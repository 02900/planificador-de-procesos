//  rutinas.c
//  Planificador de procesos
//
//  Created by Juan Ortiz & Andres Buelvas on 29/1/17.
//  Copyright © 2017 Juan Ortiz & Andres Buelvas. All rights reserved.
//

#include "rutinas.h"
#include "interfaz.h"

/*
 Funcione que permite insertar un proceso en alguna de las de colas de prioridades
 Entrada s: es un apuntador a la estructura de colas del planificador
 Entrada p: es un apuntador a la estructura de datos perteneciente al proceso a insertar
 Entrada prioridad: es un numero del 0 al 5 que corresponde a la prioridad del procesos
 */
void InsertarProceso(EstrucSched* s, Proceso* p, short prioridad){
    
    if(s->enEjecucion == NULL) {
        
        if (p->estado == 'L') {
            Proceso* p2 = NULL;
            switch (prioridad) {
                case 0:
                    p2 = consultarPID(s->q0, p->PID);
                    if (!p2) {
                        Encolar(s->q0, p);
                        msg_Insercion ();
                    } else
                        msg_errorInsertPID (p2);
                    break;
                    
                case 1:
                    p2 = consultarPID(s->q1, p->PID);
                    if (!p2) {
                        Encolar(s->q1, p);
                        msg_Insercion ();
                    } else
                        msg_errorInsertPID (p2);
                    break;
                    
                case 2:
                    p2 = consultarPID(s->q2, p->PID);
                    if (!p2) {
                        Encolar(s->q2, p);
                        msg_Insercion ();
                    } else
                        msg_errorInsertPID (p2);
                    break;
                    
                case 3:
                    p2 = consultarPID(s->q3, p->PID);
                    if (!p2) {
                        Encolar(s->q3, p);
                        msg_Insercion ();
                    } else
                        msg_errorInsertPID (p2);
                    break;
                    
                case 4:
                    p2 = consultarPID(s->q4, p->PID);
                    if (!p2) {
                        Encolar(s->q4, p);
                        msg_Insercion ();
                    } else
                        msg_errorInsertPID (p2);
                    break;
                    
                case 5:
                    p2 = consultarPID(s->q5, p->PID);
                    if (!p2) {
                        Encolar(s->q5, p);
                        msg_Insercion ();
                    } else
                        msg_errorInsertPID (p2);
                    break;
                    
                default:
                    msg_ErrorInsertar(p);
                    break;
            }
        }
        
        else
            msg_ErrorInsertar(p);
    }
    
    else
        msg_Busy ();
}

/*
 Funcion que permite elminar un proceso de la estructura de colas
 Entrada s: es un apuntador a la estructura de colas del planificador
 Entrada pid: es el identificador del proceso a eliminar
 Entrada prio: es un numero del 0 al 5 que corresponde a la prioridad del procesos
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
            msg_ErrorElim();
            break;
    }
    
}

/*
 Funcion que permite elminar ultimo proceso de la estructura de colas ejecutado
 Entrada s: es un apuntador a la estructura de colas del planificador
 */
void ElimProcesoE(EstrucSched *s) {
    EliminarU(s->enEjecucion);
    s->enEjecucion = NULL;
}

/*
 Funcion que retorna el proximo proceso a planificar
 Entrada s: es un apuntador a la estructura de colas del planificador
 Salida: identidicar al proximo proceso
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
 Funcion que asigna un nuevo estado a un proceso
 Entrada s: es un apuntador a la estructura de colas del planificador
 Enrada p: es un apuntador a la estructura de datos perteneciente al proceso a modficar su estado
 Entrada newestado: es el estado que se asgina al proceso p
 */
void CambiarEstado (EstrucSched *s, Proceso* p, Estado newestado) {
    p->estado = newestado;
}

/*
 Funcion que detiene la ejecucion del proceso actual
 Entrada s: apuntador a la estructura de colas del planificador
*/
void DetenerEjecucion (EstrucSched* s) {
    s->enEjecucion->ultimo->proceso->estado = 'L';
    s->enEjecucion = NULL;
}