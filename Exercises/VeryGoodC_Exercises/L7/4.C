#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <alloc.h>

#define isalfanum(c) (((c>=48)&&(c<58))||((c>=65)&&(c<91))||((c>=97)&&(c<123)))

int main()
{
	char sir[1000], * aux;
	unsigned i, x, x_offs, max, max_offs, st;

	clrscr();

	printf("Introduceti un text: ");
	gets(sir);

	max=0;
	if (sir[0]==32) st=0;
	else
	{
		st=1;
		x=0;
		x_offs=0;
	}
	for (i=0; i<strlen(sir); i++)
	{
		if (isalfanum(sir[i])&&(!st))
		{
			st=1;
			x=0;
			x_offs=i;
		}
		if (((!isalfanum(sir[i]))&&(st))||(i==(strlen(sir)-1)))
		{
			st=0;
			if (x>max)
			{
				max=x;
				max_offs=x_offs;
			}
		}
		if (st) x++;
	}

	if (max)
	{
		aux=(char *)malloc(max*sizeof(char));
		strncpy(aux, (sir+max_offs), max);
		aux[max]='\0';
		printf("Cel mai lung cuvant este: %s", aux);
		free(aux);
	}
	else printf("Sirul este vid!");

	getch();
	return 0;
}