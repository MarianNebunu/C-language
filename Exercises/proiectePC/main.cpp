#include<stdio.h>  //librarie folosita pentru scanf() si printf()
#include<stdlib.h> //librarie folosita pentru exit()
#include<conio.h>  //librarie folosita pentru getch()
#include<string.h>

//structura componentelor calculatorului
typedef struct comp {
	int nr_inv;
	char data_ac[20], so[20];
	char procesor[20];
	char memorie[20];
	char hard[20];
	char placa_baza[20];
	char placa_sunet[20];
	char placa_grafica[20];
} calculator;

//structura programelor aferente calculatoarelor
typedef struct prog {
	int nr_inv;
	char program[20];
	int ver;
} prg;

calculator c_array[50]; // initializare matrice cu elemente de tipul structurii calculator
prg p_array[50];//initializare matrice cu elemente de tipul structurii prg
//functia de stergere a unui calculator,j reprezinta numarul de calculatoare copiate in memorie
void stergerea_calculatoare(int j) {
	int nr_inv;
	int i;
	printf("Introduce-ti numarul de inventar:");
	scanf("%d\n", &nr_inv);
	for (i = 0; i < j; i++) {
		if (c_array[i].nr_inv == nr_inv) {
			c_array[i] = c_array[-1];
		}
	}flushall();
}
//functie de stergere a programelor
void stergerea_programe(int j) {
	int nr_inv;
	int i;
	char soft[50];
	printf("Introduce-ti numele:");
	scanf("%s", soft);
	for (i = 0; i < j; i++) {
		if (strcmp(p_array[i].program, soft) == 0) {
			p_array[i] = p_array[-1];
		}
	}
	flushall();//elibereaza spatiile in care s-au memorat variabile citite de la tastatura
}

//afisare a numarului de inventar,a programului si a versiuni in functie de numele programului
void afisare_programe(int j) {
	//int nr_inv;
	int i;
	char soft[50];
	int gasit = 0;
	printf("Introduce-ti numele programului:");
	scanf("%s", soft);
	for (i = 0; i <= j; i++) {
		if (strcmp(p_array[i].program, soft) == 0 && soft[50] != NULL) {
			printf("\nNr inventar este:%d\n", p_array[i].nr_inv);
			printf("\nProgramul este:%s\n", p_array[i].program);
			printf("\nVersiunea este:%d\n", p_array[i].ver);
			printf("-----------------------\n");
			gasit = 1;
		}
	}
	if (gasit == 0) {
		printf("\nNu s-a gasit pachetul soft\n");
	}
	flushall();
}

//functie de adaugare a programelor pentru un calculator selectat prin nr de inventar
int adaugare_programe(int j) {
	int n = j;
	printf("\nNr.Inventar al calculatorului:");
	scanf("%d", &p_array[n].nr_inv);
	printf("\nNume program:");
	scanf("%s", p_array[n].program);
	printf("\nVersiune(numerica):");
	scanf("%d", &p_array[n].ver);
	printf("-----------------------------\n");
	return n + 1;
}

//functie de adaugare a unui calculator
int adaugare_calculator(int j) {
	int n = j;

	printf("\nNr.Inventar:");
	scanf("%d", &c_array[n].nr_inv);
	printf("\nProcesor:");
	scanf("%s", c_array[n].procesor);
	printf("\nMemorie:");
	scanf("%s", c_array[n].memorie);
	printf("\nHard disk:");
	scanf("%s", c_array[n].hard);
	printf("\nPlaca de baza:");
	scanf("%s", c_array[n].placa_baza);
	printf("\nPlaca de sunet:");
	scanf("%s", c_array[n].placa_sunet);
	printf("\nPlaca grafica:");
	scanf("%s", c_array[n].placa_grafica);
	printf("\nData achizitiei:");
	scanf("%s", c_array[n].data_ac);
	printf("\nSistem de operare:");
	scanf("%s", c_array[n].so);
	printf("-----------------------------\n");
	return n + 1;
}

