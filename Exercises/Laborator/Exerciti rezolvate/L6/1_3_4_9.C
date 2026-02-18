#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <math.h>

unsigned i, j, k;

int init_m(int (* mat)[50][50])
{
	for (i=0; i<50; i++)
		for (j=0; j<50; j++) (* mat)[i][j]=0;
	return 1;
}

int init_mu(double (* mat)[50][50])
{
	if (!mat) return 0;
	for (i=0; i<50; i++)
		for (j=0; j<50; j++)
		{
			if (i==j) (* mat)[i][j]=1;
			else (* mat)[i][j]=0;
		}
	return 1;
}

int citire_m(int (* mat)[50][50], unsigned mar)
{
	if (!mat) return 0;
	clrscr();
	for (i=0; i<mar; i++)
		for (j=0; j<mar; j++)
		{
			printf("m[%d][%d]=", i, j);
			scanf("%d", &((* mat)[i][j]));
		}
	return 1;
}

int afisare_m(int mat[50][50], unsigned mar)
{
	gotoxy(1, wherey());
	for (i=0; i<mar; i++)
	{
		for (j=0; j<mar; j++) printf(" %5d", mat[i][j]);
		printf("\n\r\n\r");
	}
	return 1;
}

int afisare_md(double mat[50][50], unsigned mar)
{
	gotoxy(1, wherey());
	for (i=0; i<mar; i++)
	{
		for (j=0; j<mar; j++) printf(" %9.3lf", mat[i][j]);
		printf("\n\r\n\r");
	}
	return 1;
}

int suma_m(int mat1[50][50], int mat2[50][50], int (* rez)[50][50], unsigned mar)
{
	if (!rez) return 0;
	init_m(rez);
	for (i=0; i<mar; i++)
		for (j=0; j<mar; j++) (*rez)[i][j]=mat1[i][j]+mat2[i][j];
	return 1;
}

int produs_m(int mat1[50][50], int mat2[50][50], int (* rez)[50][50], unsigned mar)
{
	if (!rez) return 0;
	init_m(rez);
	for (i=0; i<mar; i++)
		for (j=0; j<mar; j++)
			for (k=0; k<mar; k++) (* rez)[i][j]+=(mat1[i][k]*mat2[k][j]);
	return 1;				
}

int det_m(int mat[50][50], unsigned mar)
{
	int rv;
	int minor[50][50];
	unsigned ip;
	if (mar<=2) return ((mat[0][0]*mat[1][1])-(mat[0][1]*mat[1][0]));
	else
	{
		rv=0;
		for (i=0; i<mar; i++)
		{
			for (j=0; j<(mar-1); j++)
			{
				ip=0;
				for (k=0; k<mar; k++)
				{
					if (k!=i)
					{
						minor[j][ip]=mat[j+1][k];
						ip++;
					}
				}
			}
			rv+=(pow(-1, i)*mat[0][i]*det_m(minor, mar-1));
		}
	}
	return rv;
}

int inversa_m(double mat[50][50], double (* rez)[50][50], unsigned mar)
{
	double piv, val1;
	if (!rez) return 0;
	init_mu(rez);
	for (i=0; i<mar; i++)
	{
		piv=mat[i][i];
		for (j=0; j<mar; j++)
		{
			mat[i][j]=mat[i][j]/piv;
			(* rez)[i][j]=(* rez)[i][j]/piv;
		}
		for (j=0; j<mar; j++)
		{
			if (i!=j)
			{
				val1=mat[j][i];
				for (k=0; k<mar; k++)
				{
					mat[j][k]=mat[j][k]-(mat[i][k]*val1);
					(* rez)[j][k]=(* rez)[j][k]-((* rez)[i][k]*val1);
				}
			}
		}
	}
	return 1;
}

int dif_dp_ds(int mat[50][50], unsigned mar)
{
	int d;
	d=0;
	for (i=0; i<mar; i++) d+=(mat[i][i]-mat[i][mar-i-1]);
	return d;
}

