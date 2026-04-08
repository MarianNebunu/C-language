#include <stdio.h>
#include <conio.h>

int main()
{
	int n;

	clrscr();

	printf("n="); scanf("%d", &n);

	printf("%d", (n%10));

	getch();
	return 0;
}