//afisarea tuturor calculatoarelor
void afisare_calculatoare(int j) {
	int i;
	for (i = 0; i < j; i++) {
		if (c_array[i].nr_inv != 0) {
			printf("Nr.Inventar:%d\n", c_array[i].nr_inv);
			printf("Procesor:%s\n", c_array[i].procesor);
			printf("Memorie:%s\n", c_array[i].memorie);
			printf("Hard disk:%s\n", c_array[i].hard);
			printf("Placa de baza:%s\n", c_array[i].placa_baza);
			printf("Placa de sunet:%s\n", c_array[i].placa_sunet);
			printf("Placa grafica:%s\n", c_array[i].placa_grafica);
			printf("Data achizitiei:%s\n", c_array[i].data_ac);
			printf("Sistem de operare:%s\n", c_array[i].so);
			printf("-----------------------------\n");
			flushall();
		}
	}
}

//afisarea calculatoarelor dupa o caracteristica a configuratiei 
void afisare_configuratie(int j) {
	int i;
	int opt2 = 28;
	char procesor[50];
	char memorie[50];
	char hard[50];
	char placa_baza[50];
	char placa_sunet[50];
	char placa_grafica[50];
	char so[50];
	while (opt2 != 0) {

		printf("Alegeti configuratia:\n");
		printf("1.Procesor:\n");
		printf("2.Memorie:\n");
		printf("3.Hard disk:\n");
		printf("4.Placa de baza:\n");
		printf("5.Placa de sunet:\n");
		printf("6.Placa grafica:\n");
		printf("7.Sistem de operare:\n");
		printf("0.Intoarcere la meniu:\n");
		scanf("%d", &opt2);
		switch (opt2) {
		case 1:
			printf("\nDenumire procesor:");
			scanf("%s", procesor);
			for (i = 0; i < j; i++) {
				if (c_array[i].nr_inv != 0
						&& strcmp(c_array[i].procesor, procesor) == 0) {
					printf("Nr.Inventar:%d\n", c_array[i].nr_inv);
					printf("Procesor:%s\n", c_array[i].procesor);
					printf("Memorie:%s\n", c_array[i].memorie);
					printf("Hard disk:%s\n", c_array[i].hard);
					printf("Placa de baza:%s\n", c_array[i].placa_baza);
					printf("Placa de sunet:%s\n", c_array[i].placa_sunet);
					printf("Placa grafica:%s\n", c_array[i].placa_grafica);
					printf("Data achizitiei:%s\n", c_array[i].data_ac);
					printf("Sistem de operare:%s\n", c_array[i].so);
					printf("-----------------------------\n");
					flushall();
				}
			}
			break;
		case 2:
			printf("\nDenumire memorie:");
			scanf("%s", memorie);
			for (i = 0; i < j; i++) {
				if (c_array[i].nr_inv != 0
						&& strcmp(c_array[i].memorie, memorie) == 0) {
					printf("Nr.Inventar:%d\n", c_array[i].nr_inv);
					printf("Procesor:%s\n", c_array[i].procesor);
					printf("Memorie:%s\n", c_array[i].memorie);
					printf("Hard disk:%s\n", c_array[i].hard);
					printf("Placa de baza:%s\n", c_array[i].placa_baza);
					printf("Placa de sunet:%s\n", c_array[i].placa_sunet);
					printf("Placa grafica:%s\n", c_array[i].placa_grafica);
					printf("Data achizitiei:%s\n", c_array[i].data_ac);
					printf("Sistem de operare:%s\n", c_array[i].so);
					printf("-----------------------------\n");
					flushall();
				}
			}
			break;
		case 3:
			printf("\nDenumire hard:");
			scanf("%s", hard);
			for (i = 0; i < j; i++) {
				if (c_array[i].nr_inv != 0
						&& strcmp(c_array[i].hard, hard) == 0) {
					printf("Nr.Inventar:%d\n", c_array[i].nr_inv);
					printf("Procesor:%s\n", c_array[i].procesor);
					printf("Memorie:%s\n", c_array[i].memorie);
					printf("Hard disk:%s\n", c_array[i].hard);
					printf("Placa de baza:%s\n", c_array[i].placa_baza);
					printf("Placa de sunet:%s\n", c_array[i].placa_sunet);
					printf("Placa grafica:%s\n", c_array[i].placa_grafica);
					printf("Data achizitiei:%s\n", c_array[i].data_ac);
					printf("Sistem de operare:%s\n", c_array[i].so);
					printf("-----------------------------\n");
					flushall();
				}
			}
			break;
		case 4:
			printf("\nDenumire placa_baza:");
			scanf("%s", placa_baza);
			for (i = 0; i < j; i++) {
				if (c_array[i].nr_inv != 0
						&& strcmp(c_array[i].placa_baza, placa_baza) == 0) {
					printf("Nr.Inventar:%d\n", c_array[i].nr_inv);
					printf("Procesor:%s\n", c_array[i].procesor);
					printf("Memorie:%s\n", c_array[i].memorie);
					printf("Hard disk:%s\n", c_array[i].hard);
					printf("Placa de baza:%s\n", c_array[i].placa_baza);
					printf("Placa de sunet:%s\n", c_array[i].placa_sunet);
					printf("Placa grafica:%s\n", c_array[i].placa_grafica);
					printf("Data achizitiei:%s\n", c_array[i].data_ac);
					printf("Sistem de operare:%s\n", c_array[i].so);
					printf("-----------------------------\n");
					flushall();
				}
			}
			break;
		case 5:
			printf("\nDenumire placa_sunet:");
			scanf("%s", placa_sunet);
			for (i = 0; i < j; i++) {
				if (c_array[i].nr_inv != 0
						&& strcmp(c_array[i].placa_sunet, placa_sunet) == 0) {
					printf("Nr.Inventar:%d\n", c_array[i].nr_inv);
					printf("Procesor:%s\n", c_array[i].procesor);
					printf("Memorie:%s\n", c_array[i].memorie);
					printf("Hard disk:%s\n", c_array[i].hard);
					printf("Placa de baza:%s\n", c_array[i].placa_baza);
					printf("Placa de sunet:%s\n", c_array[i].placa_sunet);
					printf("Placa grafica:%s\n", c_array[i].placa_grafica);
					printf("Data achizitiei:%s\n", c_array[i].data_ac);
					printf("Sistem de operare:%s\n", c_array[i].so);
					printf("-----------------------------\n");
					flushall();
				}
			}
			break;
		case 6:
			printf("\nDenumire placa_grafica:");
			scanf("%s", placa_grafica);
			for (i = 0; i < j; i++) {
				if (c_array[i].nr_inv != 0
						&& strcmp(c_array[i].placa_grafica, placa_grafica) == 0) {
					printf("Nr.Inventar:%d\n", c_array[i].nr_inv);
					printf("Procesor:%s\n", c_array[i].procesor);
					printf("Memorie:%s\n", c_array[i].memorie);
					printf("Hard disk:%s\n", c_array[i].hard);
					printf("Placa de baza:%s\n", c_array[i].placa_baza);
					printf("Placa de sunet:%s\n", c_array[i].placa_sunet);
					printf("Placa grafica:%s\n", c_array[i].placa_grafica);
					printf("Data achizitiei:%s\n", c_array[i].data_ac);
					printf("Sistem de operare:%s\n", c_array[i].so);
					printf("-----------------------------\n");
					flushall();
				}
			}
			break;
		case 7:
			printf("\nDenumire sistem operare:");
			scanf("%s", so);
			for (i = 0; i < j; i++) {
				if (c_array[i].nr_inv != 0 && strcmp(c_array[i].so, so) == 0) {
					printf("Nr.Inventar:%d\n", c_array[i].nr_inv);
					printf("Procesor:%s\n", c_array[i].procesor);
					printf("Memorie:%s\n", c_array[i].memorie);
					printf("Hard disk:%s\n", c_array[i].hard);
					printf("Placa de baza:%s\n", c_array[i].placa_baza);
					printf("Placa de sunet:%s\n", c_array[i].placa_sunet);
					printf("Placa grafica:%s\n", c_array[i].placa_grafica);
					printf("Data achizitiei:%s\n", c_array[i].data_ac);
					printf("Sistem de operare:%s\n", c_array[i].so);
					printf("-----------------------------\n");
					flushall();
				}
			}
			break;
		default:
			break;
		}
	}
}

