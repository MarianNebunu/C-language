#include <stdio.h>
#include <conio.h>
#include <math.h>

int prim(int nr, int cnt)
{
	if (cnt<nr)
	{
		if (!(nr%cnt)) return 0;
		else return prim(nr, cnt+1);
	}
	return 1;
}

int main()
{
	int n;	

	clrscr();

	printf("n="); scanf("%d", &n);

	printf("Numarul ");
	if (abs(n)>=2)
	{
		if (!prim(abs(n), 2)) printf("nu ");
	}
	else printf("nu ");
	printf("este prim");

	getch();
	return 0;
}