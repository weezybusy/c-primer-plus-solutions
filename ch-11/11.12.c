/*
 * 11.12.c --
 * Write a program that reads input up to EOF and reports the number
 * of words, the number of uppercase letters, the number of lowercase
 * letters, the number of punctuation characters, and the number of
 * digits. Use the ctype.h family of functions.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIM 80

char *fget(char *s, int n);
void count_ch(char *s);

int main(void)
{
	char str[LIM];
	char *val;

	val = fget(str, LIM);
	while (val && str[0] != '\0')
	{
		count_ch(str);
		val = fget(str, LIM);
	}

	return 0;
}

char *fget(char *s, int n)
{
	char *ret_val;
	char *end_ch;

	ret_val = fgets(s, n, stdin);
	if (ret_val)
	{
		end_ch = strchr(s, '\n');
		if (end_ch)
			*end_ch = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

void count_ch(char *s)
{
	int len = strlen(s);
	int words = 0;
	int upper_letters = 0;
	int lower_letters = 0;
	int puncts = 0;
	int digits = 0;

	for (int i = 0; i < len; i++)
	{
		if (isupper(s[i]))
			upper_letters++;
		if (islower(s[i]))
			lower_letters++;
		if (ispunct(s[i]))
			puncts++;
		if (isdigit(s[i]))
			digits++;
		if ((s[i] == ' ' && isalnum(s[i+1])) || s[i+1] == '\0')
			words++;
	}

	printf("Words = %d\n", words);
	printf("Uppercase letters = %d\n", upper_letters);
	printf("Lowercase letters = %d\n", lower_letters);
	printf("Punctuation characters = %d\n", puncts);
	printf("Digits = %d\n", digits);
}
