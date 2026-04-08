#include <stdio.h>
#include <conio.h>
#include <dos.h>

int main()
{
	double a, b;
	int o;

	clrscr();

	printf("a="); scanf("%lf", &a);
	printf("b="); scanf("%lf", &b);

	printf("1 - Suma numerelor introduse\n\r");
	printf("2 - Diferenta numerelor introduse\n\r");
	printf("3 - Produsul numerelor introduse\n\r");
	printf("4 - Raportul numerelor introduse\n\r");
	printf("5 - Exit\n\r\n\r\n\r");

	do
	{
		gotoxy(1, wherey()-1);
		clreol();
		printf("Optiunea dvs: ");
		scanf("%d", &o);
		if ((o<1)||(o>5))
		{
			printf("Optiunea introdusa nu este valida!");
			delay(1000);
			gotoxy(1, wherey());
			clreol();
		}
	} while ((o<1)||(o>5));

	switch(o)
	{
		case 1: printf("Suma a+b este %.4lf", (a+b)); break;
		case 2: printf("Diferenta a-b este %.4lf", (a-b)); break;
		case 3: printf("Produsul a*b este %.4lf", (a*b)); break;
		case 4: printf("Raportul a/b este %.4lf", (a/b)); break;
		case 5:
		default: return 0;
	}

	getch();
	return 0;
}