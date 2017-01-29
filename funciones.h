//Directtivas

#include <stdio.h>
#include <stdlib.h>

//Declaraciones:

char* nombreArchivoEntrada;
char* nombreArchivoSalida;

typedef struct Proceso{

	short pid;
	char estado;
	float tiempo;
	char* comando;
	void *siguiente;  //Apuntador al siguiente proceso
	void *anterior;		//Apuntador al anterior proceso

}Proceso;

typedef struct colaDePrioridad{

	int numeroDeProcesos;
	Proceso *cabeza;
	Proceso *final;

}cola;

typedef struct EstrucSched{

	cola* q0;
	cola* q1;
	cola* q2;
	cola* q3;
	cola* q4;
	cola* q5;

}EstrucSched;

typedef struct Estado{

	char estado;

}Estado;

//Prototipos:

void menu(EstrucSched* s);

void menu2(EstrucSched* s);

void InsertarProceso(EstrucSched* s, Proceso* p, short prioridad);

void ElimProceso(EstrucSched *s, long pid, short prio);

void ElimProcesoE(EstrucSched *s);

Proceso *ProxProceso(EstrucSched *s);

void CambiarEstado(EstrucSched *s, Proceso* p, Estado newestado);

EstrucSched *Construye(char *filename);

void Imprime(EstrucSched *s);




