/*
 * 11.11.c --
 * Write a program that reads in up to 10 strings or to EOF, whichever
 * comes first. Have it offer the user a menu with five choices: print
 * the original list of strings, print the strings in ASCII collating
 * sequence, print the strings in order of increasing length, print the
 * strings in order of the length of the first word in the string, and
 * quit. Have the menu recycle until the user enters the quit request.
 * The program, of course, should actually perform the promised tasks.
 */

#include <stdio.h>
#include <string.h>
#define LIM 10
#define SLEN 16

char *fget(char *s, int n);
void prnt_str(char *s[], int m);
void ascii_seq(char *s[], int n);
void word_len(char *s[], int n);

int main(void)
{
	char str_arr[LIM][SLEN];
	char *pt_str[LIM];
	int count = 0;
	char ch;

	puts("Enter 5 strings or press ctrl+d tp quit.");
	for (int i = 0; i < LIM; i++)
	{
		printf("Enter string #%d:\n", i+1);
		if (fget(str_arr[i], SLEN-1))
		{
			pt_str[count] = str_arr[count];
			count++;
		}
		else
			break;
	}

	if (count > 0)
	{
		puts("Choose what you want me to do:");
		puts("a) Print the original list of strings.");
		puts("b) Print strings in ASCII collating sequence.");
		puts("c) Print the strings in order of the length of the first word in the string.");
		puts("q) To quit.");

		ch = getchar();
		while ((ch < 'a' || ch > 'c') && ch != 'q')
		{
			puts("Please respond with a, b, c, or q:");
			ch = getchar();
		}

		switch(ch)
		{
			case 'a':
				prnt_str(pt_str, count);
				break;
			case 'b':
				ascii_seq(pt_str, count);
				break;
			case 'c':
				word_len(pt_str, count);
				break;
			case 'q':
				puts("Bye!");
				break;
			default:
				puts("Invalid input!");
				break;
		}
	}
	return 0;
}

char *fget(char *s, int n)
{
	char *ret_val;
	char *check;

	ret_val = fgets(s, n, stdin);
	if (ret_val)
	{
		check = strchr(s, '\n');
		if (check)
			*check = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

void prnt_str(char *s[], int n)
{
	for (int i = 0; i < n; i++)
		puts(s[i]);
}

void ascii_seq(char *s[], int n)
{
	char *tmp;

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if ((strcmp(s[i], s[j])) > 0)
			{
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}

	prnt_str(s, n);
}

void word_len(char *s[], int n)
{
	int prev, curr;
	char *tmp;

	for (int i = 0; i < n - 1; i++)
	{
		prev = 0;
		while (s[i][prev] != ' ' && s[i][prev] != '\0')
			prev++;
		for (int j = i + 1; j < n; j++)
		{
			curr = 0;
			while (s[j][curr] != ' ' && s[j][curr] != '\0')
				curr++;
			if (prev < curr)
			{
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
				prev = curr;
			}
		}
	}
	prnt_str(s, n);
}
