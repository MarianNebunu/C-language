#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct {
	int varsta;
	char nume[20];
} student;

int eroare(int x)
{
	switch (x)
	{
		case 1: printf("Fisierul sursa nu exista sau nu poate fi accesat!"); break;
		case 2: printf("Fisierul destinatie nu poate fi creat!"); break;
		default: printf("Eroare generica!");
	}
	getch();
	return 0;
}

int main()
{
	FILE * fis1, * fis2;
	char Nume[20];
	unsigned x;
	student s;

	clrscr();

	fis1=fopen("EX_BINAR.BIN", "r");
	if (!fis1) return eroare(1);
	fis2=fopen("temp.$$$", "w");
	if (!fis2) return eroare(2);
	Nume[0]='\0';
	printf("Introduceti numele studentului: "); gets(Nume);
	x=0;
	while (fread(&s, sizeof(student), 1, fis1))
	{
		if (strcmpi(s.nume, Nume)) fwrite(&s, sizeof(student), 1, fis2);
		else x=1;
	}
	fclose(fis1);
	fclose(fis2);
	remove("EX_BINAR.BIN");
	rename("temp.$$$", "EX_BINAR.BIN");
	if (x) printf("Studentul a fost sters!");
	else printf("Studentul nu a fost gasit!");
	getch();
	return 0;
}