#include <stdio.h>
#include <conio.h>

int prim_core(int num, unsigned cnt)
{
	if (cnt<num)
	{
		if (!(num%cnt)) return 0;
		else return prim_core(num, cnt+1);
	}
	return 1;
}

int prim(int num)
{
	if ((num>(-2))&&(num<2)) return 0;
	return prim_core(num, 26);
}

int main()
{
	int n;

	clrscr();

	printf("n="); scanf("%d", &n);

	printf("Numarul ");
	if (!prim(n)) printf("nu ");
	printf("este prim");

	getch();
	return 0;
}