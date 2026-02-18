#include <stdio.h>
#include <conio.h>
#include <string.h>

int eroare(int x)
{
	switch (x)
	{
		case 1: printf("Fisierul sursa nu exista sau nu poate fi accesat!"); break;
		case 2: printf("Fisierul destinatie nu poate fi creat!"); break;
		case 3: printf("Fisierul temporar nu poate fi creat!"); break;
		default: printf("Eroare generica!");
	}
	getch();
	return 0;
}

int main()
{
	FILE * fis1, * fis2, * fis3;
	char filnm[2][256], linie[1024], aux[1024];
	unsigned cnt, br;

	clrscr();

	printf("Introduceti numele fisierului sursa: "); gets(filnm[0]);
	printf("Introduceti numele fisierului destinatie: "); gets(filnm[1]);
	fis1=fopen(filnm[0], "r");
	if (!fis1) return eroare(1);
	fis2=fopen(filnm[1], "w");
	if (!fis2) return eroare(2);
	fclose(fis2);
	cnt=0;
	while (fgets(linie, 1024, fis1))
	{
		fis3=fopen("temp.$$$", "w");
		if (!fis3) return eroare(3);
		fwrite(linie, sizeof(char), strlen(linie), fis3);
		fis2=fopen(filnm[1], "r");
		if (!fis2) return eroare(2);
		do
		{
			br=fread(aux, sizeof(char), 1024, fis2);
			aux[br]='\0';
			fwrite(aux, sizeof(char), br, fis3);
		} while (br);
		cnt++;
		fclose(fis2);
		fclose(fis3);
		remove(filnm[1]);
		rename("temp.$$$", filnm[1]);
	}
	printf("Fisierul are %u linii", cnt);
	getch();
	return 0;
}