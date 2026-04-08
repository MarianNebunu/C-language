#include "AlgoritmProiect1.h"

typedef struct indexEchIT{
	int IndexMonitor;
    int IndexImprimanta;
	int IndexCalculator;
} IndexEch;

IndexEch Index = {0, 0, 0};
 
// Declararae functii statice
static int Meniu(void);
static int MainAlgoritm(int Optiune);
static void CautareEchNrInventar(int numarInv);	
static void ModificareStareEch(int numarInv);	
static void AfisareEchDefecte(Data data);
static void StergereEchDupaNrInventar(int numarInv);

// Declararea variabilelor globale private
static Monitor    monitor[DIM_MONITOR];
static Imprimanta imprimanta[DIM_IMPRIMANTA];
static Calculator calculator[DIM_CALCULATOR];

 

int MainAlgoritmProiect1(void)
{
	

	 
	while(1)
    MainAlgoritm(Meniu());
}


int Meniu(void)
{
	int Opt;
	
	do 
	{
		printf("\n\t\tMeniu\n");
		printf("1. Adaugati echipamente IT\n");
		printf("2. Afisati toate echipamentele existente\n");
		printf("3. Cautarea unui echipament dupa numarul de inventar\n");
		printf("4. Afisarea echipamentelor defecte cu termenul de garantie nedepasit de o anumita data introdusa de la tastaturan\n");
		printf("5. Modificarea starii unui echipament, al carui nume de inventar este introdus de la tastatura\n");
		printf("6. Afisarea celui mai performant caculator\n");
		printf("7. Stergerea unui echipament, dupa numele de inventar\n\n");
		printf("Introduceti optiunea dumneavoastra: ");
		scanf("%d", &Opt);
		if(Opt < 1 || Opt > 7)
		{
			Opt = NO_EXIT;
			system("cls");
			printf("Optiunea este gresita, introduceti din nou!!!\n");
		}		
	} while(Opt == NO_EXIT);

	return Opt;
}

int MainAlgoritm(int Optiune)
{
	int Opt;
	
	switch(Optiune)
		{
			case 1: 
			{
				do
				{
  					printf ("Apasati:\n\t1. pentru monitor\n\t2. pentru imprimanta\n\t3. pentru calculator\n");
					scanf("%d", &Opt);
		
					switch(Opt)
					{
						case 1: 
						{
							AddMonitor(&monitor[Index.IndexMonitor++]);
							break;
						}
						case 2: 
						{
							AddImprimanta(&imprimanta[Index.IndexImprimanta++]);
							break;
						}
						case 3: 
						{
							AddCalculator(&calculator[Index.IndexCalculator++]);
							break;
						}
						default :
						{
							Opt = NO_EXIT;
							system("cls");

							printf("Optiune gresita!!!");
							break;
						}	
					}
				} while(Opt == NO_EXIT);
			
				break;
			}
			case 2: 
			{
				int Index1;
				
				printf("Sunt %d monitoare in stoc:\n", Index.IndexMonitor);	
				printf("Sunt %d imprimante in stoc:\n", Index.IndexImprimanta);
				printf("Sunt %d calculatoare in stoc:\n", Index.IndexCalculator);
				
				for(Index1 = 0; Index1 < Index.IndexMonitor; Index1++)
				{
					AfisareMonitor(monitor[Index1]);
				}				
				
			
				for(Index1 = 0; Index1 < Index.IndexImprimanta; Index1++)
				{
					AfisareImprimanta(imprimanta[Index1]);
				}
				
				for(Index1 = 0; Index1 < Index.IndexCalculator; Index1++)
				{
					AfisareCalculator(calculator[Index1]);
				}
		
				printf("\n\napasati o tasta pentru a continua.");
	
				getch();
				system("cls");

				break;
			}
			case 3: 
			{
				int numarInv;
				puts("Introduceti numarul de inventar pentru echipamentul pe care il cautati:");
				scanf("%d", &numarInv);
				CautareEchNrInventar(numarInv);
				
				printf("\n\napasati o tasta pentru a continua.");
	
				getch();
				system("cls");

				break;
			}
			case 4: 
			{
				Data data;
				printf("Introduceti data limita pentru echipamentele defecte:\n");
				AddData(&data);
				
				AfisareEchDefecte(data);
				printf("\n\napasati o tasta pentru a continua.");
	
				getch();
				system("cls");

				
				break;
			}
			case 5: 
			{
				int numarInv;
				
				puts("Introduceti numarul de inventar pentru echipamentul pe care il cautati, pentru a modifica starea:");
				scanf("%d", &numarInv);
				
			ModificareStareEch(numarInv);
				break;
			}
			case 6: 
			{
				int Index1, index2 = 0;;
				float PerformantaPC = 0.0;
				
			 	for(Index1 = 0; Index1 < Index.IndexCalculator; Index1++)
				{
					if(PerformantaPC > calculator[Index1].PerformantaPC)
					{
						PerformantaPC = calculator[Index1].PerformantaPC;
						index2 = Index1;
					}	
				}
				printf("Cel mai performat Pc este:\n");
				AfisareCalculator(calculator[index2]);
				
				printf("\n\napasati o tasta pentru a continua.");
	
				getch();
				system("cls");

				break;
			}
			case 7: 
			{
				int numarInv;
				puts("Introduceti numarul de inventar pentru echipamentul pe care il cautati:");
				scanf("%d", &numarInv);
				StergereEchDupaNrInventar(numarInv);
				break;
			}
			default:
			{
				printf("Undeva este o greseala!!!!");
				exit(1);
				break;
			}
		}  
		
}

