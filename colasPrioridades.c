//
//  colaPrioridades.c
//  Planificador de procesos
//  colasPrioridades.c
//  Planificador de procesos
//
//  Created by Juan Ortiz & Andres Buelvas on 29/1/17.
//  Copyright © 2017 Juan Ortiz & Andres Buelvas. All rights reserved.
//

#include "colasPrioridades.h"
#include "rutinas.h"
#include "interfaz.h"

EstrucSched* Construye(char* filename) {
    EstrucSched* s = (EstrucSched *) malloc (sizeof (EstrucSched));
    
    s->q0 = CrearCola();
    s->q1 = CrearCola();
    s->q2 = CrearCola();
    s->q3 = CrearCola();
    s->q4 = CrearCola();
    s->q5 = CrearCola();
    
    s->enEjecucion = NULL;
    
    long pid;
    Estado e;
    short prio;
    float tiempo;
    char cmd[20];
    
    Proceso* p;
    
    FILE* fp = fopen (filename, "r");
    
    if(fp == NULL)
        msg_ErrorOpenFile();
    else
        msg_readFile();

    while (fscanf(fp, "%ld %c %hd %f %s", &pid, &e, &prio, &tiempo, cmd) != EOF) {
        p = CrearProceso(pid, e, prio, tiempo, cmd);
        InsertarProceso(s, p, p->prioridad);
    }
    
    msg_endReadFile ();
    fclose (fp);
    
    return s;
}
