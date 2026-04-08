#include "Ech_IT_Monitor.h"

static int AddTipMonitor(void);
static void PrintTipMonitor(int tipMonitor);

void MainMonitor(void)
{
	
	 Monitor masc;
	 
	 AddMonitor(&masc);
	 AfisareMonitor(masc);
}



void AddMonitor(Monitor *monitor)
{
	printf("Introduceti date despre monitor:\nNumar de inventar: ");
	scanf("%d", &monitor->numarDeInventar);
	
	printf("Introduceti diagonala monitorului in inch: ");
	scanf("%d", &monitor->diagonalaInch);
	
	fflush(stdin);
	
	printf("Introduceti numele producatorului: ");
	gets(monitor->numeProducator);
	
	monitor->tipMonitor = AddTipMonitor();
	
	printf("Introduceti timpul de raspuns al monitorului: ");
	scanf("%d", &monitor->timpDeRaspunsMs);
	
}



void AfisareMonitor(Monitor monitor)
{
	printf("\nNumar de inventar monitor este %d\n", monitor.numarDeInventar);
	
	printf("Diagonala monitor: %d inch\n", monitor.diagonalaInch);
	
	printf("Numele producatorului este: ");
	puts(monitor.numeProducator);
	
	PrintTipMonitor(monitor.tipMonitor);
	
	printf("Timpul de raspuns este: %d ms\n", monitor.timpDeRaspunsMs);
}

int AddTipMonitor(void)
{
	int optiune, returnValue;
	printf("Adaugati tip monitor:\n0 -CRT\n1 -LCD\n");
	do
	{
		scanf("%d", &optiune);
		switch(optiune)
		{
			case CRT: 
			{
				returnValue = CRT;
				break;
			}
			case LCD: 
			{
				returnValue = LCD;
				break;
			}
			default:
			{
				optiune = NO_EXIT;
				printf("Optiune gresita, introduceti din nou!!!\n");
				break;
			}
		}
	} while(optiune == NO_EXIT);
	
 return returnValue;
}

void PrintTipMonitor(int tipMonitor)
{ 
	 
	switch(tipMonitor)
	{
		case CRT: 
		{
			printf("Tip monitor este: CRT\n");
			break;
		}
		case LCD: 
		{
			printf("Tip monitor este: LCD\n");
			break;
		}
		default:
		{
		 	printf("Exita o greseala undeva!!!\n");
			break;
		}
	}
 
}





