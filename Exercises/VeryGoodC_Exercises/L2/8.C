#include <stdio.h>
#include <conio.h>

int main()
{
	unsigned n, k, d, i, j;

	clrscr();

	printf("n="); scanf("%u", &n);
	printf("k="); scanf("%u", &k);

	for (i=0; i<n; i++)
	{
		d=0;
		for (j=1; j<=i; j++)
			if (!(i%j)) d++;
		if ((d==k)&&(d)) printf("%d ", i);
	}

	getch();
	return 0;
}