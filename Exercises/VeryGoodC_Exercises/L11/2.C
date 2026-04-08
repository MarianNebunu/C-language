#include <stdio.h>
#include <conio.h>
#include <alloc.h>

typedef struct tag_LISTA {
	unsigned long val;
	struct tag_LISTA * Next;
} LISTA;

LISTA * Cap=NULL;

void Adauga(unsigned long val)
{
	LISTA * Nou;
	Nou=(LISTA *)malloc(sizeof(LISTA));
	Nou->val=val;
	Nou->Next=Cap;
	Cap=Nou;
}

void Afiseaza(void)
{
	LISTA * Parc;
	if (!Cap) printf("Lista este vida");
	for (Parc=Cap; Parc!=NULL; Parc=Parc->Next) printf("%8lXh ", Parc->val);
}

void Invers(void)
{
	LISTA * Parc, * Aux, * Aux2;
	Aux=Cap;
	Aux2=NULL;
	for (Parc=Cap; Aux!=NULL;)
	{
		Aux=Parc->Next;
		Parc->Next=Aux2;
		Aux2=Parc;
		Parc=Aux;
	}
	Cap=Aux2;
}

int Kill(void)
{
	LISTA * Aux;
	for (; Cap!=NULL;)
	{
		Aux=Cap->Next;
		free(Cap);
		Cap=Aux;
	}
	return 0;
}

int main()
{
	unsigned long nr;

	clrscr();

	do
	{
		printf("Introduceti un numar: ");
		scanf("%lu", &nr);
		if (nr) Adauga(nr);
	} while (nr);

	printf("Inainte:\n\r");
	Afiseaza();
	printf("\n\r\n\rDupa:\n\r");
	Invers();
	Afiseaza();

	getch();
	return Kill();
}