#include <stdio.h>
#include <conio.h>

int main()
{
	int n, max=(-32768);

	clrscr();

	do
	{
		scanf("%d", &n);
		if (n>max) max=n;
	} while (n);

	printf("\n\rMaximul este %d", max);

	getch();
	return 0;
}