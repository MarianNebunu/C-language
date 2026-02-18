#include <stdio.h>
#include <conio.h>

int main()
{
	int tc, tf;

	clrscr();

	printf("tC="); scanf("%d", &tc);

	tf=(int)(((double)tc*1.8)+32);

	printf("tF=%d", tf);

	getch();
	return 0;
}