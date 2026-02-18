#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
	FILE * fis1, * fis2;
	char filnm[2][256], cuv[100], linie[1024];

	clrscr();

	printf("Introduceti numele fisierului sursa: "); gets(filnm[0]);
	printf("Introduceti numele fisierului destinatie: "); gets(filnm[1]);
	fis1=fopen(filnm[0], "r");
	if (!fis1)
	{
		printf("Fisierul sursa nu exista sau nu poate fi accesat!");
		getch();
		return 0;
	}
	fis2=fopen(filnm[1], "w");
	if (!fis2)
	{
		printf("Fisierul destinatie nu poate fi creat!");
		getch();
		return 0;
	}
	printf("Introduceti cuvantul: "); gets(cuv);
	while (fgets(linie, 1024, fis1))
		if (strstr(linie, cuv)) fputs(linie, fis2);

	getch();
	return 0;
}