//salvare in fisier a programelor
void salvare_programe(int j) {
	FILE *f2;//f2 este de tip file
	int nr_inv;
	char soft[20];
	int ver;
	int i;
	f2 = fopen("db2.txt", "w+");//se deschide db2.txt cu drept de scriere in f2
	for (i = 0; i < j; i++) {
		strcpy(soft, p_array[i].program);
		nr_inv = p_array[i].nr_inv;
		ver = p_array[i].ver;
		if (nr_inv != 0) {
			fprintf(f2, "%d%s%s%s%d%s", nr_inv, " ", soft, " ", ver, "\n"); //fprintf scrie in fisier
		}

	}
	fclose(f2);
}

//salveaza calculatoarele in fisier
void salvare_calculatoare(int j) {
	FILE *f1;
	int i;
	char configuratie[100];
	char data_ac[20];
	char so[20];
	int nr_inv;
	char procesor[20];
	char memorie[20];
	char hard[20];
	char placa_baza[20];
	char placa_sunet[20];
	char placa_grafica[20];
	f1 = fopen("db.txt", "w+");
	for (i = 0; i < j; i++) {
		strcpy(procesor, c_array[i].procesor);
		strcat(procesor, " ");
		strcpy(memorie, c_array[i].memorie);
		strcat(memorie, " ");
		strcpy(hard, c_array[i].hard);
		strcat(hard, " ");
		strcpy(placa_baza, c_array[i].placa_baza);
		strcat(placa_baza, " ");
		strcpy(placa_sunet, c_array[i].placa_sunet);
		strcat(placa_sunet, " ");
		strcpy(placa_grafica, c_array[i].placa_grafica);
		strcat(placa_grafica, " ");
		strcpy(data_ac, c_array[i].data_ac);
		strcat(data_ac, " ");
		strcpy(so, c_array[i].so);
		strcat(so, " ");
		nr_inv = c_array[i].nr_inv;
		if (nr_inv != 0) {
			fprintf(f1, "%d%s%s%s%s%s%s%s%s%s%s", nr_inv, " ", procesor,
					memorie, hard, placa_baza, placa_sunet, placa_grafica,
					data_ac, so, "\n");
		}
	}
	fclose(f1);
}

