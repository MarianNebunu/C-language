#include <stdio.h>
#include <conio.h>

int main()
{
	char n[100];
	int v;

	clrscr();

	printf("Nume="); gets(n);
	printf("Varsta="); scanf("%d", &v);

	printf("Numele este %s\nVarsta este %d", n, v);

	getch();
	return 0;
}