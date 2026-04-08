#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define _MAX_TAB_ 256

int tab[256];
unsigned i, nel;

unsigned meniu_core(const char mtext[][80], unsigned mitems)
{
	unsigned sel, c;
	char b1, b2;
	if ((!mtext)||(!mitems)) return 0xFFFF;
	sel=0;
	clrscr();
	do
	{
		textattr(0x0F);
		gotoxy(1, 1);
		_setcursortype(_NOCURSOR);
		for (c=0; c<mitems; c++)
		{
			if (sel==c) textattr(0x70);
			cprintf("%s", mtext[c]);
			textattr(0x0F);
			cprintf("\n\r");
		}
		b1=getch();
		if (kbhit())
			b2=getch();
		if (!b1)
		{
			switch (b2)
			{
				case 72:
				{
					if (sel>0) sel--;
					else sel=mitems-1;
				} break;
				case 80:
				{
					if (sel<(mitems-1)) sel++;
					else sel=0;
				} break;
			};
		}
	} while (b1!=13);
	_setcursortype(_NORMALCURSOR);
	textattr(0x0F);
	return (sel+1);
}

int init_t(int x)
{
	for (i=0; i<_MAX_TAB_; i++) tab[i]=x;
	nel=0;
	return 1;
}

int adauga(int nr)
{
	if (nel<_MAX_TAB_)
	{
		for (i=0; i<nel; i++)
			if (tab[i]==nr) return 0;
		tab[nel]=nr;
		nel++;
		return 1;
	}
	return 0;
}

int afisare(unsigned x)
{
	if (x<nel)
	{
		printf("%6d ", tab[x]);
		return afisare(x+1);
	}
	return 1;
}

int sterge(int nr)
{
	int x=0;
	for (i=0; i<(nel-x); i++)
	{
		if (tab[i]==nr) x++;
		tab[i]=tab[i+x];
	}
	nel--;
	tab[nel]=0;
	return x;
}

int meniu(int x)
{
	unsigned ttl;
	int nr;
	const char men[4][80]={	"Introducere numar",
				"Afisare tablou",
				"Stergere numar",
				"Iesire"};
	ttl=0;
	do
	{
		switch (meniu_core(men, 4))
		{
			case 1:
			{
				printf("\n\rIntroduceti numarul: ");
				scanf("%d", &nr);
				if (!adauga(nr))
				{
					printf("Numarul introdus exista deja sau tabloul este plin!");
					delay(1000);
				}
			} break;
			case 2:
			{
				printf("\n\rTabloul:\n\r");
				afisare(0);
				getch();
			} break;
			case 3:
			{
				printf("\n\rIntroduceti numarul: ");
				scanf("%d", &nr);
				if (!sterge(nr))
				{
					printf("Numarul nu a fost gasit!");
					delay(1000);
				}
			} break;
			case 4:
			default: ttl=1;
		};
	} while (!ttl);
	return x;
}

int main()
{
	init_t(0);
	return meniu(0);
}