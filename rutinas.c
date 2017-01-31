// rutinas.c
// created by Juan Ortiz on 28/01/2017
// Copyright c 2017 Juan Ortiz. All rights reserved

#include "rutinas.h"

/*
 Rutina que permite insertar un proceso en alguna de las de colas de prioridades
 Parametros:
    s es un apuntador a la estructura de colas del planificador
    p es un apuntador a la estructura de datos perteneciente al proceso a insertar
    prioridad es un numero del 0 al 5 que corresponde a la prioridad del procesos
 */
void InsertarProceso(EstrucSched* s, Proceso* p, short prioridad){
    
    // Si no se ha inicializado la estructura de colas prioridad s
    // entonces se crean las colas q1, ..., q5
    if (s->init == 0) {
        s->q0 = CrearCola();
        s->q1 = CrearCola();
        s->q2 = CrearCola();
        s->q3 = CrearCola();
        s->q4 = CrearCola();
        s->q5 = CrearCola();
        s->init = 1;
    }
    
    // El proceso se insertara de ultimo en la cola correspondiente a su prioridad
    switch (prioridad) {
        case 0:
            Encolar(s->q0, p);
            break;
        case 1:
            Encolar(s->q1, p);
            break;
        case 2:
            Encolar(s->q2, p);
            break;
        case 3:
            Encolar(s->q3, p);
            break;
        case 4:
            Encolar(s->q4, p);
            break;
        case 5:
            Encolar(s->q5, p);
            break;
        default:
            break;
    }
    
    //printf("%ld %c %d %f %s\n", p->PID, p->estado, p->prioridad, p->time, p->comando);
}

/*
 Rutina que permite elminar un proceso de la estructura de colas
 Parametros:
    s es un apuntador a la estructura de colas del planificador
    pid es el PID del proceso a eliminar
    prio es un numero del 0 al 5 que corresponde a la prioridad del procesos
 */
void ElimProceso (EstrucSched *s, long pid, short prio) {
    switch (prio) {
        case 0:
            EliminarProceso(s->q0, pid);
            break;
        case 1:
            EliminarProceso(s->q1, pid);
            break;
        case 2:
            EliminarProceso(s->q2, pid);
            break;
        case 3:
            EliminarProceso(s->q3, pid);
            break;
        case 4:
            EliminarProceso(s->q4, pid);
            break;
        case 5:
            EliminarProceso(s->q5, pid);
            break;
        default:
            break;
    }

}

/*
 Rutina que permite elminar ultimo proceso de la estructura de colas ejecutado
 Parametros:
    s es un apuntador a la estructura de colas del planificador
 */
void ElimProcesoE(EstrucSched *s){
    EliminarU(s->enEjecucion);
}

/*
 Rutina que retorna el proximo proceso a planificar
 Parametros:
    s es un apuntador a la estructura de colas del planificador
 */
Proceso *ProxProceso(EstrucSched *s) {
    if (s->q0->primero){
        s->enEjecucion = s->q0;
        CambiarEstado(s, s->enEjecucion->ultimo->proceso, 'L');
        return DesplazarNodo(s->q0);
    }
    
    else if (s->q1->primero) {
        s->enEjecucion = s->q1;
        CambiarEstado(s, s->enEjecucion->ultimo->proceso, 'L');
        return DesplazarNodo(s->q1);
    }
    
    else if (s->q2->primero) {
        s->enEjecucion = s->q2;
        CambiarEstado(s, s->enEjecucion->ultimo->proceso, 'L');
        return DesplazarNodo(s->q2);
    }
    
    else if (s->q3->primero) {
        s->enEjecucion = s->q3;
        CambiarEstado(s, s->enEjecucion->ultimo->proceso, 'L');
        return DesplazarNodo(s->q3);
    }

    else if (s->q4->primero) {
        s->enEjecucion = s->q4;
        CambiarEstado(s, s->enEjecucion->ultimo->proceso, 'L');
        return DesplazarNodo(s->q4);
    }

    else if (s->q5->primero) {
        s->enEjecucion = s->q5;
        CambiarEstado(s, s->enEjecucion->ultimo->proceso, 'L');
        return DesplazarNodo(s->q5);
    }

    else
        s->enEjecucion = NULL;
    
    return NULL;
}

/*
 Rutina que asigna un nuevo estado a un proceso
 Parametros:
    s es un apuntador a la estructura de colas del planificador
    p es un apuntador a la estructura de datos perteneciente al proceso a modficar su estado
    newestado es el estado que se asgina al proceso p
 */
void CambiarEstado (EstrucSched *s, Proceso* p, Estado newestado) {
    p->estado = newestado;
}