//afiseaza numarul de calculatoare care au acelasi procesor
void afisare_nr_calculatoare(int j) {
	char procesor[50];
	int i;
	int n = 0;
	printf("\nDenumire procesor:");
	scanf("%s", procesor);
	for (i = 0; i < j; i++) {
		if (c_array[i].nr_inv != 0
				&& strcmp(c_array[i].procesor, procesor) == 0) {
			n++;
		}
	}
	printf("\nNumarul de calculatoare pe care se gaseste procesorul:%d\n", n);
}

//afisare dupa luni a calculatoarelor
void afisare_luni(int j) {
	int i;
	char an_curent[5];
	char * pch;
	strcpy(an_curent, "2011");
	for (i = 0; i < j; i++) {
		pch = strtok(c_array[i].data_ac, "-");
		while (pch != NULL) {
			printf("%s\n", pch);
			pch = strtok(NULL, "-");
		}
	}
}

//functia de generare a meniului principal
void meniu(int j, int j2) {
	int opt = 12;
	while (opt != 0) {
		printf("1. Adaugare calculator\n"); //facut
		printf(
				"2. Afisarea tuturor calculatoarelor si a tuturor informatiilor despre acestea\n"); //facut
		printf(
				"3. Stergerea unui calculator din evidenta pe baza numarului de inventar\n"); //facut
		printf("4. Adaugarea unui program la un calculator\n"); //facut
		printf("5. Stergerea unui program de pe un calculator\n"); //facut
		printf(
				"6. Listarea tuturor calculatoarelor care au instalat un anumit program\n"); //facut
		printf(
				"7. Afisarea tuturor calculatoarelor achizitionate într-o perioada citita de la tastatura\n");
		printf(
				"8. Afisarea numarului de calculatoare achizitionat în fiecare din lunile anului");
		printf("precedent\n");
		printf(
				"9. Listarea tuturor calculatoarelor care au o anumita configuratie, citita de la"); //facut
		printf(
				"10. Afisarea numarului de calculatoare pe care se gasesc anumite tipuri de"); //facut
		printf("procesoare\n");
		printf("11. Salvare in fisiere\n");
		printf("Introduceti optiunea:\n");
		scanf("%d", &opt);

		switch (opt) {
		case 1:
			j = adaugare_calculator(j);
			break;
		case 2:
			afisare_calculatoare(j);
			break;
		case 3:
			stergerea_calculatoare(j);
			break;
		case 4:
			j2 = adaugare_programe(j2);
			break;
		case 5:
			stergerea_programe(j2);
			break;
		case 6:
			afisare_programe(j2);
			break;
		case 7:
			printf("Optiunea 7");
			break;
		case 8:
			afisare_luni(j);
			break;
		case 9:
			afisare_configuratie(j);
			break;
		case 10:
			afisare_nr_calculatoare(j);
			break;
		case 11:
			salvare_calculatoare(j);
			salvare_programe(j2);
			break;
		default:
			break;
		}
	}
}

