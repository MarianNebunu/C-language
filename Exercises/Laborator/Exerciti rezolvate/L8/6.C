#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <dos.h>
#include <alloc.h>
#include <ctype.h>
#include <math.h>

#define _MAX_MAT_ 256

char mat[256][100];
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

int init_m(int x)
{
	for (i=0; i<_MAX_MAT_; i++) mat[i][0]='\0';
	nel=0;
	return x;
}

int adaugare(char * elev)
{
	if (!elev) return 0;
	if (nel<_MAX_MAT_)
	{
		strcpy(mat[nel], elev);
		nel++;
		return 1;
	}
	return 0;
}

int afisare(int x)
{
	if (x<nel)
	{
		printf("%s\n\r", mat[x]);
		return afisare(x+1);
	}
	return 1;
}

int cautare(char * elev)
{
	for (i=0; i<nel; i++)
		if (!strcmpi(mat[i], elev)) return i;
	return -1;
}

int sort_core(int poz, int x)
{
	char * aux;
	unsigned c;
	if (!x)
	{
		if (poz<(nel-1))
		{
			for (c=0; c<(((strlen(mat[poz])+strlen(mat[poz+1]))-abs((int)strlen(mat[poz])-(int)strlen(mat[poz+1])))/2); c++)
			{
				if (toupper(mat[poz][c])>toupper(mat[poz+1][c]))
				{
					aux=(char *)malloc(100*sizeof(char));
					strcpy(aux, mat[poz]);
					strcpy(mat[poz], mat[poz+1]);
					strcpy(mat[poz+1], aux);
					free(aux);
					if (poz) return sort_core(poz-1, x);
					else return sort_core(poz+1, x);
				}
				else if (toupper(mat[poz][c])<toupper(mat[poz+1][c])) return sort_core(poz+1, x);
			}
			return sort_core(poz+1, x);
		}
		else return 1;
	}
	else
	{
		if (poz<(nel-1))
		{
			for (c=0; c<(((strlen(mat[poz])+strlen(mat[poz+1]))-abs((int)strlen(mat[poz])-(int)strlen(mat[poz+1])))/2); c++)
			{
				if (toupper(mat[poz][c])<toupper(mat[poz+1][c]))
				{
					aux=(char *)malloc(100*sizeof(char));
					strcpy(aux, mat[poz]);
					strcpy(mat[poz], mat[poz+1]);
					strcpy(mat[poz+1], aux);
					free(aux);
					if (poz) return sort_core(poz-1, x);
					else return sort_core(poz+1, x);
				}
				else if (toupper(mat[poz][c])>toupper(mat[poz+1][c])) return sort_core(poz+1, x);
			}
			return sort_core(poz+1, x);
		}
		else return 1;
	}
}

int sortare(int x)
{
	return sort_core(0, x);
}

int meniu(int x)
{
	const char men[5][80]={	"Adaugare elev",
				"Afisare elevi",
				"Cautare dupa nume",
				"Sortare alfabetica dupa nume",
				"Iesire" };
	const char smen[2][80]={"Crescator",
				"Descrescator" };
	char nm[100];
	unsigned ttl;

	ttl=0;
	do
	{
		switch (meniu_core(men, 5))
		{
			case 1:
			{
				printf("\n\rIntroduceti numele elevului: ");
				gets(nm);
				if (!adaugare(nm))
				{
					printf("Baza de date este plina!");
					delay(1000);
				}
			} break;
			case 2:
			{
				printf("\n\rElevii:\n\r");
				afisare(0);
				getch();
			} break;
			case 3:
			{
				printf("\n\rIntroduceti numele elevului: ");
				gets(nm);
				if (cautare(nm)<0) printf("Elevul nu a fost gasit!");
				else printf("Elevul a fost gasit!");
				getch();
			} break;
			case 4:
			{
				printf("\n\rCum doriti sa sortati elevii?\n\r");
				sortare(meniu_core(smen, 2)-1);
				printf("\n\r");
				afisare(0);
			} break;
			case 5:
			default: ttl=1;
		};
	} while (!ttl);
	return x;
}

int main()
{
	init_m(0);
	return meniu(0);
}