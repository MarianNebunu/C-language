#include <stdio.h>
#include <conio.h>

int binar(unsigned num, unsigned cnt)
{
	if (cnt>15) return (num>>(cnt-1))&1;
	printf("%d", binar(num, cnt+1));
	return (num>>(cnt-1))&1;
}

int main()
{
	int n, p, nr, i;
	unsigned m;

	clrscr();

	printf("nr="); scanf("%x", &nr);
	printf("n="); scanf("%d", &n);
	printf("p="); scanf("%d", &p);

	binar(nr, 0);
	m&=0x0000;
	for (i=0; i<n; i++)
	{
		m=m>>1;
		m|=0x8000;
	}
	m=m>>p;
	
	nr=nr|m;

	printf("\n\r");
	binar(nr, 0);

	getch();
	return 0;
}