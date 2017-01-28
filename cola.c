//
// cola.c
// Created by Juan Ortiz
// Copyright c 2017 Juan Ortiz. All rights reserved

#include "cola.h"
#include <stdlib.h>

// Operacion crear nodo
NodoProceso* CrearNodo (Proceso* proceso) {
	NodoProceso* nodo = (NodoProceso *) malloc (sizeof (NodoProceso));
	nodo->proceso = proceso;
	nodo->siguiente = NULL;
	return nodo;
}

// Operacion destruir nodo
void DestruirNodo (NodoProceso* nodo) {
	nodo->proceso = NULL;
	nodo->siguiente = NULL;
	free (nodo);
}

// Operacion crear cola
Cola* CrearCola () {
	Cola* cola = (Cola *) malloc (sizeof (Cola));
	cola->primer = cola->ultimo = NULL;
	return cola;
}

// Operacion destruir cola
DestruirCola (Cola* cola) {
	while (cola->primer)
		Eliminar (cola);
	free (cola);
}

// Operacion anadir proceso a la cola
void Encolar (Cola* cola, Proceso* proceso){
	NodoProceso* nodo = CrearNodo (proceso);
	if (!cola->primer) {
		cola->primer = nodo;
		cola->ultimo = nodo;
	} else {
		cola->ultimo->siguiente = nodo;
		cola->ultimo = nodo;	
	}
}

// Operacion consultar primer proceso de la cola
Proceso* Consultar (Cola* cola) {
	if (cola->primer) {
		return cola->primer->proceso;
	} else {
		return NULL;
	}
}

// Operacion eliminar primer proceso de la cola
void Eliminar (Cola* cola) {
	if (cola->primer) {
		NodoProceso* eliminado = cola->primer;
		cola->primer = cola->primer->siguiente;
		DestruirNodo (eliminado);
		if (!cola -> primer)
			cola->ultimo = NULL;
	}
}

// Operacion elminar y devolver primer proceso de la cola
Proceso* Eliminar (Cola* cola) {
        if (cola->primer) {
                NodoProceso* eliminado = cola->primer;
		Proceso* proceso = cola->primer->proceso;
		cola->primer = cola->primer->siguiente;
                DestruirNodo (eliminado);
                if (!cola -> primer)
                        cola->ultimo = NULL;
		return proceso;
        }
}