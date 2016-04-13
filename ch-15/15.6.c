/*
 * 15.6.c -- Design a bit-field structure that holds the following information: 
 *
 *	Font ID: A number in the range 0–255 
 *	Font Size: A number in the range 0–127 
 *	Alignment: A number in the range 0–2 represented the choices Left,
 *	Center, and Right 
 *	Bold: Off (0) or on (1) 
 *	Italic: Off (0) or on (1) 
 *	Underline: Off (0) or on (1) 
 *
 * Use this structure in a program that displays the font parameters and uses a
 * looped menu to let the user change parameters. For example, a sample run
 * might look like this: 
 *
 *	ID SIZE ALIGNMENT   B   I   U
 *	1   12   left     off off off
 *	f)change font    s)change size    a)change alignment
 *	b)toggle bold    i)toggle italic  u)toggle underline
 *	q)quit
 *	s
 *	Enter font size (0-127):  
 *	36
 *	ID SIZE ALIGNMENT   B   I   U
 *	1   36   left     off off off
 *	f)change font    s)change size    a)change alignment
 *	b)toggle bold    i)toggle italic  u)toggle
 *	underline
 *	q)quit
 *	a
 *	Select alignment:
 *	l)left   c)center   r)right
 *	r
 *	ID SIZE ALIGNMENT   B   I   U
 *	1   36  right     off off off
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* alignment constants */
#define LEFT	0
#define CENTER	1
#define RIGHT	2

struct font_properties {
	unsigned int font_id	: 8;
	unsigned int font_size	: 7;
	unsigned int		: 1;
	unsigned int alignment	: 2;
	bool bold		: 1;
	bool italic		: 1;
	bool underline		: 1;
	unsigned int		: 11;
};

void show_font_settings(const struct font_properties *);
void show_menu(void);
char get_letter(const char *);
void clean_line(void);
void apply_choice(struct font_properties *, char);
int get_number(void);
void change_font(struct font_properties *);
void change_font_size(struct font_properties *);
void change_alignment(struct font_properties *);
void toggle_bold(struct font_properties *);
void toggle_italic(struct font_properties *);
void toggle_underline(struct font_properties *);

int main(void)
{
	struct font_properties font = { 1, 12, 0, 0, 0, 0 }; 
	const char *options = "fsabiuq";
	char choice;

	show_font_settings(&font);
	show_menu();
	choice = get_letter(options);
	while (choice != 'q') {
		apply_choice(&font, choice);
		show_font_settings(&font);
		show_menu();
		choice = get_letter(options);
	}

	return 0;
}

void show_font_settings(const struct font_properties *f)
{
	printf("\tID SIZE ALIGNMENT   B   I   U\n");
	printf("\t%-2u  %-3u ", f->font_id, f->font_size);
	switch (f->alignment) {
		case LEFT:
			printf("left      ");
			break;
		case CENTER:
			printf("center    ");
			break;
		case RIGHT:
			printf("right     ");
			break;
		default:
			printf("unknown   ");
	}
	printf("%-3s ", f->bold ? "on" : "off");
	printf("%-3s ", f->italic ? "on" : "off");
	printf("%-3s\n", f->underline ? "on" : "off");
}

void show_menu(void)
{
	printf("\tf) change font    s) change size    a) change alignment\n"
	       "\tb) toggle bold    i) toggle italic  u) toggle underline\n"
	       "\tq) quit\n");
}

char get_letter(const char *o)
{
	char choice;

	while (1) {
		printf("Enter a letter of your choice: _\b");
		choice = getchar();
		clean_line();
		if (strchr(o, choice))
			break;
		else
			printf("Invalid input.\n");
	}

	return choice;
}

void clean_line(void)
{
	while (getchar() != '\n')
		continue;
}

void apply_choice(struct font_properties *f, char c)
{
	switch (c) {
		case 'f':
			change_font(f);
			break;
		case 's':
			change_font_size(f);
			break;
		case 'a':
			change_alignment(f);
			break;
		case 'b':
			toggle_bold(f);
			break;
		case 'i':
			toggle_italic(f);
			break;
		case 'u':
			toggle_underline(f);
			break;
		default:
			puts("Switch error!");
	}
}

int get_number(void)
{
	int number;

	while (1) {
	       	if (scanf("%d", &number) == 1) {
			clean_line();
			break;
		}
		printf("Invalid input! It must be a number: _\b");
		clean_line();
	}

	return number;
}

void change_font(struct font_properties *f)
{
	int new_font_id;

	printf("Enter id: _\b");
	new_font_id = get_number();
	while (new_font_id < 0 || new_font_id > 255) {
		printf("Invalid input. Enter a number from 0-255: _\b");
		new_font_id = get_number();
	}
	f->font_id = new_font_id;
}

void change_font_size(struct font_properties *f)
{
	int new_font_size;
	printf("Enter a font size: _\b");
	new_font_size = get_number();
	while (new_font_size < 0 || new_font_size > 127) {
		printf("Invalid input. Enter a number from 0-127: _\b");
		new_font_size = get_number();
	}
	f->font_size = new_font_size;
}

void change_alignment(struct font_properties *f)
{
	char choice;

	printf("Select alignment:\n");
	printf("l) left   c) center   r) right\n");
	choice = get_letter("lcr");
	switch (choice) {
		case 'l':
			f->alignment = LEFT;
			break;
		case 'c':
			f->alignment = CENTER;
			break;
		case 'r':
			f->alignment = RIGHT;
			break;
		default:
			printf("Switch error!\n");
	}
}

void toggle_bold(struct font_properties *f)
{
	if (f->bold)
		f->bold = 0;
	else
		f->bold = 1;
}

void toggle_italic(struct font_properties *f)
{
	if (f->italic)
		f->italic = 0;
	else
		f->italic = 1;
}

void toggle_underline(struct font_properties *f)
{
	if (f->underline)
		f->underline = 0;
	else
		f->underline = 1;
}
