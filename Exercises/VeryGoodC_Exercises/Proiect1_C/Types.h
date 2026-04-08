#ifndef TYPES_H
#define TYPES_H

#define DIM        (int)100
#define FUNCTIONAL (char)1
#define DEFECT     (char)2
#define NO_EXIT    (int)231234
#define DIM_MONITOR      (int)100
#define DIM_IMPRIMANTA  (int)100
#define DIM_CALCULATOR  (int)100

 
typedef struct data {
	int zi;
	int luna;
	int an;
} Data;

typedef struct {
	char StareEchipament;
	char NumeProducator[DIM];
	int  NumarDeInventar;
	int  TermenGarantieAni;
	int  VitezaProcesorMHz;
	int  CantitateMbRAM;
	int  DimensiuneGbHDD;
	float PerformantaPC;
	Data DataAchizitie;
} Calculator;
 
 
typedef enum tipImprimanta {
	CERNEALA,
	LASER,
	MATRICEALA
} TipImprimanta;

typedef enum dimensiuneHartie {
	A3,
	A4
} DimensiuneHartie;

typedef struct imprimanta {
	char stareEchipament;
	char numeProducator[DIM];
	int  numarDeInventar;
	int  termenGarantieAni;
	int rezolutie;
 	TipImprimanta tipImprimanta;
 	DimensiuneHartie tipDimensiuneHartie;
	Data dataAchizitie;
	
} Imprimanta;

typedef enum tipMonitor {
	CRT,
	LCD
} TipMonitor;

typedef struct monitor {
	char numeProducator[DIM];
	int numarDeInventar;
	int diagonalaInch;
	TipMonitor tipMonitor;
	int timpDeRaspunsMs;
} Monitor;


#endif
