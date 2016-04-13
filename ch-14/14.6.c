/* 14.6.c -- A text file holds information about a softball team.
 * Each line has data arranged as follows:
 *
 * 	4 Jessie Joybat 5 2 1 1
 *
 * The first item is the player’s number, conveniently in the
 * range 0–18. The second item is the player’s first name, and
 * the third is the player’s last name. Each name is a single word.
 * The next item is the player’s official times at bat, followed by
 * the number of hits, walks,and runs batted in (RBIs). The file
 * may contain data for more than one game, so the same player may
 * have more than one line of data, and there may be data for other
 * players between those lines. Write a program that stores the
 * data into an array of structures. The structure should have
 * members to represent the first and last names, the at bats,
 * hits, walks, and RBIs (runs batted in), and the batting average
 * (to be calculated later). You can use the player number as an
 * array index. The program should read to end-of-file, and it
 * should keep cumulative totals for each player.
 * The world of baseball statistics is an involved one. For
 * example, a walk or reaching base on an error doesn’t count as an
 * at-bat but could possibly produce an RBI. But all this program
 * has to do is read and process the data file, as described next,
 * without worrying about how realistic the data is.
 * The simplest way for the program to proceed is to initialize the
 * structure contents to zeros, read the file data into temporary
 * variables, and then add them to the contents of the corresponding
 * structure. After the program has finished reading the file, it
 * should then calculate the batting average for each player and
 * store it in the corresponding structure member. The batting
 * average is calculated by dividing the cumulative number of hits
 * for a player by the cumulative number of at-bats; it should be a
 * floating-point calculation. The program should then display the
 * cumulative data for each player along with a line showing the
 * combined statistics for the entire team.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 18
#define LEN 20

struct player {
	char fname[LEN];
	char lname[LEN];
	int bats;
	int hits;
	int walks;
	int rbis;
	float avg;
};

void print(const struct player p[], int n);

int main(void)
{
	FILE *fp;
	struct player team[MAX];
	struct player tmp;
	int index;
	float bat_avg = 0.0;
	float hit_avg = 0.0;
	float walk_avg = 0.0;
	float rbi_avg = 0.0;
	float team_avg = 0.0;

	for ( int i = 0; i < MAX; i++) {
		strcpy(team[i].fname, "");
		strcpy(team[i].lname, "");
		team[i].bats = 0;
		team[i].hits = 0;
		team[i].walks = 0;
		team[i].rbis = 0;
		team[i].avg = 0.0;
	}
	
	if ((fp = fopen("file", "r")) == NULL) {
		fputs("Can't open file\n", stderr);
		exit(EXIT_FAILURE);
	}

	while (fscanf(fp, "%d %s %s %d %d %d %d", &index, tmp.fname,
				tmp.lname, &tmp.bats, &tmp.hits, &tmp.walks,
				&tmp.rbis) == 7) {
		--index;
		if (strcmp(team[index].fname, tmp.fname) != 0) {
			strcpy(team[index].fname, tmp.fname);
			strcpy(team[index].lname, tmp.lname);
		}
		team[index].bats += tmp.bats;
		team[index].hits += tmp.hits;
		team[index].walks += tmp.walks;
		team[index].rbis += tmp.rbis;
	}

	for (int i = 0; i < MAX; i++) {
		team[i].avg = (float) team[i].hits / (float) team[i].bats;
		team_avg += team[i].avg;
		bat_avg += team[i].bats;
		hit_avg += team[i].hits;
		walk_avg += team[i].walks;
		rbi_avg += team[i].rbis;
	}
	
	bat_avg = bat_avg / (float) MAX;
	hit_avg = hit_avg / (float) MAX;
	walk_avg = walk_avg / (float) MAX;
	rbi_avg = rbi_avg / (float) MAX;
	team_avg = team_avg / (float) MAX;

	print(team, MAX);
	printf(" %-24s %.2f %6.2f %6.2f %6.2f %9.2f\n\n", "TEAM AVERAGE",
			bat_avg, hit_avg, walk_avg,rbi_avg, team_avg);

	if (fclose(fp) != 0) {
		fputs("Can't close file!\n", stderr);
		exit(EXIT_FAILURE);
	}

	return 0;
}

void print(const struct player p[], int n)
{
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
			"~~~~~~~~~\n");
	printf(" %-24s  BAT    HIT    WAL    RBI    BAT_AVG\n", "NAME");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
			"~~~~~~~~~\n");
	for (int i = 0; i < n; i++)
		printf(" %s %-12s\t%6d %6d %6d %6d %10.2f\n",
			p[i].fname, p[i].lname, p[i].bats,
			p[i].hits, p[i].walks, p[i].rbis, p[i].avg); 
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
			"~~~~~~~~~\n");
}
