//  cola.h
//  Planificador de procesos
//
//  Created by Juan Ortiz & Andres Buelvas on 29/1/17.
//  Copyright © 2017 Juan Ortiz & Andres Buelvas. All rights reserved.
//

#ifndef cola_h
#define cola_h

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

Proceso* consultarPID (Cola* cola, long pid);

void Encolar (Cola* cola, Proceso* proceso);

Proceso* Consultar (Cola* cola);

void Eliminar (Cola* cola);

Proceso* EliminarPrimero (Cola* cola);

void EliminarU (Cola* cola);

void EliminarProceso (Cola* cola, long pid);

Proceso* DesplazarNodo (Cola* cola);

#endif //cola_h