//functie in care se citesc date din fisierul aferent calculatoarelor
int fisier_c() {
	FILE *fisier;
	char ch;
	char configuratie[100];
	char data_ac[20];
	char so[20];
	int nr_inv;
	char procesor[20];
	char memorie[20];
	char hard[20];
	char placa_baza[20];
	char placa_sunet[20];
	char placa_grafica[20];
	int i;
	int j = 0;
	calculator *c;
	prg *p;
	//c = (calculator *) malloc(sizeof calculator);
	//p = (prg *) malloc(sizeof prg);
	fisier = fopen("db.txt", "r");
	if (fisier == NULL) {
		printf("Fisierul nu exista!\nSa creat unul nou!\n");
		fisier = fopen("db.txt", "w+");
		fclose(fisier);
	} else {
		while (!feof(fisier)) {
			fscanf(fisier, "%d%s%s%s%s%s%s%s%s", &nr_inv, procesor, memorie,
					hard, placa_baza, placa_sunet, placa_grafica, data_ac, so);
			strcpy(c_array[j].procesor, procesor);
			strcpy(c_array[j].memorie, memorie);
			strcpy(c_array[j].hard, hard);
			strcpy(c_array[j].placa_baza, placa_baza);
			strcpy(c_array[j].placa_sunet, placa_sunet);
			strcpy(c_array[j].placa_grafica, placa_grafica);
			strcpy(c_array[j].data_ac, data_ac);
			strcpy(c_array[j].so, so);
			c_array[j].nr_inv = nr_inv;
			j++;
		}
	}

	fclose(fisier);
	return j;
}

//citeste din fisierul aferent programelor
int fisier_p() {
	flushall();
	FILE *fisier2;
	int nr_inv;
	char soft[20];
	int ver;
	int i;
	int j2 = 0;
	prg *p;
	p = (prg *) malloc(sizeof prg);
	fisier2 = fopen("db2.txt", "r");
	if (fisier2 == NULL) {
		printf("Fisierul nu exista!\nSa creat unul nou!\n");
		fisier2 = fopen("db2.txt", "w+");
		fclose(fisier2);
	} else {

		while (!feof(fisier2)) {
			fscanf(fisier2, "%d%s%d", &nr_inv, soft, &ver);
			strcpy(p_array[j2].program, soft);
			p_array[j2].nr_inv = nr_inv;
			p_array[j2].ver = ver;
			j2++;
		}
	}

	fclose(fisier2);
	return j2;
}

void main() {
	int i;
	int j = fisier_c(); //returneaza numarul de inregistrari de calculatoare
	int j2 = fisier_p(); // returneaza numarul de inregistrari de programe
	j = j - 1;
	j2 = j2 - 1;
	meniu(j, j2);
	getch();
}

