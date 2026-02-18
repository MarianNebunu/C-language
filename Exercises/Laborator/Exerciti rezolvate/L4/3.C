#include <stdio.h>
#include <conio.h>

int main()
{
	unsigned char n;
	unsigned i;

	clrscr();

	printf("n="); scanf("%u", &n);

	for (i=0; i<8; i++) printf("%u", ((n>>(7-i))&1));

	getch();
	return 0;
}