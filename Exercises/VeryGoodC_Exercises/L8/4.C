#include <stdio.h>
#include <conio.h>
#include <math.h>

int prim_core(int num, int cnt)
{
	if (cnt<num)
	{
		if (!(num%cnt)) return 0;
		return prim_core(num, cnt+1);
	}
	return 1;
}

int prim(int num)
{
	if (abs(num)<2) return 0;
	return prim_core(num, 2);
}

int main()
{
	unsigned i, n;

	clrscr();

	printf("Introduceti un numar: "); scanf("%d", &n);
	printf("Numerele prime mai mici sau egale cu n sunt: ");
	for (i=2; i<=n; i++)
		if (prim(i)) printf("%d ", i);

	getch();
	return 0;
}