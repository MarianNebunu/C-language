#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <alloc.h>

int ap1(char * sir)
{
	unsigned poz, len;
	char * aux;

	if (!sir) return 0;

	clrscr();
	printf("Sirul: %s", sir);

	aux=(char *)malloc(strlen(sir)*sizeof(char));

	do
	{
		printf("\n\rIntroduceti pozitia: ");
		scanf("%u", &poz);
	} while (poz>=strlen(sir));
	do
	{
		printf("\n\rIntroduceti lungimea: ");
		scanf("%u", &len);
	} while ((poz+len)>strlen(sir));

	strncpy(aux, sir, poz);
	strcpy((aux+poz), (sir+poz+len));
	strcpy(sir, aux);
	free(aux);
	return 1;
}

int ap2(char * sir)
{
	char * aux;
	char ss[100];
	unsigned poz;

	if (!sir) return 0;

	clrscr();
	printf("Sirul: %s", sir);
	printf("\n\rIntroduceti subsirul: ");
   fflush(stdin);
	gets(ss);

	do
	{
		printf("\n\rIntroduceti pozitia: ");
		scanf("%u", &poz);
	} while (poz>=strlen(sir));

	aux=(char *)malloc((strlen(sir)+strlen(ss))*sizeof(char));

	strncpy(aux, sir, poz);
	strcpy((aux+poz), ss);
	strcat(aux, (sir+poz));
	strcpy(sir, aux);
	free(aux);
	return 1;
}

int ap3(char * sir)
{
	char * aux;
	char cuv1[100], cuv2[100];
   char * offs;
   unsigned uoffs;

	if (!sir) return 0;

	clrscr();
	printf("Sirul: %s", sir);
	do
	{
		printf("\n\rIntroduceti cuvantul de inlocuit: ");
		fflush(stdin);
		gets(cuv1);
	} while (!strlen(cuv1));
	do
	{
		printf("\n\rIntroduceti cuvantul cu care se inlocuieste: ");
		fflush(stdin);
		gets(cuv2);
	} while (!strlen(cuv2));

	offs=strstr(sir, cuv1);
   uoffs=(unsigned)(offs-sir);
	while (offs)
	{
		aux=(char *)malloc(((int)strlen(sir)+((int)strlen(cuv2)-(int)strlen(cuv1)))*sizeof(char));
		strcpy(aux, sir);
      aux[uoffs]='\0';
		strcat(aux, cuv2);
		strcat(aux, offs+strlen(cuv1));
		strcpy(sir, aux);
		free(aux);
		offs=strstr(sir, cuv1);
		uoffs=(offs-sir);
	}
	return 1;
}

int meniu(char * sir)
{
	unsigned opt;

	if (!sir) return 0;


	clrscr();
	printf("Sirul: %s", sir);
	printf("\n\r  1 - Sterge un subsir specificat prin pozitie si lungime");
	printf("\n\r  2 - Insereaza incepand cu o pozitie data un alt sir");
	printf("\n\r  3 - Citeste 2 cuvinte; inlocuieste toate aparitiile I-lui cuvant cu al II-lea");
	printf("\n\r  4 - Iesire\n\r\n\r");

	do
	{
		clreol();
		printf("Optiunea dvs: ");
		opt=getche()-48;
		if ((!opt)||(opt>4))
		{
			printf("\n\rOptiunea introdusa nu este valida!");
			delay(1000);
			printf("\r"); clreol();
			gotoxy(1, wherey()-1);
		}
	} while ((!opt)||(opt>4));

	switch (opt)
	{
		case 1:
		{
			ap1(sir);
			return 1;
		}
		case 2:
		{
			ap2(sir);
			return 1;
		}
		case 3:
		{
			ap3(sir);
			return 1;
		}
		case 4:
		default: return 0;
	};
}

int main()
{
	char s[1000];

	clrscr();

	printf("Introduceti un text: ");
	gets(s);

	do {} while (meniu(s));

	return 0;
}