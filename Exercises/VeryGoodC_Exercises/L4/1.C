#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
	unsigned a, b, c;
	double p;

	clrscr();

	printf("a="); scanf("%d", &a);
	printf("b="); scanf("%d", &b);
	printf("c="); scanf("%d", &c);

	p=(double)(a+b+c)/2;

	if ((p<a)||(p<b)||(p<c)) printf("Valorile introduse nu definesc un triunghi!");
	else printf("Aria este: %lf", pow((p*(p-a)*(p-b)*(p-c)), 0.5)); //sqrt(p*(p-a)*(p-b)*(p-c))

	getch();
	return 0;
}