int main()
{
	unsigned n=0, m1f=0, m2f=0, o, o1, gata=0, gata2;
	int m1[50][50], m2[50][50], s[50][50], p[50][50];
	double mu[50][50], aux[50][50];

	init_m(&m1);
	init_m(&m2);

	do
	{
		clrscr();
		printf("1 - Introducere marime matrice\n\r");
		printf("2 - Introducere matrice\n\r");
		printf("3 - Afisare\n\r");
		printf("4 - Iesire\n\r");

		printf("\n\r");
		do
		{
			clreol();
			printf("Optiunea dvs: ");
			o=getche()-48;
			if ((o<1)||(o>4))
			{
				printf(" Optiunea introdusa nu este valida!");
				delay(1000);
				gotoxy(1, wherey());
			}
		} while ((o<1)||(o>4));

		switch (o)
		{
			case 1:
			{
				do
				{
					clrscr();
					printf("Introduceti marimea matricelor: ");
					scanf("%u", &n);
				} while (n>50);
			} break;
			case 2:
			{
				if (!n)
				{
					printf("\n\r\n\rIntroduceti marimea matricii mai intai!");
					delay(1000);
				}
				else
				{
					clrscr();
					printf("1 - Matricea 1\n\r");
					printf("2 - Matricea 2\n\r");
					printf("3 - Inapoi\n\r");

					printf("\n\r");
					do
					{
						clreol();
						printf("Optiunea dvs: ");
						o1=getche()-48;
						if ((o1<1)||(o1>3))
						{
							printf("\n\r\n\rOptiunea introdusa nu este valida!");
							delay(1000);
							gotoxy(1, wherey());
							clreol();
							gotoxy(1, wherey()-2);
						}
					} while ((o1<1)||(o1>3));

					switch (o1)
					{
						case 1: if (citire_m(&m1, n)) m1f=1; break;
						case 2: if (citire_m(&m2, n)) m2f=1; break;
						case 3:
						default: break;
					};
				}
			} break;
			case 3:
			{
				if (!m1f&&!m2f)
				{
					printf("\n\r\n\rIntroduceti o matrice mai intai!");
					delay(1000);
				}
				else
				{
					gata2=0;
					do
					{
						clrscr();
						printf("1 - Matricea 1\n\r");
						printf("2 - Matricea 2\n\r");
						printf("3 - Suma celor doua matrici\n\r");
						printf("4 - Produsul m1 X m2\n\r");
						printf("5 - Produsul m2 X m1\n\r");
						printf("6 - Determinantul lui m1\n\r");
						printf("7 - Determinantul lui m2\n\r");
						printf("8 - Inversa lui m1\n\r");
						printf("9 - Inversa lui m2\n\r");
						printf("0 - Diferenta dintre suma pe diagonala principala si suma pe cea secundara m1\n\r");
						printf(": - Inapoi\n\r");

						printf("\n\r");
						do
						{
							clreol();
							printf("Optiunea dvs: ");
							o1=getche()-48;
							if (o1>10)
							{
								printf("\n\r\n\rOptiunea introdusa nu este valida!");
								delay(1000);
								gotoxy(1, wherey());
								clreol();
								gotoxy(1, wherey()-2);
							}
						} while (o1>10);

						printf("\n\r\n\r");

						switch (o1)
						{
							case 1:
							{
								if (!m1f)
								{
									printf("Introduceti matricea mai intai!");
									delay(1000);
								}
								else
								{
									afisare_m(m1, n);
									getch();
								}
							} break;
							case 2:
							{
								if (!m2f)
								{
									printf("Introduceti matricea mai intai!");
									delay(1000);
								}
								else
								{
									afisare_m(m2, n);
									getch();
								}
							} break;
							case 3:
							{
								if ((!m1f)||(!m2f))
								{
									printf("Introduceti ambele matrici mai intai!");
									delay(1000);
								}
								else
								{
									if (suma_m(m1, m2, &s, n)) afisare_m(s, n);
									getch();
								}
							} break;
							case 4:
							{
								if ((!m1f)||(!m2f))
								{
									printf("Introduceti ambele matrici mai intai!");
									delay(1000);
								}
								else
								{
									if (produs_m(m1, m2, &p, n)) afisare_m(p, n);
									getch();
								}
							} break;
							case 5:
							{
								if ((!m1f)||(!m2f))
								{
									printf("Introduceti ambele matrici mai intai!");
									delay(1000);
								}
								else
								{
									if (produs_m(m2, m1, &p, n)) afisare_m(p, n);
									getch();
								}
							} break;
							case 6:
							{
								if (!m1f)
								{
									printf("Introduceti matricea mai intai!");
									delay(1000);
								}
								else
								{
									printf("Determinantul este %d", det_m(m1, n));
									getch();
								}
							} break;
							case 7:
							{
								if (!m2f)
								{
									printf("Introduceti matricea mai intai!");
									delay(1000);
								}
								else
								{
									printf("Determinantul este %d", det_m(m2, n));
									getch();
								}
							} break;
							case 8:
							{
								if (!m1f)
								{
									printf("Introduceti matricea mai intai!");
									delay(1000);
								}
								else
								{
									if (det_m(m1, n))
									{
										for (i=0; i<n; i++)
											for (j=0; j<n; j++) aux[i][j]=(double)m1[i][j];
										if (inversa_m(aux, &mu, n)) afisare_md(mu, n);
										getch();
									}
									else
									{
										printf("Matricea nu este inversabila!");
										delay(1000);
									}
								}
							} break;
							case 9:
							{
								if (!m2f)
								{
									printf("Introduceti matricea mai intai!");
									delay(1000);
								}
								else
								{
									if (det_m(m2, n))
									{
										for (i=0; i<n; i++)
											for (j=0; j<n; j++) aux[i][j]=(double)m2[i][j];
										if (inversa_m(aux, &mu, n)) afisare_md(mu, n);
										getch();
									}
									else
									{
										printf("Matricea nu este inversabila!");
										delay(1000);
									}
								}
							} break;
							case 0:
							{
								if (!m1f)
								{
									printf("Introduceti matricea mai intai!");
									delay(1000);
								}
								else
								{
									printf("Diferenta este: %d", dif_dp_ds(m1, n));
									getch();
								}
							} break;
							case 10:
							default: gata2=1;
						};
					} while (!gata2);
				}
			} break;
			case 4:
			default: gata=1;
		};
	} while (!gata);

	return 0;
}