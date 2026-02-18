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

typedef struct tag_UTILAJ {
	char Nume[30];
	unsigned Fabr;
	char Sect[30];
	struct tag_UTILAJ * Next;
} UTILAJ;

UTILAJ * Cap=NULL;

unsigned GetS(char * S)
{
	if (!S) return 0;
	fflush(stdin);
	do {gets(S);} while (!strlen(S));
	return strlen(S);
}

void Adaugare(void)
{
	UTILAJ * Nou, * Parc;

	Nou=(UTILAJ *)malloc(sizeof(UTILAJ));
	clrscr();
	printf("Introduceti numele utilajului: "); GetS(Nou->Nume);
	printf("Introduceti anul fabricatiei: "); scanf("%u", &(Nou->Fabr));
	printf("Introduceti sectorul: "); GetS(Nou->Sect);

	if (Cap)
	{
		for (Parc=Cap; Parc->Next!=NULL; Parc=Parc->Next)
		{
			if (!strcmpi(Nou->Sect, Parc->Sect))
			{
				Nou->Next=Parc->Next;
				Parc->Next=Nou;
				return;
			}
		}
		Nou->Next=NULL;
		Parc->Next=Nou;
		return;
	}
	Nou->Next=NULL;
	Cap=Nou;
}

void Afisare(char * Sec, int x)
{
	UTILAJ * Parc;

	if (!Cap)
	{
		printf("\n\rNu sunt utilaje in depozit!");
		delay(1000);
		return;
	}
	if (x) clrscr();
	printf("\n\r| %30s | %5s | %30s |\n\r", "Denumire", "Anul", "Sector");
	for (Parc=Cap; Parc!=NULL; Parc=Parc->Next)
	{
		if (Sec)
		{
			if (!strcmpi(Parc->Sect, Sec))
				printf("\n\r| %30s | %5u | %30s |", Parc->Nume, Parc->Fabr, Parc->Sect);
		}
		else printf("\n\r| %30s | %5u | %30s |", Parc->Nume, Parc->Fabr, Parc->Sect);
	}
	getch();
}

void Mutare(void)
{
	UTILAJ * Parc, * Aux;
	char s[30], n[30];

	Aux=NULL;
	if (!Cap)
	{
		printf("\n\rNu sunt utilaje in depozit!");
		delay(1000);
		return;
	}
	clrscr();
	printf("Introduceti numele utilajului: "); GetS(n);
	printf("Introduceti sectorul in care il mutati: "); GetS(s);

	if (!strcmpi(Cap->Nume, n))
	{
		Aux=Cap;
		Cap=Cap->Next;
	}
	for (Parc=Cap; (Parc->Next)&&(!Aux); Parc=Parc->Next)
	{
		if (!strcmpi(Parc->Next->Nume, n))
		{
			Aux=Parc->Next;
			Parc->Next=Aux->Next;
		}
	}
	if (Aux)
	{
		strcpy(Aux->Sect, s);
		for (Parc=Cap; Parc->Next!=NULL; Parc=Parc->Next)
		{
			if (!strcmpi(Parc->Sect, Aux->Sect))
			{
				Aux->Next=Parc->Next;
				Parc->Next=Aux;
				printf("\n\rUtilajul a fost mutat!");
				getch();
				return;
			}
		}
		Aux->Next=NULL;
		Parc->Next=Aux;
		printf("\n\rUtilajul a fost mutat!");
		getch();
		return;
	}
	printf("\n\rUtilajul nu a fost gasit!");
	getch();
	return;
}

unsigned Sort_core(UTILAJ * Ant, UTILAJ * Cur, char * Sec)
{
	UTILAJ * Urm, * Aux;

	if ((!Cur)||(!Sec)) return 0;

	Urm=Cur->Next;

	if (!Urm) return 1;
	if (strcmpi(Urm->Sect, Sec)) return 1;

	if (!Sort_core(Cur, Urm, Sec)) return 0;

	Urm=Cur->Next;

	if (!Urm) return 1;
	if (strcmpi(Urm->Sect, Sec)) return 1;

	if ((Cur->Fabr)<(Urm->Fabr))
	{
		if (Ant) Ant->Next=Urm;
		Cur->Next=Urm->Next;
		Urm->Next=Cur;
		if (Cap==Cur) Cap=Urm;
		return Sort_core(Urm, Cur, Sec);
	}
	return 1;
}

void Sortare(void)
{
	UTILAJ * Parc;
	char s[30];

	if (!Cap)
	{
		printf("\n\rNu sunt utilaje in depozit!");
		delay(1000);
		return;
	}
	clrscr();
	printf("Introduceti sectorul: "); GetS(s);
	if (!strcmpi(Cap->Sect, s))
	{
		Sort_core(NULL, Cap, s);
		Afisare(s, 0);
		return;
	}
	for (Parc=Cap; Parc->Next!=NULL; Parc=Parc->Next)
	{
		if (!strcmpi(Parc->Sect, s))
		{
			if (Sort_core(Parc, Parc->Next, s))
			{
				Afisare(s, 0);
				return;
			}
			else
			{
				printf("\n\rEroare de sortare!");
				delay(1000);
				return;
			}
		}
	}
	printf("\n\rSectorul introdus nu exista!");
	delay(1000);
}

void Stergere(void)
{
	UTILAJ * Parc, * Aux;
	char n[30];

	if (!Cap)
	{
		printf("\n\rNu sunt utilaje in depozit!");
		delay(1000);
		return;
	}
	clrscr();
	printf("Introduceti numele utilajului: "); GetS(n);
	if (!strcmpi(Cap->Nume, n))
	{
		Aux=Cap;
		Cap=Cap->Next;
		free(Aux);
		return;
	}
	for (Parc=Cap; Parc->Next!=NULL; Parc=Parc->Next)
	{
		if (!strcmpi(Parc->Next->Nume, n))
		{
			Aux=Parc->Next;
			Parc->Next=Aux->Next;
			free(Aux);
			printf("\n\rUtilajul a fost sters!");
		}
	}
}

unsigned Kill(void)
{
	UTILAJ * Aux;
	if (Cap)
	{
		for (; Cap;)
		{
			Aux=Cap->Next;
			free(Cap);
			Cap=Aux;
		}
	}
	return 0;
}

void meniu(void)
{
	const char men[6][80]={	"Adauga utilaj",
				"Afiseaza utilaje",
				"Muta utilaj",
				"Afiseaza utilaje dintr-un sector in ordine descrescatoare",
				"Sterge utilaj",
				"Iesire" };
	unsigned ttl;

	ttl=0;
	do
	{
		switch (meniu_core(men, 6))
		{
			case 1: Adaugare(); break;
			case 2: Afisare(NULL, 1); break;
			case 3: Mutare(); break;
			case 4: Sortare(); break;
			case 5: Stergere(); break;
			case 6:
			default: ttl=1;
		}
	} while (!ttl);
}

int main()
{
	meniu();
	return Kill();
}