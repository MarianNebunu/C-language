#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <string.h>
#include <dos.h>

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

typedef struct tag_STIVA {
	char NStr[20];
	unsigned Nr;
	struct tag_STIVA * Next;
} STIVA;

STIVA * Varf=NULL;

unsigned GetS(char * S)
{
	if (!S) return 0;
	fflush(stdin);
	do {gets(S);} while (!strlen(S));
	return strlen(S);
}

void o_Push(void)
{
	STIVA * Nou;
	Nou=(STIVA *)malloc(sizeof(STIVA));
	printf("\n\r\n\rStrada: "); GetS(Nou->NStr);
	printf("Numar: "); scanf("%u", &(Nou->Nr));
	Nou->Next=Varf;
	Varf=Nou;
}

void o_Pop(void)
{
	STIVA * Aux;
	if (!Varf)
	{
		printf("\n\r\n\rStiva este vida!");
		delay(1000);
		return;
	}
	Aux=Varf;
	Varf=Varf->Next;
	printf("\n\r\n\rElementul extras:\n\rStrada: %s\n\rNumar: %u", Aux->NStr, Aux->Nr);
	getch();
	free(Aux);
}

void o_Display_core(STIVA * Parc)
{
	if (!Parc) return;
	o_Display_core(Parc->Next);
	printf("| %20s | %5u |\n\r", Parc->NStr, Parc->Nr);
	return;
}

void o_Display(void)
{
	if (!Varf)
	{
		printf("\n\rStiva este vida!");
		delay(1000);
		return;
	}
	printf("\n\r\n\r| %20s | %5s |\n\r\n\r", "Nume strada", "Numar");
	o_Display_core(Varf);
	getch();
}

int Kill(void)
{
	STIVA * Aux;
	for (; Varf;)
	{
		Aux=Varf->Next;
		free(Varf);
		Varf=Aux;
	}
	return 0;
}

int meniu(void)
{
	const char men[4][80]={	"Push",
				"Pop",
				"Display",
				"Exit" };
	unsigned ttl;

	ttl=0;
	do
	{
		switch (meniu_core(men, 4))
		{
			case 1: o_Push(); break;
			case 2: o_Pop(); break;
			case 3: o_Display(); break;
			case 4:
			default: ttl=1;
		}
	} while (!ttl);
	return Kill();
}

int main()
{
	return meniu();
}