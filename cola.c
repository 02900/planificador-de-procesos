// cola.c
// Created by Juan Ortiz
// Copyright c 2017 Juan Ortiz. All rights reserved

#include <stdlib.h>
#include "cola.h"

// Operacion crear nodo
NodoProceso* CrearNodo (Proceso* proceso) {
	NodoProceso* nodo = (NodoProceso *) malloc (sizeof (NodoProceso));
	nodo->proceso = proceso;
	nodo->anterior = nodo->siguiente = NULL;
	return nodo;
}

// Operacion destruir nodo
void DestruirNodo (NodoProceso* nodo) {
	nodo->proceso = NULL;
	nodo->anterior = nodo->siguiente = NULL;
	free (nodo);
}

// Operacion crear cola
Cola* CrearCola () {
	Cola* cola = (Cola *) malloc (sizeof (Cola));
	cola->primero = cola->cabeza = cola->ultimo = NULL;
	return cola;
}

// Operacion destruir cola
void DestruirCola (Cola* cola) {
	while (cola->primero)
		Eliminar (cola);
	free (cola);
}

// Operacion anadir proceso a la cola
void Encolar (Cola* cola, Proceso* proceso){
	NodoProceso* nodo = CrearNodo (proceso);
	if (!cola->primero) {
		cola->primero = nodo;
		cola->ultimo = nodo;
	} else {
		cola->ultimo->siguiente = nodo;
		nodo->anterior = cola->ultimo;
		cola->ultimo = nodo;
	}
}

// Operacion consultar primero proceso de la cola
Proceso* Consultar (Cola* cola) {
	if (cola->primero) {
		return cola->primero->proceso;
	} else {
		return NULL;
	}
}

// Operacion eliminar primero proceso de la cola
void Eliminar (Cola* cola) {
	if (cola->primero) {
		NodoProceso* eliminado = cola->primero;
		cola->primero = cola->primero->siguiente;
		DestruirNodo (eliminado);
		if (!cola->primero)
			cola->ultimo = NULL;
	}
}

// Operacion elminar y devolver primero proceso de la cola
Proceso* EliminarPrimero (Cola* cola) {
    if (cola->primero) {
        NodoProceso* eliminado = cola->primero;
        Proceso* proceso = cola->primero->proceso;
        cola->primero = cola->primero->siguiente;
        DestruirNodo (eliminado);
        if (!cola -> primero)
            cola->ultimo = NULL;
		return proceso;
    }
    return NULL;
}

// Operacion eliminar un proceso de la cola
void EliminarProceso (Cola* cola, long PID) {
	cola->cabeza = cola->primero;
	while (cola->cabeza) {
		if (cola->cabeza->proceso->PID == PID){
			NodoProceso* eliminado = cola->cabeza;
			if (cola->cabeza == cola->primero) {
				cola->primero = cola->primero->siguiente;
				cola->primero->anterior = NULL;

			} else if (cola->cabeza == cola->ultimo) {
				cola->ultimo = cola->ultimo->anterior;
				cola->ultimo->siguiente = NULL;
			} else {
				eliminado->anterior->siguiente = eliminado->siguiente;
				eliminado->siguiente->anterior = eliminado->anterior;
			}
			DestruirNodo (eliminado);
			if (!cola->primero)
				cola->ultimo = NULL;
		}
		cola->cabeza = cola->cabeza->siguiente;
	}
}