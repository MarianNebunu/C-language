#include "Ech_IT_Imprimanta.h"

  	int static AddTipImprimanta(); 
	void static PrintData(Data data);
	int static SetStareEch(void);
	void static PrintStareEch(int Stare);
    int static AddTipDimensiuneHartie();
  	void PrintTipDimensiuneHartie(int TipHartie);
  
  
  void MainImprimanta(void)
  {

	Imprimanta HP[3];
	int index;
	
 
	 
  }

  void AddImprimanta(Imprimanta *Printer)
  { 
   
	printf("Introduceti date despre imprimanta:\nNumar de inventar: ");
	scanf("%d", &Printer->numarDeInventar);
	
	printf("Data Achizitie: ");
	AddData(&Printer->dataAchizitie);

	printf("Termen de garantie, ani: ");
	scanf("%d", &Printer->termenGarantieAni);

	printf("Stare echipament:\nIntroduceti \n-1 daca echipamentul este functional\n-2 daca echipamentul este defect:\n");
	Printer->stareEchipament = SetStareEch();
	
	fflush(stdin);
	
	printf("Introduceti numele producatorului: ");
	gets(Printer->numeProducator);
	 
	Printer->tipImprimanta = AddTipImprimanta();
	
 	Printer->tipDimensiuneHartie = AddTipDimensiuneHartie();
 	
 	printf("Introduceti rezolutia dpi: ");
	scanf("%d", &Printer->rezolutie);
	  	
  }
  
 void AfisareImprimanta(Imprimanta Printer)
{
  	
	printf("\nAfisare Date imprimanta\n\nNumar inventar: %d\n", Printer.numarDeInventar);

	PrintData(Printer.dataAchizitie);

	printf("%d ani de garantie\n", Printer.termenGarantieAni);
  	 
	PrintStareEch(Printer.stareEchipament);
	
	printf("Numele producatorului este: ");
	puts(Printer.numeProducator);
	
	PrintTipDimensiuneHartie(Printer.tipDimensiuneHartie);
	printf("%d rezolutie", Printer.rezolutie);
}
  
int AddTipDimensiuneHartie()
{
	int optiune, returnValue;
	printf("\nIntroduceti dimensiunea hartiei:");
	printf("\n0. -A3\n1. -A4\n");

	do
	{
		scanf("%d", &optiune);
		
		switch(optiune)
		{
			case A3: 
			{
				returnValue = A3;
				break;
			}
			case A4: 
			{
				returnValue = A4;
				break;
			}
			default:
			 {
			 	system("cls");
			 	printf("Optiune gresita, introduceti din nou!!!");
				optiune = NO_EXIT;
				break;
			}
		}
	} while(optiune == NO_EXIT);

	return returnValue;
}
 
 void PrintTipDimensiuneHartie(int TipHartie)
{

	switch(TipHartie)
	{
		case A3: 
		{
			printf("Dimensiune A3\n");
			break;
		}
		case A4: 
		{
			printf("Dimensiune A4\n");
			break;
		}
		default:
		{
			printf("Dimensiune eronata\n");
			break;
		}
	}
 
}
 
int AddTipImprimanta()
{
	int optiune, returnValue;
	printf("\nIntroduceti tipul imprimantei:");
	printf("\n0. -Imprimanta cu cerneala\n1. -Imprimanta cu laser\n2. -Imprimanta matriceala");
	
	do
	{
		scanf("%d", &optiune);
		switch(optiune)
		{
			case CERNEALA: 
			{
				returnValue = CERNEALA; 
				break;
			}	
			case LASER:
			{
				returnValue = LASER;
				break;
			}
			case MATRICEALA: 
			{
				returnValue = MATRICEALA;
				break;
			}
			default :
			{
				optiune = NO_EXIT;
				printf("Optiunea gresita!!!");
				break;
			}
				
		}	
	} while(optiune == NO_EXIT);
	
return returnValue;
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
 


