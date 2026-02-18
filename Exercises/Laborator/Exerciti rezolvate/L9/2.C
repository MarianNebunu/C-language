#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <string.h>
#include <dos.h>
#include <math.h>
#include <ctype.h>

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

typedef struct tag_CARTE {
	char Titlu[100];
	char Autor[100];
	char Domeniu[100];
	unsigned An;
	unsigned Nr_pag;
	struct tag_CARTE * Next;
	struct tag_CARTE * Prev;
} CARTE;

CARTE * Cap=NULL;

void Adaugare(void)
{
	CARTE * Nou, * Parc;
	unsigned x;

	clrscr();
	Nou=(CARTE *)malloc(sizeof(CARTE));
	printf("Introduceti datele cartii:");
	printf("\n\r  Titlul: "); gets(Nou->Titlu);
	printf("  Autorul: "); gets(Nou->Autor);
	printf("  Anul: "); scanf("%u", &(Nou->An));
	printf("  Numarul de pagini: "); scanf("%u", &(Nou->Nr_pag));
	printf("  Domeniul: "); fflush(stdin); gets(Nou->Domeniu);

	if (Cap)
	{
		x=0;
		for (Parc=Cap; Parc->Prev!=NULL; Parc=Parc->Prev);
		for (; !x; Parc=Parc->Next)
		{
			if ((!strcmpi(Nou->Domeniu, Parc->Domeniu))||(Parc->Next==NULL))
			{
				x=1;
				Cap=Parc;
			}
		}
	}
	Nou->Prev=Cap;
	if (Nou->Prev)
	{
		Nou->Next=(Nou->Prev)->Next;
		(Nou->Prev)->Next=Nou;
		if (Nou->Next) (Nou->Next)->Prev=Nou;
	}
	else Nou->Next=NULL;
	Cap=Nou;
}

void Afisare(void)
{
	CARTE * Parc;
	char dom[100];

	clrscr();
	if (!Cap)
	{
		printf("\n\rNu sunt carti in biblioteca!");
		delay(1000);
		return;
	}
	printf("Introduceti domeniul: "); fflush(stdin); gets(dom);
	printf("\n\rCartile din domeniul %s:\n\r%25s%25s%6s%5s", dom, "Titlu", "Autor", "Anul", "Pag");
   printf("\n\r");
	for (Parc=Cap; Parc->Prev!=NULL; Parc=Parc->Prev);
	for (; Parc!=NULL; Parc=Parc->Next)
		if (!strcmpi(Parc->Domeniu, dom)) printf("\n\r%25s%25s%6u%5u", Parc->Titlu, Parc->Autor, Parc->An, Parc->Nr_pag);
   getch();
}

void Cautare(void)
{
	CARTE * Parc;
	char tit[100];

	clrscr();
	if (!Cap)
	{
		printf("\n\rNu sunt carti in biblioteca!");
		delay(1000);
		return;
	}
	printf("Introduceti titlul: "); fflush(stdin); gets(tit);
	printf("\n\r%25s%25s%6s%5s%18s", "Titlu", "Autor", "Anul", "Pag", "Domeniu");
	printf("\n\r");
	for (Parc=Cap; Parc->Prev!=NULL; Parc=Parc->Prev);
	for (; Parc!=NULL; Parc=Parc->Next)
		if (!strcmpi(Parc->Titlu, tit)) printf("\n\r%25s%25s%6u%5u%18s", Parc->Titlu, Parc->Autor, Parc->An, Parc->Nr_pag, Parc->Domeniu);
   getch();
}

void Stergere(void)
{
	CARTE * Parc, * Aux;
	char tit[100];

	if (!Cap)
	{
		printf("\n\rNu sunt carti in biblioteca!");
		delay(1000);
		return;
	}
	clrscr();
	printf("Introduceti titlul: "); fflush(stdin); gets(tit);
	for (Parc=Cap; Parc->Prev!=NULL; Parc=Parc->Prev);
	for (; Parc!=NULL; Parc=Parc->Next)
	{
		if (!strcmpi(Parc->Titlu, tit))
		{
			Aux=Parc;
			if (Parc->Prev) (Parc->Prev)->Next=Parc->Next;
			if (Parc->Next) (Parc->Next)->Prev=Parc->Prev;
			if (Cap==Parc)
			{
				if (Parc->Prev) Cap=Parc->Prev;
				else
				{
					if (Parc->Next) Cap=Parc->Next;
					else
					{
						Cap=NULL;
						return;
					}
				}
			}
			Parc=Aux->Next;
			free(Aux);
		}
	}
}

int Sort_core(char * dom, CARTE * actual)
{
	CARTE * urmator, * aux;
	unsigned c;
	urmator=actual->Next;
	if (!urmator) return 1;
	else if (strcmpi(dom, urmator->Domeniu)) return 1;
	for (c=0; c<(((strlen(actual->Titlu)+strlen(urmator->Titlu))-abs(((int)strlen(actual->Titlu))-((int)strlen(urmator->Titlu))))/2); c++)
	{
		if (toupper(actual->Titlu[c])>toupper(urmator->Titlu[c]))
		{
			urmator->Prev=actual->Prev;
			actual->Next=urmator->Next;
			urmator->Next=actual;
			actual->Prev=urmator;
			aux=actual;
			actual=urmator;
			urmator=aux;
			if (urmator->Next) (urmator->Next)->Prev=urmator;
			if (actual->Prev)
			{
				(actual->Prev)->Next=actual;
				if (!strcmpi(actual->Prev->Domeniu, dom)) return Sort_core(dom, actual->Prev);
			}
         return Sort_core(dom, urmator);
		}
		else if (toupper(actual->Titlu[c])<toupper(urmator->Titlu[c])) return Sort_core(dom, urmator);
	}
	return Sort_core(dom, urmator);
}

void Sortare(void)
{
	CARTE * Parc;
	char dom[100];

	if (!Cap)
	{
		printf("\n\rNu sunt carti in biblioteca!");
		delay(1000);
		return;
	}
	clrscr();
	printf("Introduceti domeniul: "); fflush(stdin); gets(dom);
	for (Parc=Cap; Parc->Prev!=NULL; Parc=Parc->Prev);
	for (; Parc!=NULL; Parc=Parc->Next)
	{
		if (!strcmpi(Parc->Domeniu, dom))
		{
			Sort_core(dom, Parc);
			return;
		}
	}
	printf("Domeniul nu a fost gasit!");
	delay(1000);
}

void Kill(void)
{
	CARTE * Aux;
	for (; Cap->Prev!=NULL; Cap=Cap->Prev);
	for (; Cap!=NULL;)
	{
		Aux=Cap;
		Cap=Cap->Next;
		free(Aux);
	}
}

int meniu(int x)
{
	const char men[6][80]={	"Adaugare carte",
				"Afisare carti dintr-un domeniu",
				"Cautare carte dupa titlu",
				"Stergere carte",
				"Sortare carti dintr-un domeniu dupa titlu",
				"Iesire" };
	unsigned ttl;

	ttl=0;
	do
	{
		switch (meniu_core(men, 6))
		{
			case 1: Adaugare(); break;
			case 2: Afisare(); break;
			case 3: Cautare(); break;
			case 4: Stergere(); break;
			case 5: Sortare(); break;
			case 6:
			default: ttl=1;
		}
	} while (!ttl);
	Kill();
	return x;
}

int main()
{
	return meniu(0);
}