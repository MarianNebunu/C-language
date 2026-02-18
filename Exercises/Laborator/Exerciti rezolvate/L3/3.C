#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
	unsigned ug;
	double ur;

	clrscr();

	printf("Unghiul in grade: "); scanf("%u", &ug);

	ur=((double)ug*M_PI)/180;

	printf("Unghiul in radieni: %lf", ur);

	getch();
	return 0;
}