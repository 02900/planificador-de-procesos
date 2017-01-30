//
//  proceso.c
//  Planificador de procesos
//
//  Created by Juan Tepedino on 29/1/17.
//  Copyright © 2017 Juan Tepedino. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "proceso.h"

Proceso* CrearProceso (long pid, Estado e, short prio, float time, char* cmd) {
    Proceso* proceso = (Proceso *) malloc (sizeof (Proceso));
    proceso->PID = pid;
    proceso->estado = e;
    proceso->prioridad = prio;
    proceso->time = time;
    strcpy(proceso->comando, cmd);
    return proceso;
}