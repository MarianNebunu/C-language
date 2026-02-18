#include <stdio.h>
#include <conio.h>
#include <math.h>

int prim_core(int num, int cnt)
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
	if (abs(num)<2) return 0;
	return prim_core(num, 2);
}

int main()
{
	int i, n, nr, S, P;

	clrscr();

	printf("n="); scanf("%d", &n);

	S=0;
	P=1;
	for(i=0; i<n; i++)
	{
		scanf("%d", &nr);
		if (!(nr%2)) S+=nr;
		if (prim(abs(nr))) P*=nr;
	}
	
	if (!S) printf("Nu au fost numere pare. S=0\n\r");
	else printf("Suma este S=%d\n\r", S);
	if (P==1) printf("Nu au fost numere prime. P nu exista\n\r");
	else printf("Produsul este P=%d\n\r", P);

	getch();
	return 0;
}