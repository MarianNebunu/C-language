#include <stdio.h>
#include <conio.h>

int main()
{
	int a, b, s;

	clrscr();

	printf("a="); scanf("%d", &a);
	printf("b="); scanf("%d", &b);

	s=a+b;

	printf("Suma este %d in hexa %X", s, s);

	getch();
	return 0;
}