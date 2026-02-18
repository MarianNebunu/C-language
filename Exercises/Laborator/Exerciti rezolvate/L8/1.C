#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

#define p5ct 1.72048
#define p6ct 2.59807
#define gtor 0.0174533

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

double triunghi(void)
{
	unsigned a, b, c;
	double p;

	clrscr();
	printf("\n\rIntroduceti laturile triunghiului: ");
	printf("\n\r  a="); scanf("%u", &a);
	printf("  b="); scanf("%u", &b);
	printf("  c="); scanf("%u", &c);

	p=((double)a+(double)b+(double)c)/2;

	if ((a>p)||(b>p)||(c>p))
	{
		printf("Laturile nu formeaza un triunghi!");
		getch();
		return 0;
	}

	return sqrt(p*(p-a)*(p-b)*(p-c));
}

unsigned patrat(void)
{
	unsigned a, b;

	clrscr();
	printf("\n\rIntroduceti lungimea si latimea: ");
	printf("\n\r  L="); scanf("%u", &a);
	printf("  l="); scanf("%u", &b);

	return (a*b);
}

double paralelogram(void)
{
	unsigned a, b, u;
	double ur;

	clrscr();
	printf("\n\rIntroduceti laturile si unghiul ascutit (in grade): ");
	printf("\n\r  L="); scanf("%u", &a);
	printf("  l="); scanf("%u", &b);
	do
	{
		printf("  u=");
		scanf("%u", &u);
	} while (u>90);

	ur=((double)u)*gtor;
	return (a*b*sin(ur));
}

double trapez(void)
{
	unsigned l1, l2, l3, l4;
	unsigned aux;
	double p;

	clrscr();
	printf("\n\rIntroduceti laturile trapezului: ");
	printf("\n\rLaturile paralele:");
	printf("\n\r  L="); scanf("%u", &l3);
	printf("  l="); scanf("%u", &l1);
	printf("\n\rLaturile inclinate:");
	printf("\n\r  l1="); scanf("%u", &l4);
	printf("  l2="); scanf("%u", &l2);

	if (l1==l3)
	{
		if (l2!=l4)
		{
			printf("Laturile introduse nu reprezinta un trapez!");
			getch();
			return 0;
		}
		else return (l1*l2);
	}
	aux=abs((int)l1-(int)l3);
	p=((double)(l4+l2+aux))/2;
	if ((p<l4)||(p<l2)||(p<aux))
	{
		printf("Laturile introduse nu reprezinta un trapez!");
		getch();
		return 0;
	}
	return (((l1+l3)-aux)*(p*(p-l4)*(p-l2)*(p-aux)))/aux;
}

double cerc(void)
{
	unsigned r;

	clrscr();
	printf("\n\rIntroduceti raza cercului: ");
	printf("\n\r  r="); scanf("%u", &r);

	return (M_PI*(double)pow(r, 2));
}

double pentagon(void)
{
	unsigned l;

	clrscr();
	printf("\n\rIntroduceti lungimea laturii: ");
	printf("\n\r  l="); scanf("%u", &l);

	return (pow(((double)l), 2)*p5ct);
}

double hexagon(void)
{
	unsigned l;

	clrscr();
	printf("\n\rIntroduceti lungimea laturii: ");
	printf("\n\r  l="); scanf("%u", &l);

	return (pow(((double)l), 2)*p6ct);
}

int meniu(void)
{
	const char men[8][80]={	"Triunghi",
				"Dreptunghi",
				"Paralelogram",
				"Trapez",
				"Pentagon regulat",
				"Hexagon regulat",
				"Cerc",
				"Iesire" };
	unsigned ttl;

	ttl=0;
	do
	{
		switch (meniu_core(men, 8))
		{
			case 1:
			{
				printf("\n\rAria este: %7.3lf", triunghi());
				getch();
			} break;
			case 2:
			{
				printf("\n\rAria este: %5u", patrat());
				getch();
			} break;
			case 3:
			{
				printf("\n\rAria este: %7.3lf", paralelogram());
				getch();
			} break;
			case 4:
			{
				printf("\n\rAria este: %7.3lf", trapez());
				getch();
			} break;
			case 5:
			{
				printf("\n\rAria este: %7.3lf", pentagon());
				getch();
			} break;
			case 6:
			{
				printf("\n\rAria este: %7.3lf", hexagon());
				getch();
			} break;
			case 7:
			{
				printf("\n\rAria este: %7.3lf", cerc());
				getch();
			} break;
			case 8:
			default: ttl=1;
		};
	} while (!ttl);
	return 0;
}

int main()
{
	return meniu();
}