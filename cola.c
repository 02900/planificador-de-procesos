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

// Fuera Alcance Proyecto
// Operacion consultar primero proceso de la cola
Proceso* Consultar (Cola* cola) {
    if (cola->primero) {
        return cola->primero->proceso;
    } else {
        return NULL;
    }
}

// Fuera Alcance Proyecto
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

// Fuera Alcance Prpyecto
// Operacion elminar y devolver primero proceso de la cola
Proceso* EliminarPrimero (Cola* cola) {
    if (cola->primero) {
        NodoProceso* eliminado = cola->primero;
        Proceso* proceso = cola->primero->proceso;
        cola->primero = cola->primero->siguiente;
        cola->ultimo->siguiente = NULL;
        cola->primero->anterior = NULL;
        DestruirNodo (eliminado);
        if (!cola -> primero)
            cola->ultimo = NULL;
        return proceso;
    }
    return NULL;
}


// Fuera Alcance Proyecto
// Operacion consultar primero proceso de la cola
Proceso* ConsultarU (Cola* cola) {
    if (cola->ultimo) {
        return cola->ultimo->proceso;
    } else {
        return NULL;
    }
}

// Operacion eliminar ultimo proceso de la cola
void EliminarU (Cola* cola) {
    if (cola->ultimo) {
        NodoProceso* eliminado = cola->ultimo;
        cola->ultimo = cola->ultimo->anterior;
        
        DestruirNodo (eliminado);
        if (!cola->ultimo)
            cola->primero = NULL;
        else {
            cola->ultimo->siguiente = NULL;
            cola->primero->anterior = NULL;
        }
    }
}

/*
 Fuera del alcance del proyecto
 
 No se ha probado, se piensa que debe tener error al eliminar el nodo. Ya que con este se eliminada la data del proceso tmb y no se retornara algo correcto.
 
 // Operacion elminar y devolver ultimo proceso de la cola
 Proceso* EliminarUltimo (Cola* cola) {
 if (cola->ultimo) {
 NodoProceso* eliminado = cola->ultimo;
 Proceso* proceso = cola->ultimo->proceso;
 cola->ultimo = cola->ultimo->anterior;
 DestruirNodo (eliminado);
 if (!cola -> ultimo)
 cola->primero = NULL;
 return proceso;
 }
 return NULL;
 }
 */

// Operacion eliminar un proceso de la cola dado su PID
void EliminarProceso (Cola* cola, long PID) {
    cola->cabeza = cola->primero;
    while (cola->cabeza) {
        if (cola->cabeza->proceso->PID == PID){
            NodoProceso* eliminado = cola->cabeza;
            if (cola->cabeza == cola->primero) {
                cola->primero = cola->primero->siguiente;                
            } else if (cola->cabeza == cola->ultimo) {
                cola->ultimo = cola->ultimo->anterior;
            } else {
                eliminado->anterior->siguiente = eliminado->siguiente;
                eliminado->siguiente->anterior = eliminado->anterior;
            }
            DestruirNodo (eliminado);
            if (!cola->primero)
                cola->ultimo = NULL;
            else {
                cola->ultimo->siguiente = NULL;
                cola->primero->anterior = NULL;
            }
        }
        cola->cabeza = cola->cabeza->siguiente;
    }
}

// Operacion colocar el primer nodo de la cola de ultimo en la misma
Proceso* DesplazarNodo (Cola* cola) {
    cola->ultimo->siguiente = cola->primero;
    cola->ultimo->siguiente->anterior = cola->ultimo;
    cola->ultimo = cola->ultimo->siguiente;
    cola->primero = cola->primero->siguiente;
    cola->primero->anterior = NULL;
    cola->ultimo->siguiente = NULL;
    
    cola->ultimo->proceso->estado = 'E';
    
    return cola->ultimo->proceso;
}