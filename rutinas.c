// rutinas.c
// created by Juan Ortiz on 28/01/2017
// Copyright c 2017 Juan Ortiz. All rights reserved

#include "rutinas.h"

// metodo para insertar proceso a una cola
void InsertarProceso(EstrucSched* s, Proceso* p, short prioridad){

	Proceso *aux = NULL;
	//printf("%d\n", prioridad);

	if(prioridad == 0){
		s->q0->numProcesos++;
		if(s->q0->cabeza == NULL){
			s->q0->cabeza->proceso = p;
			s->q0->ultimo->proceso =p;
			s->q0->cabeza->siguiente = NULL;
			s->q0->cabeza->anterior = NULL;
		}
		else{

			//printf("%d\n", p -> pid);
			//printf("%c\n", p -> estado);
			//printf("%f\n", p -> tiempo);
			//printf("%s\n", p -> comando);

			aux = s->q0->ultimo->proceso;
			s->q0->ultimo->siguiente->proceso = p;
			s->q0->ultimo->anterior->proceso = aux;


			//ESTO DA ERROR
			//printf("%d\n", s-> q0-> ultimo-> anterior -> pid);
			//printf("%c\n", s-> q0-> ultimo-> anterior -> estado);
			//printf("%f\n", s-> q0-> ultimo-> anterior -> tiempo);
			//printf("%s\n", s-> q0-> ultimo-> anterior -> comando);
		}
		//printf("Se ha agregado el proceso con exito\n");
	}
}

/*

// metodo para eliminar proceso de una cola
void ElimProceso(EstrucSched *s, int pid, int prio){

	long pidArgumento = pid;
	proceso * auxProceso;
	proceso * anteriorAux;
	proceso * siguienteAux;
	char *auxEstado;
	long *auxPid;

	if(prioridad == 0){

		int ayuda = 0;

		aux = s-> q0-> &cabeza
		if(aux == NULL){
			printf("No existe elementos en la cola\n");
		}
		if(aux != NULL){

			auxEstado = aux-> estado;
			auxPid = aux-> pid;

			while(ayuda == 0){

				if(auxPid == pidArgumento){

					if(auxEstado == 'L'){
						anteriorAux = aux -> anterior;
						siguienteAux = aux -> siguiente;

						aux -> anterior -> siguiente = siguienteAux;
						aux -> siguiente -> anterior = anteriorAux;
						printf("Se ha eliminado satifactoriamente el proceso de la cola\n");
						return;


					}
					else if(auxEstado == 'E'){
						ayuda = -1;
						printf("El proceso sigue en ejecucion. No puede ser eliminado\n");
					}

				}
				else{
					aux = aux-> siguiente;
					auxEstado = aux-> siguiente -> estado;
					auxPid = aux -> siguiente-> pid;
				}
			}
		}
	}
}

void ElimProcesoE(EstrucSched *s){

	Proces *p = NULL;
	long *pidTemp = NULL;
	short *prioTemp = NULL;

	*p = ProxProceso(&s);

	*pidTemp = p-> &pid;
	*prioTemp = p-> &prioridad;

	ElimProceso(&s, &pidTemp, &prioTemp);
}

Proceso *ProxProceso(EstrucSched *s){

	Proceso *p == NULL;
	char estadoTemp;

	int valor = s-> q0-> &numeroDeProcesos;
	if(valor == 0){
		valor = s-> q1-> &numeroDeProcesos;
	}
	else{
		*p = s-> q0 -> &cabeza
		estadoTemp = p-> &estado;
		if(estado != 'L)'){
			return *p
		}
		else{
			while(p != NULL){
				*p = s-> q0 -> cabeza -> &siguiente;
				estadoTemp = p->& estado;
				if(estado != 'L)'){
					return *p
				}

			}
		}
	}

}


void CambiarEstado(EstrucSched *s, Proceso* p, char estado){

}

*/

EstrucSched *Construye(char *filename){

	//Estructuras y apuntadores

	EstrucSched *s;
	EstrucSched planificador;

	Cola cola0;
	Cola cola1;
    Cola cola2;
	Cola cola3;
	Cola cola4;
	Cola cola5;

	Cola *c0;
	Cola *c1;
	Cola *c2;
	Cola *c3;
	Cola *c4;
	Cola *c5;

	FILE* archivo;
	int pidAux;
	char estadoAux;
	int prioridadAux;
	float tiempoAux;
	char comandoAux[20];

	//Inicializaciones

	s = &planificador;
	c0 = &cola0;
	c1 = &cola1;
	c2 = &cola2;
	c3 = &cola3;
	c4 = &cola4;
	c5 = &cola5;

	s-> q0 = c0;
	s-> q1 = c1;
	s-> q2 = c2;
	s-> q3 = c3;
	s-> q4 = c4;
	s-> q5 = c5;

	s-> q0-> numProcesos = 0;
	s-> q1-> numProcesos = 0;
	s-> q2-> numProcesos = 0;
	s-> q3-> numProcesos = 0;
	s-> q4-> numProcesos = 0;
	s-> q5-> numProcesos = 0;

	s-> q0-> cabeza = NULL;
	s-> q0-> ultimo = NULL;
	s-> q1-> cabeza = NULL;
	s-> q1-> ultimo = NULL;
	s-> q2-> cabeza = NULL;
	s-> q2-> ultimo = NULL;
	s-> q3-> cabeza = NULL;
	s-> q3-> ultimo = NULL;
	s-> q4-> cabeza = NULL;
	s-> q4-> ultimo = NULL;
	s-> q5-> cabeza = NULL;
	s-> q5-> ultimo = NULL;


	archivo = fopen(filename, "r");

	while(fscanf(archivo, "%d %c %d %f %s", &pidAux, &estadoAux, &prioridadAux, &tiempoAux, comandoAux) != EOF){

		Proceso proc;
		Proceso *p;
		p = &proc; 

		p->PID = pidAux;
		p->estado = estadoAux;
		p->time = tiempoAux;
		//p->comando = &comandoAux;

		InsertarProceso(s, p, prioridadAux);
	}

	fclose(archivo);

	return s;

}
