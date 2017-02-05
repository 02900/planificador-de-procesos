//  proceso.c
//  Planificador de procesos
//
//  Created by Juan Ortiz & Andres Buelvas on 29/1/17.
//  Copyright © 2017 Juan Ortiz & Andres Buelvas. All rights reserved.
//

//#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proceso.h"

/*
 Funcion que se encarga e crear una estructura de tipo Proceso en memoria dinamica
 Entrada pid: identificador del proceso
 Entrada e: Estado del proceso (En ejecucion o Listo)
 Entrada prio: prioridad que dira en que cola estara ubicado el proceso
 Entrada time: tiempo en la cual fue hecho el proceso
 Entrada cmd: comando del proceso
 Salida: un apuntador al proceso              
*/
Proceso* CrearProceso (long pid, Estado e, short prio, float time, char* cmd) {
    Proceso* proceso = (Proceso *) malloc (sizeof (Proceso));
    proceso->PID = pid;
    proceso->estado = e;
    proceso->prioridad = prio;
    proceso->time = time;
    strcpy(proceso->comando, cmd);
    return proceso;
}