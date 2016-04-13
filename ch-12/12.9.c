/*
 * 12.9.c --
 * Write a program with the following behavior. First, it asks you
 * how many words you wish to enter. Then it asks you enter the words,
 * and then it displays the words. Use malloc() and the answer to the
 * first question (the number of words) to create a dynamic array of
 * the corresponding number of pointers-to-char. (Note that because
 * each element in the array is a pointer-to-char, the pointer used
 * to store the return value of malloc() should be a
 * pointer-to-a-pointer-to-char. When reading the string, the program
 * should read the word into a temporary array of char, use malloc()
 * to allocate enough storage to hold the word, and store the address
 * in the array of char pointers. Then it should copy the word from
 * the temporary array into the allocated storage. Thus, you wind up
 * with an array of character pointers, each pointing to an object of
 * the precise size needed to store the particular word. A sample run
 * could look like this:
 *
 * 		How many words do you wish to enter? 5
 * 		Enter 5 words now:
 * 		I enjoyed doing this exercise
 * 		Here are your words:
 * 		I
 * 		enjoyed
 * 		doing
 * 		this
 * 		exercise
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIM 30

int main(void)
{
	int words_num;
	int word_len;
	char ** words_arr;
	char ** tmp_arr;

	printf("How many words do you wish to enter? ");
	if (scanf("%d", &words_num) == 1) {
		printf("Enter %d words now:\n", words_num);

		words_arr = (char **) malloc(words_num * sizeof(char *));
		tmp_arr = (char **) malloc(words_num * sizeof(char *));

		for (int word = 0; word < words_num; word++) {
			tmp_arr[word] = (char *) malloc(LIM * sizeof(char));
			scanf("%s", tmp_arr[word]);

			word_len = 1;
			while (tmp_arr[word][word_len - 1]) {
				word_len++;
			}

			words_arr[word] = (char *) malloc(word_len * sizeof(char));
			strcpy(words_arr[word], tmp_arr[word]);
			printf("%s\n", words_arr[word]);
		}

		for (int word = 0; word < words_num; word++) {
			free(tmp_arr[word]);
			free(words_arr[word]);
		}
		free(tmp_arr);
		free(words_arr);
	}

	return 0;
}
