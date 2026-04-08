#include <stdio.h>
#include <conio.h>

int main()
{
	int n, i;

	clrscr();

	printf("n="); scanf("%d", &n);
	printf("Divizorii sunt: ");
	for (i=1; i<=n; i++)
		if (!(n%i)) printf("%d ", i);

	getch();
	return 0;
}