#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
	char sir[256];
	unsigned i, x;

	clrscr();

	printf("Introduceti cuvantul: ");
	scanf("%s", sir);
	fflush(stdin);

	x=0;
	for (i=0; i<(strlen(sir)/2); i++)
		if (sir[i]!=sir[strlen(sir)-i-1]) x=1;

	printf("Cuvantul '%s'", sir);
	if (x) printf(" nu");
	printf(" este palindrom");

	getch();
	return 0;
}