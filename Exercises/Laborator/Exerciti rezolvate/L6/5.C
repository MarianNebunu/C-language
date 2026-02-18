#include <stdio.h>
#include <conio.h>

int main()
{
	int v[256];
	unsigned i, j, k, n;
	int aux;

	clrscr();

	printf("Cate numere doriti? "); scanf("%u", &n);
	if (n>256) n=256;
	
	for (i=0; i<n; i++)
	{
		printf("v[%u]=", i);
		scanf("%u", (v+i));
	}

	k=0;
	for (i=0; i<n; i++)
	{
		if (!(v[i]%2))
		{
			aux=v[i];
			for (j=i; j>k; j--) v[j]=v[j-1];
			v[k]=aux;
			k++;
		}
	}
	
	for (i=0; i<n; i++) printf("%d ", v[i]);

	getch();
	return 0;
}