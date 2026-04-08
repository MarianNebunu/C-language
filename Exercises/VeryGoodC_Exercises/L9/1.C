#include <stdio.h>
#include <conio.h>
#include <math.h>

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

typedef struct {
	double rl;
	double im;
} nr_complex;

void citire(nr_complex * rezultat)
{
	printf("real="); scanf("%lf", &(rezultat->rl));
	printf("imag="); scanf("%lf", &(rezultat->im));
}

void afisare(nr_complex n)
{
	if (n.rl)
	{
		printf("%7.3lf", n.rl);
		if (n.im)
		{
			if (n.im>0) printf("+");
			printf("%7.3lfi", n.im);
		}
	}
	else
	{
		if (n.im) printf("%7.3lf", n.im);
		else printf("0");
	}
}

void adunare(nr_complex n1, nr_complex n2, nr_complex * rezultat)
{
	rezultat->rl=(n1.rl+n2.rl);
	rezultat->im=(n1.im+n2.im);
}

void scadere(nr_complex n1, nr_complex n2, nr_complex * rezultat)
{
	rezultat->rl=(n1.rl-n2.rl);
	rezultat->im=(n1.im-n2.im);
}

void inmultire(nr_complex n1, nr_complex n2, nr_complex * rezultat)
{
	rezultat->rl=(n1.rl*n2.rl-n1.im*n2.im);
	rezultat->im=(n1.rl*n2.im+n1.im*n2.rl);
}

double modul(nr_complex n)
{
	return sqrt(pow(n.rl, 2)+pow(n.im, 2));
}

void conjugat(nr_complex n, nr_complex * rezultat)
{
	rezultat->rl=n.rl;
	rezultat->im=-n.im;
}

int meniu(void)
{
	nr_complex a, b, r;
	const char men[6][80]={	"Suma",
				"Diferenta",
				"Produsul",
				"Modulul",
				"Conjugatul",
				"Exit" };
	unsigned ttl;

	ttl=0;
	do
	{
		switch (meniu_core(men, 6))
		{
			case 1:
			{
				printf("\n\rIntroduceti primul numar:\n\r");
				citire(&a);
				printf("\n\rIntroduceti al doilea numar:\n\r");
				citire(&b);
				adunare(a, b, &r);
				printf("Suma este: "); afisare(r);
				getch();
			} break;
			case 2:
			{
				printf("\n\rIntroduceti primul numar:\n\r");
				citire(&a);
				printf("\n\rIntroduceti al doilea numar:\n\r");
				citire(&b);
				scadere(a, b, &r);
				printf("Diferenta este: "); afisare(r);
				getch();
			} break;
			case 3:
			{
				printf("\n\rIntroduceti primul numar:\n\r");
				citire(&a);
				printf("\n\rIntroduceti al doilea numar:\n\r");
				citire(&b);
				inmultire(a, b, &r);
				printf("Produsul este: "); afisare(r);
				getch();
			} break;
			case 4:
			{
				printf("\n\rIntroduceti numarul:\n\r");
				citire(&a);
				printf("Modulul este: %7.3lf", modul(a));
				getch();
			} break;
			case 5:
			{
				printf("\n\rIntroduceti numarul:\n\r");
				citire(&a);
				conjugat(a, &r);
				printf("Conjugatul este: "); afisare(r);
				getch();
			} break;
			case 6:
			default: ttl=1;
		};
	} while (!ttl);
	return 0;
}

int main()
{
	return meniu();
}