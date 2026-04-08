#include <stdio.h>
#include <conio.h>
#include <dos.h>

unsigned i, j;
unsigned marx=0, mary=0, mf=0;

int def_mar(int x)
{
	clrscr();
	printf("Introduceti numarul de linii: "); scanf("%u", &mary);
	printf("Introduceti numarul de coloane: "); scanf("%u", &marx);
   return x;
}

int citire_m(int (* mat)[50][50])
{
	clrscr();
	if (!mat) return 0;
	for (i=0; i<mary; i++)
		for (j=0; j<marx; j++)
		{
			printf("m[%u][%u]=", i, j);
			scanf("%d", &((* mat)[i][j]));
		}
	return 1;
}

void afisare_m(int mat[50][50])
{
	for (i=0; i<mary; i++)
	{
		for (j=0; j<marx; j++) printf(" %6d", mat[i][j]);
		printf("\n\r\n\r");
	}
}

int suma_m(int mat[50][50])
{
	int rv=0;

	printf("\n\r\n\r");
	afisare_m(mat);
	for (i=0; i<mary; i++) rv+=(mat[i][0]+mat[i][marx-1]);
	if (marx<2) return (rv/2);
	if (marx<3) return rv;
	if (mary<2) rv=rv*2;
	for (i=1; i<(marx-1); i++) rv+=(mat[0][i]+mat[mary-1][i]);
	if (mary<2) return (rv/2);
	return rv;
}

int ord_c(int * linie, unsigned poz)
{
	int aux;
	if (marx<2) return 1;
	if (linie[0]>linie[1])
	{
		aux=linie[0];
		linie[0]=linie[1];
		linie[1]=aux;
		if (poz!=0) return ord_c((linie-1), poz-1);
	}
	if (poz<(marx-2)) return ord_c((linie+1), poz+1);
	else return 1;
}

int ord_d(int * linie, unsigned poz)
{
	int aux;
	if (!linie) return 0;
	if (marx<2) return 1;
	if (linie[0]<linie[1])
	{
		aux=linie[0];
		linie[0]=linie[1];
		linie[1]=aux;
		if (poz!=0) ord_d((linie-1), poz-1);
	}
	if (poz<(marx-2)) return ord_d((linie+1), poz+1);
	else return 1;
}

int inter_v(int * linie)
{
	int aux;
	unsigned ind1, ind2, wy;
	if (!linie) return 0;
	if (marx<2) return 1;
	do
	{
		printf("\n\r  Introduceti perechea [1, m] [1, m] de interschimbat ('0 0' - anulare): ");
		wy=wherey();
		scanf("%u %u", &ind1, &ind2);
		fflush(stdin);
		if (((ind1>marx)||(ind2>marx))&&((ind1)||(ind2)))
		{
			printf("\n\rValorile introduse nu sunt valide!");
			delay(1000);
			printf("\r"); clreol();
			do
			{
				gotoxy(1, wherey()-1);
				clreol();
			} while (wherey()!=wy);
		}
	} while (((ind1>=marx)||(ind2>=marx))&&((ind1)||(ind2)));

   if ((!ind1)&&(!ind2)) return 0;

	aux=linie[ind1-1];
	linie[ind1-1]=linie[ind2-1];
	linie[ind2-1]=aux;
	return 1;
}

int inter_c(int (* mat)[50][50])
{
	unsigned ind1, ind2, wy;
	int aux;

	clrscr();
	if (!mat) return 0;
	printf("INTERSCHIMBARE COLOANE\n\r\n\r");
	afisare_m(*mat);
	printf("\n\r");
	do
	{
		printf("  Introduceti perechea [1, m] [1, m] de interschimbat ('0 0' - anulare): ");
		wy=wherey();
		scanf("%u %u", &ind1, &ind2);
		if (((ind1>marx)||(ind2>marx))&&((ind1)||(ind2)))
		{
			printf("\n\rValorile introduse nu sunt valide!");
			delay(1000);
			printf("\r"); clreol();
			do
			{
				gotoxy(1, wherey()-1);
				clreol();
			} while (wherey()!=wy);
		}
	} while (((ind1>marx)||(ind2>marx))&&((ind1)||(ind2)));

	if ((!ind1)&&(!ind2)) return 0;

	for (i=0; i<mary; i++)
	{
		aux=(* mat)[i][ind1-1];
		(* mat)[i][ind1-1]=(* mat)[i][ind2-1];
		(* mat)[i][ind2-1]=aux;
	}
	return 1;
}

