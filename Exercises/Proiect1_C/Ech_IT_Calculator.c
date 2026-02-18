#include "Ech_IT_Calculator.h"

void static PrintData(Data data);
int static SetStareEch(void);
void static PrintStareEch(int Stare);

void MainCalculator(void)
{
   Calculator PC_Pentium;
   
   AddCalculator(&PC_Pentium);
   AfisareCalculator(PC_Pentium);
   
}

void AddCalculator(Calculator *PC)
{ 

	printf("Introduceti date despre calculator:\nNumar de inventar: ");
	scanf("%d", &PC->NumarDeInventar);
	
	printf("Data Achizitie: ");
	AddData(&PC->DataAchizitie);

	printf("Termen de garantie, ani: ");
	scanf("%d", &PC->TermenGarantieAni);

	printf("Stare echipament:\nIntroduceti \n-1 daca echipamentul este functional\n-2 daca echipamentul este defect:\n");
	PC->StareEchipament = SetStareEch();
	
	fflush(stdin);
	
	printf("Introduceti numele producatorului: ");
	gets(PC->NumeProducator);
	
	printf("Introduceti viteza de la procesor: ");
	scanf("%d", &PC->VitezaProcesorMHz);
	
	printf("Introduceti cantitatea de meomorie RAM: ");
	scanf("%d", &PC->CantitateMbRAM);
	
	printf("Introduceti Dimensiune HDD in Gigabytes: ");
	scanf("%d", &PC->DimensiuneGbHDD);	
	
	PC->PerformantaPC = (3 * PC->VitezaProcesorMHz) + (2 * PC->CantitateMbRAM) + (1 * PC->DimensiuneGbHDD);
}
 
void AfisareCalculator(Calculator PC)
{
	printf("\nAfisare Date PC\n\nNumar inventar: %d\n", PC.NumarDeInventar);

	PrintData(PC.DataAchizitie);

	printf("%d ani de garantie\n", PC.TermenGarantieAni);
  	 
	PrintStareEch(PC.StareEchipament);
	
	printf("Numele producatorului este: ");
	puts(PC.NumeProducator);
	
	printf("Viteza procesorului este %d MHz\n", PC.VitezaProcesorMHz);
	 	
	printf("%d Gb RAM\n ", PC.CantitateMbRAM);
	 	
	printf("%d HDD Gigabytes\n ", PC.DimensiuneGbHDD); 
}



void AddData(Data *data)
{
	int Index = 1;
	
	do
	{
		printf("\nZi: ");
		scanf("%d", &data->zi);
		printf("Luna: ");
		scanf("%d", &data->luna);
		printf("An: ");
		scanf("%d", &data->an);
		
		if(data->zi > 0 && data->zi <= 31)
		{	
	   		if(data->luna > 0 && data->luna <= 12)
			{
				if(data->an > 1950 && data->an <= 2020)
				{
					Index = 0;
				}
	            if(data->luna == 2 && data->zi > 29)
		    	{
			    	Index = 1;
			    	printf("Luna februarie are maxim 29 zile");
		    	}
			}
		}
		if(Index)
		{
			puts("Data este gresita, introduceti din nou!!!");	
		}	
	} while(Index);

}

int SetStareEch(void)
{
	int optiune, stare = 22;
	
	do
	{
		scanf("%d", &optiune);
		
 		if(FUNCTIONAL == optiune)
		{
			stare = FUNCTIONAL;
		}
		else if(DEFECT == optiune)
		{
			stare = DEFECT; 
		}
		else
		{
			puts("Optiune gresita, introduceti din nou: ");
		}
	} while (stare < 1 || stare > 2);
	
	return stare;
}


void PrintData(Data data)
{
	printf("Data:\nZi: %d\nLuna: %d\nAn: %d\n", data.zi, data.luna, data.an);	
}

void PrintStareEch(int Stare)
{
	if(FUNCTIONAL == Stare)
	{
		printf("Echipament: -functional\n");
	}
	else if(DEFECT == Stare)
	{
		printf("Echipament: -defect\n");
	}
}
 






