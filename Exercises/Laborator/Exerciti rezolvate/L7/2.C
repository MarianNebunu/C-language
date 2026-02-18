#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
	unsigned n, i, max;
	char m[10][80];

	clrscr();

	do
	{
		printf("Cate siruri doriti sa introduceti? ");
		scanf("%u", &n);
      fflush(stdin);
	} while ((!n)||(n>10));

	for (i=0; i<n; i++)
	{
		printf("m[%u]=", i);
		gets(m[i]);
	}

	max=0;
	for (i=0; i<(n-1); i++)
	{
		if (strcmp(m[i], m[i+1])<0) max=i+1;
		else max=i;
	}

	printf("Sirul cel mai mare este: %s", m[max]);

	getch();
	return 0;
}