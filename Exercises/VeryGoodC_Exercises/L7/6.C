#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <string.h>
#include <dos.h>

typedef struct tagCARTE {
	char Titlu[100];
	char Autor[100];
	struct tagCARTE * Prev;
	struct tagCARTE * Next;
} CARTE;

CARTE * Bibl=NULL;

int Adauga(int x)
{
	CARTE * Nou;
	Nou=(CARTE *)malloc(sizeof(CARTE));

	clrscr();
	printf("\n\r  Introduceti autorul: "); gets(Nou->Autor);
	printf("\n\r  Introduceti titlul: "); gets(Nou->Titlu);
	Nou->Prev=Bibl;
	Nou->Next=NULL;
   if (Bibl!=NULL)
	{
		Nou->Next=Bibl->Next;
		Bibl->Next=Nou;
	}
	Bibl=Nou;
	return x;
}

int Sterge(int x)
{
	CARTE * Parc;
	char a[100];
	char t[100];
	unsigned char f1, f2;

	if (!Bibl)
	{
		printf("\n\rBiblioteca este goala!");
		delay(1000);
		return 0;
	}

	a[0]='\0';
	t[0]='\0';
	do
	{
		clrscr();
		printf("\n\r\n\rIntroduceti autorul cartii: "); gets(a);
		printf("Introduceti titlul cartii: "); gets(t);
	} while ((a[0]=='\0')&&(t[0]=='\0'));

	for (Parc=Bibl; Parc->Prev!=NULL; Parc=Parc->Prev);
	for (; Parc!=NULL; Parc=Parc->Next)
	{
		f1=0;
		f2=0;
		if (!strcmpi(a, Parc->Autor)) f1=1;
		if (!strcmpi(t, Parc->Titlu)) f2=1;
		if ((a[0]=='\0')&&(f2))
		{
			if (Parc->Prev!=NULL) (Parc->Prev)->Next=Parc->Next;
			if (Parc->Next!=NULL) (Parc->Next)->Prev=Parc->Prev;
			free(Parc);
			return x;
		}
		if ((t[0]=='\0')&&(f1))
		{
			if (Parc->Prev!=NULL) (Parc->Prev)->Next=Parc->Next;
			if (Parc->Next!=NULL) (Parc->Next)->Prev=Parc->Prev;
			free(Parc);
			return x;
		}
		if (f1&&f2)
		{
			if (Parc->Prev!=NULL) (Parc->Prev)->Next=Parc->Next;
			if (Parc->Next!=NULL) (Parc->Next)->Prev=Parc->Prev;
			free(Parc);
			return x;
		}
	}
	return 0;
}

int Cauta(int Elem)
{
	CARTE * Parc;
	char s[100];
	unsigned f1=0;

	if (!Bibl)
	{
		printf("\n\rBiblioteca este goala!");
		delay(1000);
		return 0;
	}

	s[0]='\0';
	do
	{
		clrscr();
		printf("\n\r\n\r  Introduceti textul: ");
		gets(s);
	} while (s[0]=='\0');

	for (Parc=Bibl; Parc->Prev!=NULL; Parc=Parc->Prev);
	if (Elem)
	{
		for (; Parc!=NULL; Parc=Parc->Next)
      {
			if (!strcmpi(s, Parc->Autor))
			{
				printf("\n\rTitlu %s, Autor %s", Parc->Titlu, Parc->Autor);
				f1=1;
			}
		}
	}
	else
	{
		for (; Parc!=NULL; Parc=Parc->Next)
		{
			if (!strcmpi(s, Parc->Titlu))
			{
				printf("\n\rTitlu %s, Autor %s", Parc->Titlu, Parc->Autor);
				f1=1;
			}
		}
	}
	if (!f1) printf("\n\rCartea nu a fost gasita!");
	getch();
	return 1;
}

int Killib(int x)
{
	CARTE * Parc, * Aux;
	if (!Bibl) return 0;
	for (Parc=Bibl; Parc->Prev!=NULL; Parc=Parc->Prev);
	for (; Parc!=NULL;)
	{
		Aux=Parc;
		Parc=Parc->Next;
		free(Aux);
	}
	return x;
}

int meniu(int x)
{
	unsigned opt;

	clrscr();
	printf("\n\r  1 - Adaugare carte");
	printf("\n\r  2 - Cautare dupa titlu");
	printf("\n\r  3 - Cautare dupa autor");
	printf("\n\r  4 - Stergere carte");
	printf("\n\r  5 - Iesire\n\r\n\r");

	do
	{
		clreol();
		printf("Optiunea dvs: ");
		opt=getche()-48;
		if ((!opt)||(opt>5))
		{
			printf("\n\rOptiunea introdusa nu este valida!");
			delay(1000);
			printf("\r"); clreol();
			gotoxy(1, wherey()-1);
		}
	} while ((!opt)||(opt>5));

	switch (opt)
	{
		case 1:
		{
			Adauga(1);
			return x;
		}
		case 2:
		{
			Cauta(0);
			return x;
		}
		case 3:
		{
			Cauta(1);
			return x;
		}
		case 4:
		{
			Sterge(1);
			return x;
		}
		case 5:
		default: return 0;
	};
}

int main()
{
	clrscr();

	do {} while (meniu(1));

	return Killib(0);
}