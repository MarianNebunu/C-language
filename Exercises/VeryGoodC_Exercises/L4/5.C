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
	unsigned n;
	unsigned char o1, o2;

	clrscr();

	printf("n="); scanf("%u", &n);

	binar(n, 0);

	o1&=0x0000;
	o2&=0x0000;
	o1=(n&0x00FF);
	o2=(n>>8);
	n&=0x0000;
	n=o1;
	n=(n<<8)|o2;

	printf("\n\r");
	binar(n, 0);

	getch();
	return 0;
}