#include <stdio.h>
#include <conio.h>

int main()
{
	int n, S=0;

	clrscr();

	do
	{
		scanf("%d", &n);
		S+=n;
	} while (n);

	printf("\n\rSuma este %d", S);

	getch();
	return 0;
}