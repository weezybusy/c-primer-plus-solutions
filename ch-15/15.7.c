/*
 * 15.7.c -- Write a program with the same behavior as described in exercise 6,
 * but use an unsigned long variable to hold the font information and use the
 * bitwise operators instead of bit members to manage the information. 
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define FONT_ID_MASK	0xff
#define FONT_SIZE_MASK	0x7f00
#define LEFT		0x00000
#define CENTER		0x10000
#define RIGHT		0x20000
#define ALIGN_MASK	0x30000
#define BOLD		0x1000000
#define ITALIC		0x2000000
#define UNDERLINE	0x4000000

void set_default_settings(unsigned long *);
void show_settings(unsigned long *);
void show_menu(void);
char get_letter(char *);
void apply_choice(unsigned long *, const char);
void clean_line(void);
void change_font(unsigned long *);
int get_number(void);
void change_size(unsigned long *);
void change_alignment(unsigned long *);
void toggle_bold(unsigned long *);
void toggle_italic(unsigned long *);
void toggle_underline(unsigned long *);
char *show_binary(unsigned long, char *);

int main(void)
{
	unsigned long font = 0;
	char choice;
	char binary[CHAR_BIT * sizeof(long) + 1];

	set_default_settings(&font);
	show_settings(&font);
	show_binary(font, binary);
	show_menu();
	printf("Select letter of your choice: _\b");
	choice = get_letter("fsabiuq");
	while (choice != 'q') {
		apply_choice(&font, choice);
		show_binary(font, binary);
		show_settings(&font);
		show_menu();
		printf("Next choice: _\b");
		choice = get_letter("fsabiuq");
	}

	return 0;
}

void set_default_settings(unsigned long *f)
{
	*f |= 1;
	*f |= 12 << 8;
}

void show_settings(unsigned long *f)
{
	printf("\tID  SIZE  ALIGNMENT   B   I   U\n");
	printf("\t%-4ld", *f & FONT_ID_MASK);
	printf("%-6ld", (*f & FONT_SIZE_MASK) >> 8);
	switch (*f & ALIGN_MASK) {
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
	printf("%3s ", (*f & BOLD) >> 24 ? "on" : "off");
	printf("%3s ", (*f & ITALIC) >> 25 ? "on" : "off");
	printf("%3s\n", (*f & UNDERLINE) >> 26 ? "on" : "off");
}

void show_menu(void)
{
	printf("\tf) change font    s) change size    a) change alignment\n"
	       "\tb) toggle bold    i) toggle italic  u) toggle underline\n"
	       "\tq) quit\n");
}

char get_letter(char *o)
{
	char choice;

	while (1) {
		choice = getchar();
		clean_line();
		if (strchr(o, choice))
			break;
		printf("Invalid input!\n");
		printf("Choose f, s, a, b, i, u or q: _\b");
	}

	return choice;
}

void clean_line(void)
{
	while (getchar() != '\n')
		continue;
}

void apply_choice(unsigned long *f, const char c)
{
	switch (c) {
		case 'f':
			change_font(f);
			break;
		case 's':
			change_size(f);
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
			printf("Switch error!\n");
	}
}

void change_font(unsigned long *f)
{
	unsigned long new_font_id;

	printf("Enter a font id: _\b");
	new_font_id = get_number();
	while (new_font_id > 255) {
		printf("Invalid input!.\n");
		printf("Choose a number from 0-255: _\b");
		new_font_id = get_number();
	}

	*f &= ~FONT_ID_MASK;
	*f |= new_font_id;
}

int get_number(void)
{
	int number;
	while (scanf("%d", &number) != 1) {
		clean_line();
		printf("Invalid input.\n");
		printf("It must be an integer. Try again: _\b");
	}
	clean_line();

	return number;
}

void change_size(unsigned long *f)
{
	unsigned long font_size;

	printf("Enter a font size: _\b");
	font_size = get_number();
	while (font_size > 127) {
		printf("Invalid input.\n");
		printf("Choose a number from 0-127: _\b");
		font_size = get_number();
	}

	*f &= ~FONT_SIZE_MASK;
	*f |= font_size << 8;
}

void change_alignment(unsigned long *f)
{
	char new_alignment;

	printf("l) left    c) center    r) right\n");
	printf("Your choice: _\b");
	new_alignment = get_letter("lcr");
	switch (new_alignment) {
		case 'l':
			*f &= ~ALIGN_MASK;
			break;
		case 'c':
			*f &= ~ALIGN_MASK;
			*f |= CENTER;
			break;
		case 'r':
			*f &= ~ALIGN_MASK;
			*f |= RIGHT;
			break;
		default:
			printf("Switch error.\n");
	}
}

void toggle_bold(unsigned long *f)
{
	if (*f & BOLD)
		*f &= ~BOLD;
	else
		*f |= BOLD;
}

void toggle_italic(unsigned long *f)
{
	if (*f & ITALIC)
		*f &= ~ITALIC;
	else
		*f |= ITALIC;
}

void toggle_underline(unsigned long *f)
{
	if (*f & UNDERLINE)
		*f &= ~UNDERLINE;
	else
		*f |= UNDERLINE;
}

char *show_binary(unsigned long f, char *b)
{
	static const int size = CHAR_BIT * sizeof(long);

	for (int i = size - 1; i >= 0; i--, f >>= 1)
		b[i] = (f & 0x1) + '0';
	b[size] = '\0';

	putchar('\t');
	int j = 0;
	while (*b) {
		putchar(*(b++));
		if (++j % 4 == 0)
			putchar(' ');
	}
	putchar('\n');

	return b;
}
