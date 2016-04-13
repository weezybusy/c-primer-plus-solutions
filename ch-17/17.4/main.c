/*
 * 17.4.c -- Rewrite mall.c (Listing 17.7) so that it simulates a double booth
 * having two queues.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#define MIN_PER_HR 60.0

bool new_customer(double x);
bool line(void);
Item customer_time(long when);
void show_results(const long *, const long *, const long *, const double *,
	          const double *);
void add_customer(const int, long *, const long, Queue []);

int main(void)
{
	Queue	lines[2];
	Item	tmp;
	int	hours;
	int	per_hour;
	long	turnaways = 0;
	long	customers = 0;
	long	served = 0;
	long	sum_line[2] = { 0, 0 };
	int	wait_time[2] = { 0, 0 };
	long	line_wait[2] = { 0, 0 };

	InitializeQueue(&lines[0]);
	InitializeQueue(&lines[1]);

	srand(time(NULL));

	printf("Enter the number of simulation hours: ");
	scanf("%d", &hours);
	long cycle_limit = MIN_PER_HR * hours;

	printf("Enter the average number of customers per hour: ");
	scanf("%d", &per_hour);
	double min_per_cust = MIN_PER_HR / per_hour;

	for (long cycle = 0; cycle < cycle_limit; cycle++)
	{
		if (new_customer(min_per_cust))
		{
			bool q1_is_full = QueueIsFull(&lines[0]);
			bool q2_is_full = QueueIsFull(&lines[1]);

			if (!q1_is_full && !q2_is_full)
				add_customer(line(), &customers, cycle, lines);
			else if (q1_is_full && !q2_is_full)
				add_customer(1, &customers, cycle, lines);
			else if (q2_is_full && !q1_is_full)
				add_customer(0, &customers, cycle, lines);
			else
				turnaways++;
		}

		if (wait_time[0] <= 0 && !QueueIsEmpty(&lines[0]))
		{
			DeQueue (&tmp, &lines[0]);
			wait_time[0] = tmp.process_time;
			line_wait[0] += cycle - tmp.arrive;
			served++;
		}
		else (wait_time[0] > 0)
			wait_time[0]--;
		sum_line[0] += QueueItemCount(&lines[0]);

		if (wait_time[1] <= 0 && !QueueIsEmpty(&lines[1]))
		{
			DeQueue (&tmp, &lines[1]);
			wait_time[1] = tmp.process_time;
			line_wait[1] += cycle - tmp.arrive;
			served++;
		}
		else (wait_time[1] > 0)
			wait_time[1]--;
		sum_line[1] += QueueItemCount(&lines[1]);
	}

	if (customers > 0)
	{
		double avg_q_size =
			(double) (sum_line[0] + sum_line[1]) / cycle_limit;
		double avg_wait_time =
			(double) (line_wait[0] + line_wait[1]) / served;

		show_results(&customers, &served, &turnaways, &avg_q_size,
			     &avg_wait_time);
	}
	else
	{
		puts("\nNo customers!");
	}

	EmptyTheQueue(&lines[0]);
	EmptyTheQueue(&lines[1]);

	return 0;
}

bool new_customer(double x)
{
	if (rand() * x / RAND_MAX < 1)
		return true;
	else
		return false;
}

bool which_line(void)
{
	return rand() % 2;
}

Item customer_time(long when)
{
	Item cust;

	cust.process_time = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}

void show_results(const long *customers, const long *served,
		  const long *turnaways, const double *avg_q_size,
		  const double *avg_wait_time)
{
		printf("\ncustomers accepted: %ld\n", *customers);
		printf("  customers served: %ld\n", *served);
		printf("         turnaways: %ld\n", *turnaways);
		printf("average queue size: %.2f\n", *avg_q_size);
		printf(" average wait time: %.2f min\n\n", *avg_wait_time);
}

void add_customer(const int line, long *customers, const long cycle,
		  Queue lines[])
{
	*customers += 1;
	Item tmp = customer_time(cycle);
	EnQueue(tmp, &lines[line]);
}
