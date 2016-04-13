/*
 * 14.9.c -- Colossus Airlines (from exercise 8) acquires a second plane (same
 * capacity) and expands its service to four flights daily (Flights 102, 311,
 * 444, and 519). Expand the program to handle four flights. Have a top-level
 * menu that offers a choice of flights and the option to quit. Selecting a
 * particular flight should then bring up a menu similar to that of exercise 8.
 * However, one new item should be added: confirming a seat assignment. Also,
 * the quit choice should be replaced with the choice of exiting to the
 * top-level menu. Each display should indicate which flight is currently being
 * handled. Also, the seat assignment display should indicate the confirmation
 * status.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define NAME 30
#define SEATS 12
#define FLIGHTS 4
#define EMPTY 'y'
#define TAKEN 'n'
#define UNCONFIRMED 'n'
#define CONFIRMED 'y'
#define EXIT_TO_MAIN_MENU 'g'
#define EXIT 'e'
#define HEADER

struct seat {
	int seat_number;
	char fname[NAME];
	char lname[NAME];
	char status;
	char confirmation;
};

struct plane {
	int flight_number;
	struct seat seat_info[SEATS];
};

char *sgets(char *);
void invalid_input(void);
void clean(void);
void get_name(char *);
int get_number(void);
char get_letter(char *);
void flight_options_menu(void);
void action_menu(void);
void empty_seats_number(const struct plane *);
void empty_seats_list(const struct plane *);
void alphabetical_seats_list(const struct plane *);
void assign_seat(struct plane *);
void confirm_assignment(struct plane *);
void delete_assignment(struct plane *);
void print(const struct seat, int);

int main(void)
{
	struct plane flights[FLIGHTS];
	struct plane *flight_ptr;
	FILE *colossus_airlines;
	const int flight_numbers[FLIGHTS] = { 102, 311, 444, 519 };
	long size = sizeof(struct plane);
	int flight_number;
	char action;
	int read = 0;
	char choice;

	for (int i = 0; i < FLIGHTS; i++) {
		flights[i].flight_number = flight_numbers[i];
		for (int j = 0; j < SEATS; j++) {
			flights[i].seat_info[j].seat_number = j + 1;
			flights[i].seat_info[j].status = EMPTY;
			flights[i].seat_info[j].confirmation = UNCONFIRMED;
		}
	}

	if ((colossus_airlines = fopen("colossus_airlines.dat", "r")) != NULL) {
		for (int i = 0; i < FLIGHTS; i++) {
			fread(&flights[i], size, 1, colossus_airlines);
			for (int j = 0; j < SEATS; j++)
				if (flights[i].seat_info[j].status == TAKEN) {
					read++;
					if (read == 1) {
						printf("\n %-6s %-4s %-12s "
							"%-12s  %-12s\n",
							"FLIGHT", "SEAT",
							"FNAME", "LNAME",
							"SEAT", "STATUS");
						puts(" ~~~~~~~~~~~~~~~~~~~~~~~~"
							"~~~~~~~~~~~~~~~~~~~~~~"
							"~~~~~~~~~~~");
					}
					print(flights[i].seat_info[j],
							flight_numbers[i]);
				}
		}
	}

	flight_options_menu();
	choice = get_letter("abcde");
	flight_number = choice - 97;
	flight_ptr = &flights[flight_number];

	while (choice != EXIT){
		action_menu();
		action = get_letter("abcdefg");
		while (action != EXIT_TO_MAIN_MENU) {
			switch (action) {
			case 'a':
				empty_seats_number(flight_ptr);
				break;
			case 'b':
				empty_seats_list(flight_ptr);
				break;
			case 'c':
				alphabetical_seats_list(flight_ptr);
				break;
			case 'd':
				assign_seat(flight_ptr);
				break;
			case 'e':
				confirm_assignment(flight_ptr);
				break;
			case 'f':
				delete_assignment(flight_ptr);
			}
			action_menu();
			action = get_letter("abcdefg");
		}
		flight_options_menu();
		choice = get_letter("abcde");
		flight_number = choice - 97;
		flight_ptr = &flights[flight_number];
	}

	if (fclose(colossus_airlines) != 0) {
		fputs(" Can't close file!\n", stderr);
		exit(EXIT_FAILURE);
	}

	if ((colossus_airlines = fopen("colossus_airlines.dat", "w")) == NULL) {
		fputs(" Error opening file!\n", stderr);
		exit(EXIT_FAILURE);
	} else {
		for (int i = 0; i < FLIGHTS; i++)
			fwrite(&flights[i], size, 1, colossus_airlines);
	}

	if (fclose(colossus_airlines) != 0) {
		fputs(" Can't close file!\n", stderr);
		exit(EXIT_FAILURE);
	}

	return 0;
}

void flight_options_menu(void)
{
	const char *options = " a) 102\n b) 311\n c) 444\n d) 519\n e) EXIT\n";

	puts("\n Please, choose a flight:");
	puts(" ~~~~~~~~~~~~~~~~~~~~~~~~");
		printf("%s\n", options);
	printf(" Your choice: _\b");
}

void print(const struct seat s, const int n)
{
	printf(" %-6d %-2d   %-12s %-12s  %s, %s\n",
			n, s.seat_number, s.fname, s.lname, "taken",
			(s.confirmation == CONFIRMED) ?
			"confirmed" : "unconfirmed");
}

void action_menu(void)
{
	const char *options = 
		"\n Choose an action:\n"
		" ~~~~~~~~~~~~~~~~~\n"
		" a) Show number of empty seats\n"
		" b) Show list of empty seats\n"
		" c) Show alphabetical list of seats\n"
		" d) Assign a customer to a seat assignment\n"
		" e) Confurm assignment\n"
		" f) Delete a seat assignment\n"
		" g) Main menu\n";

	printf(" %s\n", options);
	printf(" Your choice: _\b");
}

void empty_seats_number(const struct plane *s)
{
	int empty_seats = 0;

	for (int i = 0; i < SEATS; i++)
		if (s->seat_info[i].status == EMPTY)
			empty_seats++;

	printf("\n Number of empty seats: %d\n", empty_seats);
}

void empty_seats_list(const struct plane *s)
{
	printf("\n Available seats on a flight %d:\n", s->flight_number);
	puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	for (int i = 0; i < SEATS; i++)
		if (s->seat_info[i].status == EMPTY ||
				s->seat_info[i].confirmation == UNCONFIRMED)
			printf(" %d  ", s->seat_info[i].seat_number);
	printf("\n\n");
}

void alphabetical_seats_list(const struct plane *s)
{
	struct plane copy = *s;
	struct seat tmp;
	int taken = 0;

	for (int i = 0; i < SEATS - 1; i++)
		if (copy.seat_info[i].status == TAKEN) {
			taken++;
			for (int j = 1; j < SEATS; j++)
				if (copy.seat_info[j].status == TAKEN)
					if (strcmp(copy.seat_info[j].fname,
						       copy.seat_info[i].fname) < 0) {
						tmp = copy.seat_info[i];
						copy.seat_info[i] = copy.seat_info[j];
						copy.seat_info[j] = tmp;
					}
		}

	if (taken > 0) {
		printf("\n %-6s %-4s %-12s %-12s  %-12s\n", "FLIGHT", "SEAT",
				"FNAME", "LNAME", "SEAT", "STATUS");
		puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		for (int i = 0; i < SEATS; i++)
			if (copy.seat_info[i].status == TAKEN)
				printf(" %-6d %-2d   %-12s %-12s  %s, %s\n",
					s->flight_number,
					s->seat_info[i].seat_number,
					s->seat_info[i].fname,
					s->seat_info[i].lname,
					"taken",
					(s->seat_info[i].confirmation == CONFIRMED) ?
					"confirmed" : "unconfirmed");
	} else {
		puts("\n There are no taken seats on this flight yet.");
	}
}

void assign_seat(struct plane *s)
{
	int seat;

	printf("\n Available seats on a flight %d:\n\n", s->flight_number);
	printf("  #  %-12s\n", "STATUS");
	puts(" ~~~~~~~~~~");
	for (int i = 0; i < SEATS; i++)
		if (s->seat_info[i].confirmation == UNCONFIRMED)
			printf(" %2d  %5s, %11s\n",
					s->seat_info[i].seat_number,
					(s->seat_info[i].status = EMPTY) ? 
					"empty" : "taken",
					"unconfirmed");
	printf("\n");

	printf(" Choose: _\b");
	seat = get_number() - 1;
	while (s->seat_info[seat].status == TAKEN) {
		fputs(" This place is already taken!\n", stderr);
		printf(" Pick another one: _\b");
		seat = get_number() - 1;
	}

	printf(" Enter your first name: _\b");
	get_name(s->seat_info[seat].fname);
	printf(" Enter your second name: _\b");
	get_name(s->seat_info[seat].lname);

	s->seat_info[seat].status = TAKEN;
	printf("\n %-12s %-12s %-4s  %-12s\n", "FNAME", "LNAME", "SEAT",
			"STATUS");
	puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf(" %-12s %-12s %-4d  %s, %s\n",
			s->seat_info[seat].fname,
			s->seat_info[seat].lname,
			s->seat_info[seat].seat_number,
			"taken",
			"unconfirmed");
}

void confirm_assignment(struct plane *s)
{
	int seat;
	char fname[NAME];
	char lname[NAME];

	printf(" Please, enter number of your seat: _\b");
	seat = get_number() - 1;
	printf(" Now enter your first name: _\b");
	get_name(fname);
	printf(" And your last name: _\b");
	get_name(lname);

	if (strcmp(fname, s->seat_info[seat].fname) == 0 &&
			strcmp(lname, s->seat_info[seat].lname) == 0) {
		puts(" Now your assign confirmed.");
		s->seat_info[seat].confirmation = CONFIRMED;

		printf("\n %-12s %-12s %-4s  %-12s\n", "FNAME", "LNAME", "SEAT",
				"STATUS");
		puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		printf(" %-12s %-12s %-4d  %s, %s\n",
				s->seat_info[seat].fname,
				s->seat_info[seat].lname,
				s->seat_info[seat].seat_number,
				"taken",
				"confirmed");
	}
}

void delete_assignment(struct plane *s)
{
	int seat;
	char fname[NAME];
	char lname[NAME];

	printf(" Please, enter number of your seat: _\b");
	seat = get_number() - 1;
	printf(" Now enter your first name: _\b");
	get_name(fname);
	printf(" And your last name: _\b");
	get_name(lname);

	if (strcmp(fname, s->seat_info[seat].fname) == 0 &&
			strcmp(lname, s->seat_info[seat].lname) == 0) {
		puts(" Now your assignment is deleted.");
		s->seat_info[seat].confirmation = UNCONFIRMED;
		s->seat_info[seat].status = EMPTY;
	}

	printf("\n %-12s %-12s %-4s  %-12s\n", "FNAME", "LNAME", "SEAT",
			"STATUS");
	puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf(" %-12s %-12s %-4d  %s, %s\n",
			s->seat_info[seat].fname,
			s->seat_info[seat].lname,
			s->seat_info[seat].seat_number,
			"empty",
			"unconfirmed");
}

void get_name(char *s)
{
	while (sgets(s) == NULL || s[0] == '\0')
		invalid_input();
}

int get_number(void)
{
	int number;

	while (scanf("%d", &number) != 1 && (number < 1 || number > 12)) {
		invalid_input();
		clean();
	}
	clean();

	return number;
}

char get_letter(char *s)
{
	char choice;

	choice = getchar();
	clean();
	while (strchr(s, choice) == NULL) {
		invalid_input();
		choice = getchar();
		clean();
	}

	return choice;
}

char *sgets(char *s)
{
	char *value, *new_line;

	value = fgets(s, NAME, stdin);
	if (value) {
		new_line = strchr(s, '\n');
		if (new_line)
			*new_line = '\0';
		else
			clean();
	}

	return value;
}

void invalid_input(void)
{
	fputs(" Invalid input\n", stderr);
	printf(" Try again: _\b");
}

void clean(void)
{
	while (getchar() != '\n')
		continue;
}