void CautareEchNrInventar(int numarInv)
{
	int Index1;
			
	for(Index1 = 0; Index1 < Index.IndexMonitor; Index1++)
	{
		if(numarInv == monitor[Index1].numarDeInventar)
		{
			AfisareMonitor(monitor[Index1]);
		}
	}				
	 
	for(Index1 = 0; Index1 < Index.IndexImprimanta; Index1++)
	{
		if(numarInv == imprimanta[Index1].numarDeInventar)
		{
			AfisareImprimanta(imprimanta[Index1]);	
		}	
	}
	
 	for(Index1 = 0; Index1 < Index.IndexCalculator; Index1++)
	{
		if(numarInv == calculator[Index1].NumarDeInventar)
		{
			AfisareCalculator(calculator[Index1]);
		}	
	}
}

void ModificareStareEch(int numarInv)
{
	int Index1;
	 
	for(Index1 = 0; Index1 < Index.IndexImprimanta; Index1++)
	{
		if(numarInv == imprimanta[Index1].numarDeInventar)
		{
			 if(imprimanta[Index1].stareEchipament == FUNCTIONAL)
			 {
			 	imprimanta[Index1].stareEchipament = DEFECT;
			 }
			 else
			 {
			 	imprimanta[Index1].stareEchipament = FUNCTIONAL;
			 }
		}	
	}
	
 	for(Index1 = 0; Index1 < Index.IndexCalculator; Index1++)
	{
		if(numarInv == calculator[Index1].NumarDeInventar)
		{
			 if(calculator[Index1].StareEchipament == FUNCTIONAL)
			 {
			 	calculator[Index1].StareEchipament = DEFECT;
			 }
			 else
			 {
			 	calculator[Index1].StareEchipament = FUNCTIONAL;
			 }
		}	
	}
}

void AfisareEchDefecte(Data data)
{
	int Index1;
			
	for(Index1 = 0; Index1 < Index.IndexImprimanta; Index1++)
	{
		if(DEFECT == imprimanta[Index1].stareEchipament)
		{
			if(imprimanta[Index1].dataAchizitie.zi <= data.zi && imprimanta[Index1].dataAchizitie.luna <= data.luna && imprimanta[Index1].dataAchizitie.an <= data.an)
			{
				AfisareImprimanta(imprimanta[Index1]);	
			}
		
		}	
	}
	
 	for(Index1 = 0; Index1 < Index.IndexCalculator; Index1++)
	{
		if(DEFECT == calculator[Index1].StareEchipament)
		{
			if(calculator[Index1].DataAchizitie.zi <= data.zi && calculator[Index1].DataAchizitie.luna <= data.luna && calculator[Index1].DataAchizitie.an <= data.an)
			{
				AfisareCalculator(calculator[Index1]);	
			}
		}	
	}
}

void StergereEchDupaNrInventar(int numarInv)
{
	int Index1;
			
	for(Index1 = 0; Index1 < Index.IndexMonitor; Index1++)
	{
		if(numarInv == monitor[Index1].numarDeInventar)
		{
			int index = Index1;
			
			for(; index < Index.IndexMonitor; index++)
			{
				monitor[index] = monitor[index+1];
			}
			Index.IndexMonitor--;			
		}
	}				
	 
	for(Index1 = 0; Index1 < Index.IndexImprimanta; Index1++)
	{
		if(numarInv == imprimanta[Index1].numarDeInventar)
		{
			int index = Index1;
			
			for(; index < Index.IndexImprimanta; index++)
			{
				imprimanta[index] = imprimanta[index+1];
			}
			Index.IndexImprimanta--;
		}	
	}
	
 	for(Index1 = 0; Index1 < Index.IndexCalculator; Index1++)
	{
		if(numarInv == calculator[Index1].NumarDeInventar)
		{
			int index = Index1;
			
			for(; index < Index.IndexCalculator; index++)
			{
				calculator[index] = calculator[index+1];
			}
			Index.IndexCalculator--;
		}	
	}
}

