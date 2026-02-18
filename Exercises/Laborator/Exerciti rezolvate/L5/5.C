#include <stdio.h>
#include <conio.h>

int main()
{
	int n, S=0, cnt=0;

	clrscr();

	do
	{
		scanf("%d", &n);
		S+=n;
		if (n) cnt++;
	} while (n);

	printf("\n\rMedia este %.2lf", (((double)S)/(double)cnt));

	getch();
	return 0;
}