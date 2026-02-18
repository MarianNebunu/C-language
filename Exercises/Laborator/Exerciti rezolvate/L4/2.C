#include <stdio.h>
#include <conio.h>

int main()
{
	int b[8], i, z;
	char c;

	clrscr();

	printf("Introduceti numarul binar:\n\r");
	do
	{
		for (i=0; i<8; i++)
		{
			c=getche();
			if ((c!=48)&&(c!=49))
			{
				printf("\n\rEroare! Introduceti din nou!\n\r");
				i=9;
			}
			else b[i]=((int)c)-48;
		}
	} while (i!=8);

	z=b[0];
	for (i=1; i<8; i++) z=(z*2)+b[i];
	printf("\n\rNumarul in baza 10 este: %d", z);

	getch();
	return 0;
}