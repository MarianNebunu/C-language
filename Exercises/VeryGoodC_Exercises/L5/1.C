#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
	double a, b, c, d, sd, x1, x2, x1i, x2i;

	clrscr();

	printf("a="); scanf("%lf", &a);
	printf("b="); scanf("%lf", &b);
	printf("c="); scanf("%lf", &c);
	printf("Ecuatia este: ");
	if (a) printf("%.3lfx^2", a);
	if (b>0) printf("+%.3lfx", b);
	else if (b<0) printf("%.3lfx", b);
	if (c>0) printf("+%.3lf", c);
	else
	{
		if (c<0) printf("%.3lf", c);
		else if (!a&&!b) printf("%.3lf", c);
	}
	printf("=0\n\r");
	if (!a&&!b)
	{
		if (c) printf("Ecuatia nu este valida!");
		else printf("Ecuatia este valabila pentru orice x");
		getch();
		return 0;
	}
	
	d=(pow(b, 2)-(4*a*c));
	if (d>=0)
	{
		sd=pow(d, 0.5);
		x1=(-b+sd)/(2*a);
		x2=(-b-sd)/(2*a);
		
		if (d) printf("Radacinile sunt:\n\rx1=%.3lf\n\rx2=%.3lf", x1, x2);
		else printf("Radacina unica este:\n\rx=%.3lf", x1);
	}
	else
	{
		sd=pow(-d, 0.5);
		x1=(-b)/(2*a);
		x2=(-b)/(2*a);
		x1i=sd/(2*a);
		x2i=(-sd)/(2*a);

		printf("Radacinile sunt:\n\rx1=");
		if (x1) printf("%.3lf", x1);
		if (x1i)
		{
			if (x1i>0) printf("+%.3lfi", x1i);
			else printf("%.3lfi", x1i);
		}
		printf("\n\rx2=");
		if (x2) printf("%.3lf", x2);
		if (x2i)
		{
			if (x2i>0) printf("+%.3lfi", x2i);
			else printf("%.3lfi", x2i);
		}
	}

	getch();
	return 0;
}