int meniu_2(int (* mat)[50][50])
{
	unsigned opt, lin;

	clrscr();
	printf("ORDONARE ELEMENTE PE LINII\n\r\n\r");
	afisare_m(*mat);
	printf("\n\r");
	do
	{
		printf("\r"); clreol();
		printf("  Introduceti linia [1, n] pe care doriti sa o modificati('0' - anulare): ");
		scanf("%u", &lin);
		if ((lin>mary)&&(lin))
		{
			printf("\n\rNumarul introdus nu este valid!");
			delay(1000);
			printf("\r"); clreol();
			gotoxy(1, wherey()-2);
		}
	} while ((lin>mary)&&(lin));
	if (!lin) return 0;

	printf("\n\r  1 - Ordonare crescator");
	printf("\n\r  2 - Ordonare descrescator");
	printf("\n\r  3 - Interschimbare elemente");
	printf("\n\r  4 - Inapoi\n\r\n\r");

	do
	{
		printf("\r"); clreol();
		printf("Optiunea dvs: ");
		opt=getche()-48;
		if ((opt<1)||(opt>4))
		{
			printf("\n\rOptiunea introdusa nu este valida!");
			delay(1000);
			printf("\r"); clreol();
			gotoxy(1, wherey()-1);
		}
	} while ((opt<1)||(opt>4));

	switch (opt)
	{
		case 1:
		{
			if (!ord_c((* mat)[lin-1], 0))
			{
				printf("\n\rOperatia nu s-a incheiat cu succes!");
				delay(1000);
			}
			return 1;
		}
		case 2:
		{
			if (!ord_d((* mat)[lin-1], 0))
			{
				printf("\n\rOperatia nu s-a incheiat cu succes!");
				delay(1000);
			}
			return 1;
		}
		case 3:
		{
			if (!inter_v((* mat)[lin-1]))
			{
				printf("\n\rOperatia nu s-a incheiat cu succes!");
				delay(1000);
			}
			return 1;
		}
		case 4:
		default: return 0;
	};
}

int meniu_1(int (* mat)[50][50])
{
	unsigned opt;

	clrscr();
	printf("\n\r  1 - Introducere marime matrice");
	printf("\n\r  2 - Introducere matrice");
	printf("\n\r  3 - Afisare matrice");
	printf("\n\r  4 - Ordonare elemente pe linii");
	printf("\n\r  5 - Interschimbare coloane");
	printf("\n\r  6 - Afisare suma elementelor de pe margine");
	printf("\n\r  7 - Iesire\n\r\n\r");

	do
	{
		printf("\r"); clreol();
		printf("Optiunea dvs: ");
		opt=getche()-48;
		if ((!opt)||(opt>7))
		{
			printf("\n\rOptiunea introdusa nu este valida!");
			delay(1000);
			printf("\r"); clreol();
			gotoxy(1, wherey()-1);
		}
	} while ((!opt)||(opt>7));

	switch (opt)
	{
		case 1:
		{
			def_mar(0);
			return 1;
		}
		case 2:
		{
			if ((!marx)||(!mary))
			{
				printf("\n\rIntroduceti marimile matricei mai intai!");
				delay(1000);
				return 1;
			}
			mf=citire_m(mat);
			return 1;
		}
		case 3:
		{
			if (!mf)
			{
				printf("\n\rIntroduceti matricea mai intai!");
				delay(1000);
				return 1;
			}
			printf("\n\r\n\r");
			afisare_m(*mat);
			getch();
			return 1;
		}
		case 4:
		{
			if (!mf)
			{
				printf("\n\rIntroduceti matricea mai intai!");
				delay(1000);
				return 1;
			}
			do {} while (meniu_2(mat));
			return 1;
		}
		case 5:
		{
			if (!mf)
			{
				printf("\n\rIntroduceti matricea mai intai!");
				delay(1000);
				return 1;
			}
			do {} while (inter_c(mat));
			return 1;
		}
		case 6:
		{
			if (!mf)
			{
				printf("\n\rIntroduceti matricea mai intai!");
				delay(1000);
				return 1;
			}
			printf("\n\r\n\r  Suma este: %d", suma_m(*mat));
			getch();
			return 1;
		}
		case 7:
		default: return 0;
	};
}

int main()
{
	int m[50][50];

	do {} while (meniu_1(&m));

	return 0;
}