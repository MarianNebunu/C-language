#include <stdio.h>
#include <conio.h>

int main()
{
	int a, b, c, max;

	clrscr();

	printf("a="); scanf("%d", &a);
	printf("b="); scanf("%d", &b);
	printf("c="); scanf("%d", &c);

	if (a>=b)
	{
		if (a>=c) max=a;
		else max=c;
	}
	else
	{
		if (b>=c) max=b;
		else max=c;
	}
	printf("Maximul este: %d", max);

	getch();
	return 0;
}