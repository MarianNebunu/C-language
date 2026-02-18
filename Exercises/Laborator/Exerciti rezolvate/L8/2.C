#include <stdio.h>
#include <conio.h>

typedef struct tag_CPLX {
	double rl;
	double im;
} CPLX;

int print_cplx(CPLX nr)
{
	printf("%7.3lf", nr.rl);
	if (nr.im)
	{
		if (nr.im>0) printf("+%7.3lfi", nr.im);
		else printf("%7.3lfi", nr.im);
	}
	return 1;
}

CPLX * radacini(double c1, double c2, double c3)
{
	CPLX rv[2];
	double d;
	double sd;

	d=pow(c2, 2)-4*(c1*c3);
	sd=sqrt(abs(d));

	if (d>=0)
	{
		rv[0].rl=(-c2+sd)/(2*c1);
		rv[0].im=0;
		rv[1].rl=(-c2-sd)/(2*c1);
		rv[1].im=0;
	}
	else
	{
		rv[0].rl=(-c2)/(2*c1);
		rv[0].im=sd/(2*c1);
		rv[1].rl=(-c2)/(2*c1);
		rv[1].im=(-sd)/(2*c1);
	}

	return rv;
}

int test_coef(double c1, double c2, double c3)
{
	if ((!a)&&(!b)&&(!c))
	{
		printf("Valabil pentru orice x din R!");
		return 0;
	}
	if ((!a)&&(!b)&&(c))
	{
		printf("Ecuatia nu este valida!");
		return 0;
	}
	if (!a)
	{
		printf("Ecuatie de gradul 1, x=%7.3lf", ((-c3)/c2));
		return 0;
	}
	return 1;
}

int main()
{
	double a, b, c;
	CPLX rad[2];

	clrscr();

	printf("Introduceti coeficientii:\n\r");
	printf("a="); scanf("%lf", &a);
	printf("b="); scanf("%lf", &b);
	printf("c="); scanf("%lf", &c);

	printf("\n\rEcuatia este: ");
	if (a) printf("%6.2lfx^2", a);
	if (b)
	{
		if (b>0) printf("+%6.2lfx", b);
		else printf("%6.2lfx", b);
	}
	if (c>0) printf("+%6.2lf=0\n\r\n\r", c);
	else printf("%6.2lf=0\n\r\n\r", c);

	if (test_coef(a, b, c))
	{
		rad=radacini(a, b, c);
		if ((rad[0].im)||(rad[1].im)) printf("Ecuatia nu are radacini reale!\n\r");
		else if (rad[0].rl==rad[1].rl) printf("Ecuatia are radacina unica x=x1=x2!\n\r");
		print_cplx(rad[0]);
		print_cplx(rad[1]);
	}

	getch();
	return 0;
}