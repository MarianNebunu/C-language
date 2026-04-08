#include <stdio.h>
#include <conio.h>

int main()
{
	unsigned n;

	clrscr();

	printf("n="); scanf("%u", &n);

	printf("O1=%.2X O2=%.2X", (n%256), (n/256));

	getch();
	return 0;
}