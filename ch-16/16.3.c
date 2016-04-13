/*
 * 16.3.c -- Polar coordinates describe a vector in terms of magnitude and the
 * counterclockwise angle from the x-axis to the vector. Rectangular coordinates
 * describe the same vector in terms of x and y components (see  Figure  16.3).
 * Write a program that reads the magnitude and angle (in degrees) of a vector
 * and then displays the x and y components. The relevant equations are these: 
 *
 * 	 x = r cos A y = r sin A
 *
 * To do the conversion, use a function that takes a structure containing the
 * polar coordinates and returns a structure containing the rectangular
 * coordinates (or use pointers to such structures, if you prefer).
 */

#include <stdio.h>
#include <math.h>
#define PI (4 * atan(1))
#define DEG_TO_RAD (PI / 180)

typedef struct {
	double magnitude;
	double angle_degrees;
} Polar;

typedef struct {
	double x;
	double y;
} Rectangular;

Rectangular polar_to_rect(Polar);

int main(void)
{
	Polar p;
	Rectangular r;

	puts("Enter magnitude and angle values:");
	while (scanf("%lf %lf", &p.magnitude, &p.angle_degrees) != 2) {
		while (getchar() != '\n')
			continue;
		printf("Enter magnitude and angle: _\b");
	}

	r = polar_to_rect(p);

	printf("x: %g\ny: %g\n", r.x, r.y);

	return 0;
}

Rectangular polar_to_rect(Polar p)
{
	Rectangular r;
	double angle_radians = p.angle_degrees * DEG_TO_RAD;

	r.x = p.magnitude * cos(angle_radians);
	r.y = p.magnitude * sin(angle_radians);

	return r;
}
