//
//  colaPrioridades.c
//  Planificador de procesos
//
//  Created by Juan Tepedino on 29/1/17.
//  Copyright © 2017 Juan Tepedino. All rights reserved.
//

#include <stdio.h>
#include "colasPrioridades.h"
#include "rutinas.h"

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
    float time;
    char* cmd;// NULL;
    
    //Proceso* p;
    
    FILE* fp = fopen (filename, "r");
    
    while (fscanf(fp, "%ld %c %hd %f %s", &pid, &e, &prio, &time, cmd) != EOF) {
        
        Proceso* p = CrearProceso(pid, e, prio, time, cmd);
        InsertarProceso(s, p, p->prioridad);
        
    }
    
    fclose (fp);
    
    return s;
}
