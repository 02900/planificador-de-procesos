// cola.h
// created by Juan Ortiz on 28/01/2017
// Copyright c 2017 Juan Ortiz. All rights reserved

#ifndef cola_h
#define cola_h

#include <stdio.h>
#include "proceso.h"

typedef struct NodoProceso {
	Proceso* proceso;
	struct NodoProceso* anterior;
	struct NodoProceso* siguiente;
} NodoProceso;

typedef struct Cola {
	NodoProceso*  primero;
	NodoProceso* cabeza;
	NodoProceso* ultimo;
} Cola;


NodoProceso* CrearNodo (Proceso* proceso);
void DestruirNodo (NodoProceso* proceso);

Cola* CrearCola ();
void DestruirCola (Cola* cola);

void Encolar (Cola* cola, Proceso* proceso);

Proceso* Consultar (Cola* cola);
void Eliminar (Cola* cola);
Proceso* EliminarPrimero (Cola* cola);

Proceso* ConsultarU (Cola* cola);
void EliminarU (Cola* cola);
Proceso* EliminarUltimo (Cola* cola);

void EliminarProceso (Cola* cola, long pid);

Proceso* DesplazarNodo (Cola* cola);

#endif //cola_h
