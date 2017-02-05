//  cola.c
//  Planificador de procesos
//
//  Created by Juan Ortiz & Andres Buelvas on 29/1/17.
//  Copyright © 2017 Juan Ortiz & Andres Buelvas. All rights reserved.
//

#include <stdlib.h>
#include "cola.h"

/*
 Funcion que se encarga de crear un nodo a partir de procesos de entrada
 Entrada proceso: proceso de tipo Proceso
 Salida: retorna un nodo de tipo NodoProceso que la identifica              
*/
NodoProceso* CrearNodo (Proceso* proceso) {
    NodoProceso* nodo = (NodoProceso *) malloc (sizeof (NodoProceso));
    nodo->proceso = proceso;
    nodo->anterior = nodo->siguiente = NULL;
    return nodo;
}

/*
 Funcion que se encarga eliminar o destruir el proceso perteneciente al nodo
 Entrada nodo: es rl nodo de tipo NodoProceso que queremos eliminar           
*/
void DestruirNodo (NodoProceso* nodo) {
    nodo->proceso = NULL;
    nodo->anterior = nodo->siguiente = NULL;
    free (nodo);
}

/*
 Funcion que se encarga de contruir un cola de prioridad en memoria dinamica
 Salida: retorna un apuntador a una cola de prioridad            
*/
Cola* CrearCola () {
    Cola* cola = (Cola *) malloc (sizeof (Cola));
    cola->primero = cola->cabeza = cola->ultimo = NULL;
    return cola;
}

/*
 Funcion que se encarga de eliminar una cola de prioridad de la memoria dinamica
 Entrada cola: cola de prioridad del planificar de tipo Cola             
*/
void DestruirCola (Cola* cola) {
    while (cola->primero)
        Eliminar (cola);
    free (cola);
}

/*
 Funcion que se encarga de consultar un proceso a traves del PID que lo identifica
 Entrada cola: cola de prioridad del planificar de tipo Cola
 Entrada PID: identificador del proceso.
 Salida: un apuntador a proceso              
*/
Proceso* consultarPID (Cola* cola, long PID) {
    cola->cabeza = cola->primero;
    while (cola->cabeza) {
        if (cola->cabeza->proceso->PID == PID)
            return cola->cabeza->proceso;
        cola->cabeza = cola->cabeza->siguiente;
    }
    return NULL;
}

/*
 Funcion que se encarga de insertar el proceso dentro de la cola de prioridad
 asignada
 Entrada cola
 Entrada PID: identificador del proceso.
 Salida: un apuntador a proceso              
*/
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

/*
 Funcion que permite consultar el primer proceso de la cola
 Entrada cola: cola de prioridad del planificador
 Salida: apuntador al primer proceso
*/
Proceso* Consultar (Cola* cola) {
    if (cola->primero) {
        return cola->primero->proceso;
    } else {
        return NULL;
    }
}

/*
 Funcion que permite eliminar al primer proceso de la cola
 Entrada cola: cola de prioridad del planificador
*/
void Eliminar (Cola* cola) {
    if (cola->primero) {
        NodoProceso* eliminado = cola->primero;
        cola->primero = cola->primero->siguiente;
        
        DestruirNodo (eliminado);
        if (!cola->primero)
            cola->ultimo = NULL;
        else {
            cola->primero->anterior = NULL;
            cola->ultimo->siguiente = NULL;
        }
    }
}

/*
 Funcion que permite eliminar al ultimo proceso de la cola
 Entrada: cola de prioridad del planificador
*/
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
 Funcion que permite eliminar y retornar el primer proceso de la cola
 Entrada cola: cola de prioridad del planificador
 Salida: apuntador al primer proceso de la cola
*/
Proceso* EliminarPrimero (Cola* cola) {
    if (cola->primero) {
        NodoProceso* eliminado = cola->primero;
        Proceso* proceso = cola->primero->proceso;
        cola->primero = cola->primero->siguiente;
        DestruirNodo (eliminado);
        if (!cola -> primero)
            cola->ultimo = NULL;
        else {
            cola->ultimo->siguiente = NULL;
            cola->primero->anterior = NULL;
        }
        return proceso;
    }
    return NULL;
}

/*
 Funcion que permite eliminar un proceso de la cola de acuerdo a su PID
 Entrada cola: cola de prioridad del planificador
 Entrada PID: identificador del proceso 
*/
void EliminarProceso (Cola* cola, long PID) {
    cola->cabeza = cola->primero;
    NodoProceso* eliminado;
    while (cola->cabeza) {
        if (cola->cabeza->proceso->PID == PID){
            eliminado = cola->cabeza;
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

/*
 Funcion que permite colocar al primer nodo de la cola al final del mismo
 y se le asigna del valor de 'E' a su estado
 Entrada cola: cola de prioridad del planificador
 Salida: apuntador al proceso desplazado
*/
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