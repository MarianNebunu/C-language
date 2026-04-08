#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "4_TYPES.C"

int eroare(int x)
{
	switch (x)
	{
		case 1: printf("Fisierul 'AGENDA.BIN' nu exista sau nu poate fi accesat!"); break;
		case 2: printf("Fisierul 'DEPOZIT.BIN' nu exista sau nu poate fi accesat!"); break;
		case 3: printf("Fisierul 'COMENZI.BIN' nu exista sau nu poate fi accesat!"); break;
		case 4: printf("Fisierul 'RASP.TXT' nu poate fi creat!"); break;
		case 5: printf("Fisierul temporar nu poate fi creat!"); break;
		default: printf("Eroare generica!");
	}
	getch();
	return 0;
}

int main()
{
	FILE * fis[3], * rez, * tmp;
	AGENDA a;
	DEPOZIT d;
	COMENZI c;
	unsigned i, j;
	char linie[100];
	const char nmfis[3][100]={"AGENDA.BIN",
				"DEPOZIT.BIN",
				"COMENZI.BIN", };

	clrscr();

	for (i=0; i<3; i++)
	{
		fis[i]=fopen(nmfis[i], "rb");
		if (!fis[i])
		{
			for (j=0; j<i; j++) fclose(fis[j]);
			return eroare(i+1);
		}
	}

	rez=fopen("RASP.TXT", "wt");
	if (!rez)
	{
		for (j=0; j<3; j++) fclose(fis[j]);
		return eroare(4);
	}

	while (fread(&c, sizeof(COMENZI), 1, fis[2]))
	{
		fseek(fis[0], 0, 0);
		while (fread(&a, sizeof(AGENDA), 1, fis[0]))
		{
			if (!strcmpi(c.Nume, a.Nume))
			{
				sprintf(linie, "%30s -> ", c.Nume);
				fwrite(linie, sizeof(char), strlen(linie), rez);
				tmp=fopen("temp.$$$", "w");
				if (!tmp)
				{
					for (j=0; j<3; j++) fclose(fis[j]);
					fclose(rez);
					return eroare(5);
				}
				i=0;
				while (fread(&d, sizeof(DEPOZIT), 1, fis[1]))
				{
					if (!strcmpi(c.Produs, d.Produs))
					{
						if (d.NrBuc)
						{
							if (d.NrBuc<c.Cantitate)
							{
								sprintf(linie, "Produsul %s exista pe stoc in numar de %u bucati si costa %6.2lf LEI / Buc\n", d.Produs, d.NrBuc, d.Pret);
								d.NrBuc=0;
							}
							else
							{
								sprintf(linie, "Produsul %s exista pe stoc si costa %6.2lf LEI / Buc\n", d.Produs, d.Pret);
								d.NrBuc-=c.Cantitate;
							}
						}
						else sprintf(linie, "Produsul %s nu exista pe stoc\n", d.Produs);
						i=1;
					}
					fwrite(&d, sizeof(DEPOZIT), 1, tmp);
				}
				if (!i) sprintf(linie, "Nu comercializam produsul %s\n", c.Produs);
				fclose(tmp);
				fclose(fis[1]);
				remove(nmfis[1]);
				rename("temp.$$$", nmfis[1]);
				fis[1]=fopen(nmfis[1], "rb");
				fwrite(linie, sizeof(char), strlen(linie), rez);
			}
		}
	}
	for (i=0; i<3; i++) fclose(fis[i]);
	fclose(rez);

	return 0;
}