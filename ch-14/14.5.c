/* 
 * 14.5.c -- Write a program that fits the following recipe:
 *
 * 	a. Externally define a name structure template with two
 * 	   members: a string to hold the first name and a string
 * 	   to hold the second name.
 *	b. Externally define a student structure template with
 *	   three members: a name structure, a grade array to hold
 * 	   three floating-point scores, and a variable to hold the
 * 	   average of those three scores.
 * 	c. Have the main() function declare an array of CSIZE
 * 	   (with CSIZE = 4 ) student structures and initialize the
 * 	   name portions to names of your choice. Use functions to
 * 	   perform the tasks described in parts d., e., f., and g.
 * 	d. Interactively acquire scores for each student by prompting
 * 	   the user with a student name and a request for scores.
 * 	   Place the scores in the grade array portion of the
 * 	   appropriate structure. The required looping can be
 * 	   done in main() or in the function, as you prefer.
 * 	e. Calculate the average score value for each structure and
 * 	   assign it to the proper member.
 *	f. Print the information in each structure.
 * 	g. Print the class average for each of the numeric structure
 *	   members.
 */

#include <stdio.h>
#define CSIZE 4
#define SCORES 3

struct name {
	char first[20];
	char last[20];
};

struct student {
	struct name person;
	float grade[SCORES];
	float average;
};

void eat_line(void);
void get_float(float *);
void get_scores(struct student s[], int n);
void student_avg_score(struct student s[], int n, int m);
void class_avg_score(const struct student s[], int n, int m); 
void print_info(const struct student s[], int n);

int main(void)
{
	/*
	 * I couldn't initialize names directly: { "John", Dou" }
	 * due to the gcc bug -- 'missing braces around initializer'
	 */
	struct student class[CSIZE] = {
		[0].person = { "John", "Dou" },
		[1].person = { "Maria", "Lopez" },
		[2].person = { "Dug", "Bright" },
		[3].person = { "Liza", "Moreno" }
	};

	get_scores(class, CSIZE);
	student_avg_score(class, CSIZE, SCORES);
	print_info(class, CSIZE);
	class_avg_score(class, CSIZE, SCORES);

	return 0;
}

void print_info(const struct student s[], int n)
{
	printf("%-15s %-6s %-6s %-6s %-7s\n",
		"NAME", "SCORE1", "SCORE2", "SCORE3", "AVERAGE");
	puts("=============== ====== ====== ====== =======");
	for (int i = 0; i < n; i++) {
		printf("%s %s	%6g %6g %6g %7.2f\n",
			s[i].person.first, s[i].person.last, s[i].grade[0],
			s[i].grade[1], s[i].grade[2], s[i].average);
	}
	puts("=============== ====== ====== ====== =======");
}

void student_avg_score(struct student s[], int n, int m)
{
	float sum = 0.0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			sum += s[i].grade[j];
		s[i].average = sum / (float) m;
		sum = 0;
	}
}

void class_avg_score(const struct student s[], int n, int m)
{
	float score1_avg = 0.0;
	float score2_avg = 0.0;
	float score3_avg = 0.0;
	float class_avg;

	for (int j = 0; j < n; j++) {
		score1_avg += s[j].grade[0];
		score2_avg += s[j].grade[1];
		score3_avg += s[j].grade[2];
	}
	score1_avg = score1_avg / (float) n, 
	score2_avg = score2_avg / (float) n, 
	score3_avg = score3_avg / (float) n, 
	class_avg = (score1_avg + score2_avg + score3_avg) / (float) m;

	printf("%-15s %6.2f %6.2f %6.2f %7.2f\n\n", "CLASS AVERAGE",
		score1_avg, score2_avg, score3_avg, class_avg);
}

void get_scores(struct student s[], int n)
{
	for (int i = 0; i < n; i++) {
		printf("Enter scores for %s %s:\n",
			s[i].person.first, s[i].person.last);
		for (int j = 0; j < 3; j++) {
			printf("Score %d: ", j + 1);
			get_float(&s[i].grade[j]);
		}
		putchar('\n');
	}
}

void eat_line(void)
{
	while (getchar() != '\n')
		continue;
}

void get_float(float *n)
{
	while (scanf("%f", n) != 1) {
		eat_line();
		printf("Invalid input. Try again: ");
		continue;
	}
	eat_line();
}
