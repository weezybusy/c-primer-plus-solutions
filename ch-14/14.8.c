/*
 * 14.8.c -- The Colossus Airlines fleet consists of one plane with a seating
 * capacity of 12. It makes one flight daily. Write a seating reservation
 * program with the following features:
 *
 *	a. The program uses an array of 12 structures. Each structure should
 *	   hold a seat identification number, a marker that indicates whether
 *	   the seat is assigned, the last name of the seat holder, and the
 *	   first name of the seat holder.
 *
 *	b. The program displays the following menu:
 * 		To choose a function, enter its letter label:
 *		a) Show number of empty seats
 *		b) Show list of empty seats
 *		c) Show alphabetical list of seats
 *		d) Assign a customer to a seat assignment
 *		e) Delete a seat assignment
 *		f) Quit
 *
 *	c. The program successfully executes the promises of its menu. Choices
 *	   d) and e) require additional input, and each should enable the user
 *	   to abort an entry.
 *	
 *	d. After executing a particular function, the program shows the menu
 *	   again, except for choice f).
 *
 *	e. Data is saved in a file between runs. When the program is restarted,
 *	   it first loads in the data, if any, from the file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 30
#define SEATS 12
#define NAME 30

struct seat {
	int index;
	char status;
	char fname[SIZE];
	char lname[SIZE];
	bool delete;
};

void menu(void);
void get_choice(char *c);
void clean(void);
char *sgets(char *s);
void show_empty_seats(const struct seat s[]);
int list_empty_seats(const struct seat s[]);
void list_ocupied_seats_alpha(const struct seat s[]);
void assign_seat(struct seat s[]);
void delete_asignment(struct seat s[]);
void get_name(char *s);
void invalid_input(void);

int main(void)
{
	struct seat plane[SEATS];
	struct seat tmp;
	FILE *seats_ptr;
	int count = 0;
	long size = sizeof(struct seat);
	char choice;
	char confirmation;
	int assignment_on = 0;
	int assignment_off = 0;

	for (int seat = 0; seat < SEATS; seat++) {
		plane[seat].index = seat + 1;
		plane[seat].status ='f';
		plane[seat].delete = false;
	}

	if ((seats_ptr = fopen("seats.dat", "r")) == NULL) {
		fputs(" Can't open \"seats.dat\" file!", stderr);
		exit(EXIT_FAILURE);
	}

	while (count < SEATS && fread(&tmp, size, 1, seats_ptr) == 1) {
		if (count == 0) {
			puts("\n Current assignments");
			puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			printf(" %4s  %-20s%-20s\n", "SEAT", "FNAME", "LNAME");
			puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		} 
		printf(" %4d  %-20s%-20s\n", tmp.index,
				tmp.fname,
				tmp.lname); 
		plane[tmp.index - 1] = tmp;
		count++;
	}

	if (fclose(seats_ptr) != 0) {
		fputs(" Can't close file!\n", stderr);
		exit(EXIT_FAILURE);
	}

	puts("\n To choose a function, enter its letter label:");
	menu();
	get_choice(&choice);
	while (choice != 'f') {
		switch (choice) {
			case 'a':
				show_empty_seats(plane);
				break;
			case 'b':
				list_empty_seats(plane);
				break;
			case 'c':
				list_ocupied_seats_alpha(plane);
				break;
			case 'd':
				assign_seat(plane);
				assignment_on++;
				break;
			case 'e':
				delete_asignment(plane);
				assignment_off++;
				break;
		}
		menu();
		get_choice(&choice);
	}

	if (assignment_on > 0 || assignment_off > 0) {
		printf(" Do you want to write changes? <y/n>: _\b");
		confirmation = getchar();
		clean();
		while (confirmation != 'y' && confirmation != 'n') {
			fputs(" Invalid input!\n", stderr);
			printf(" Choose y for yes or n for no: _\b");
			confirmation = getchar();
			clean();
		}

		if (confirmation == 'y') {
			if ((seats_ptr = fopen("seats.dat", "w")) == NULL) {
				fputs(" Can't open file!\n", stderr);
				exit(EXIT_FAILURE);
			}

			rewind(seats_ptr);

			for (int seat = 0; seat < SEATS; seat++)
				if (plane[seat].status == 'a' &&
						plane[seat].delete == false)
					fwrite(&plane[seat], size, 1, seats_ptr);

			if (fclose(seats_ptr) != 0) {
				fputs(" Can't close file!\n", stderr);
				exit(EXIT_FAILURE);
			}
		}
	}

	putchar('\n');

	return 0;
}

void menu(void)
{
	puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	puts(" a) Show number of empty seats");
	puts(" b) Show list of empty seats");
	puts(" c) Show alphabetical list of seats");
	puts(" d) Assign a customer to a seat assignment");
	puts(" e) Delete a seat assignment");
	puts(" f) Quit");
	puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	putchar('\n');
	printf(" Your choice: _\b");
}

void get_choice(char *c)
{
	while ((*c = getchar()) != 1 && *c < 'a' && *c > 'f') {
		invalid_input();
		menu();
		clean();
	}
	clean();
}

void clean(void)
{
	while (getchar() != '\n')
		continue;
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
			while (getchar() != '\n')
				continue;
	}

	return value;
}

void show_empty_seats(const struct seat s[])
{
	int empty_seats = 0;

	for (int i = 0; i < SEATS; i++)
		if (s[i].status == 'f')
			empty_seats++;

	if (empty_seats > 0)
		printf("\n NUMBER OF EMPTY SEATS: %d\n\n", empty_seats);
	else
		printf("\n Sorry, but there are no empty seats.\n");
}

int list_empty_seats(const struct seat s[])
{
	int empty_seats = 0;

	puts("\n LIST OF EMPTY SEATS:");
	for (int i = 0; i < SEATS; i++) {
		if (s[i].status == 'f') {
			printf(" %2d ", s[i].index);
			empty_seats++;
		}
	}

	if (empty_seats == 0)
		puts(" There's no empty seats for now.\n\n");
	else
		printf("\n\n");
	
	return empty_seats;
}

void list_ocupied_seats_alpha(const struct seat s[])
{
	struct seat copy[SEATS];
	struct seat tmp;
	int occupied_seats = 0;

	for (int i = 0; i < SEATS; i++)
		copy[i] = s[i];

	for (int i = 0; i < SEATS - 1; i++) {
		if (copy[i].status == 'a')
			occupied_seats++;
			for (int j = i + 1; j < SEATS; j++)
				if (copy[j].status == 'a')
					if (strcmp(copy[j].fname,
						copy[i].fname) < 0) {
						tmp = copy[i];
						copy[i] = copy[j];
						copy[j] = tmp;
					}
	}

	if (occupied_seats > 0) {
		puts("\n Occupied seats");
		puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		printf(" %4s  %-20s %-20s\n", "SEAT", "FNAME", "LNAME");
		puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		for (int i = 0; i < SEATS; i++)
			if (copy[i].status == 'a')
				printf(" %4d  %-20s %-20s\n", copy[i].index,
						copy[i].fname, copy[i].lname);
		putchar('\n');
	} else
		puts(" All seats are free.\n");
}

void assign_seat(struct seat s[])
{
	int empty_seats;
	int seat;

	empty_seats = list_empty_seats(s);
	if (empty_seats > 0) {
		printf(" Choose a seat: _\b");
		while ((scanf("%d", &seat) != 1 && seat < 1 && seat > 12) ||
				s[seat - 1].status != 'f') {
			if (s[seat - 1].status != 'f') {
				fputs(" This seat is already occupied.\n",
						stderr);
				printf(" Try another one from the list:\n");
				list_empty_seats(s);
				printf(" Your choice: _\b");
			} else {
				clean();
				invalid_input();
			}
		}
		clean();

		printf(" Enter your first name: _\b");
		get_name(s[seat - 1].fname);
		printf(" Enter your last name: _\b");
		get_name(s[seat - 1].lname);

		printf(" %s %s: seat #%d\n\n", s[seat - 1].fname,
				s[seat - 1].lname, seat);

		s[seat - 1].status = 'a';
	}
}

void delete_asignment(struct seat s[])
{
	char fname[NAME];
	char lname[NAME];
	int seat;
	
	printf(" Enter your first name: _\b");
	get_name(fname);
	printf(" Enter your last name: _\b");
	get_name(lname);
	printf(" Number of your seat: _\b");
	while (scanf("%d", &seat) != 1 && seat < 1 && seat > 12 &&
					s[seat - 1].status == 'f')
		invalid_input();
	clean();
	putchar('\n');

	if (strcmp(fname, s[seat - 1].fname) != 0 &&
			strcmp(lname, s[seat - 1].lname) != 0)
		printf(" Sorry, information doesn't match.\n");
	else
		s[seat - 1].delete = true;
}

void get_name(char *s)
{
	while (sgets(s) == NULL || s[0] == '\0')
		invalid_input();
}

void invalid_input(void)
{
	fputs(" Invalid input!\n", stderr);
	printf(" Try again: _\b");
}
