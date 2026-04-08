#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define _MAX_STACK_ 380

unsigned vf;

/*Functia de afisare este facuta doar pentru a facilita
  posibilitatea vizualizarii runtime a modificarii stivei */

int afisare_s(unsigned char * stk)
{
	unsigned i;
	printf("\n\r");
	for (i=0; i<vf; i++) printf(" 0x%.2X ", stk[i]);
	return 1;
}

int meniu(unsigned char * stk)
{
	unsigned opt;
	unsigned val;

	clrscr();
	afisare_s(stk);
	gotoxy(1, 19);
	printf("\n\r  1 - Depunere in stiva");
	printf("\n\r  2 - Extragere din stiva");
	printf("\n\r  3 - Iesire\n\r");

	do
	{
		printf("\r"); clreol();
		printf("Optiunea dvs: ");
		opt=getche()-48;
		if ((opt)&&(opt>3))
		{
			printf("\n\rOptiunea introdusa nu este valida!");
			delay(1000);
			printf("\r"); clreol();
			gotoxy(1, wherey()-1);
		}
	} while ((opt)&&(opt>3));

	switch (opt)
	{
		case 1:
		{
			if (vf==_MAX_STACK_)
			{
				printf("\n\rStiva este plina!");
				delay(1000);
				return 1;
			}
			printf("\n\rIntroduceti valoarea [0, 65535]: ");
			scanf("%u", &val);
			fflush(stdin);
			stk[vf]=(val&0x00FF);
			vf++;
			if (val>0x00FF)
			{
				stk[vf]=((val&0xFF00)>>8);
				vf++;
			}
			return 1;
		}
		case 2:
		{
			if (!vf)
			{
				printf("\n\rStiva este goala!");
				delay(1000);
				return 1;
			}
			vf--;
			printf("\n\rValoarea extrasa este: %u", stk[vf]);
			stk[vf]=0;
			getch();
			return 1;
		}
		case 3:
		default: return 0;
	};
}

int main()
{
	unsigned char stiva[_MAX_STACK_];
	unsigned i;

	for (i=0; i<_MAX_STACK_; i++) stiva[i]=0;
	vf=0;

	do {} while (meniu(stiva));

	return 0;
}