#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
	int a, b, c, d;
	float sd, x1, x2;

	clrscr();

	printf("a="); scanf("%d", &a);
	printf("b="); scanf("%d", &b);
	printf("c="); scanf("%d", &c);
	
	printf("Ecuatia este: %dx^2", a);
	if (b>=0) printf("+%dx", b);
	else printf("%dx", b);
	if (c>=0) printf("+%d", c);
	else printf("%d", c);
	printf("=0\n\r");

	d=pow(b, 2)-4*a*c;
	if (d>=0)
	{
		sd=(float)pow((double)d, 0.5);
		x1=(-((float)b)+sd)/(2*(float)a);
		x2=(-((float)b)-sd)/(2*(float)a);

		if (!d) printf("Solutia unica este:\n\rx=%f", x1);
		else printf("Solutiile sunt:\n\rx1=%f\n\rx2=%f", x1, x2);
	}
	else printf("Nu exista solutii in R");

	getch();
	return 0;
}