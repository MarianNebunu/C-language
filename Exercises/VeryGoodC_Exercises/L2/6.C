#include <stdio.h>
#include <conio.h>

int main()
{
	int p[256], n, cnt, i;

	clrscr();

	cnt=0;
	printf("Introduceti numerele:\n\r");
	do
	{
		scanf("%d", &n);
		if (n)
		{
			p[cnt]=n;
			cnt++;
			if (cnt==256) printf("Limita maxima de numere atinsa!\n\r");
		}
	} while ((n)&&(cnt<256));

	if (cnt>1)
		for (i=1; i<cnt; i++)
			if ((p[i-1]*2)==p[i]) printf("%d - %d\n\r", p[i-1], p[i]);

	getch();
	return 0;
}