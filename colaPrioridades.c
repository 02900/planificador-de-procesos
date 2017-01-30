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
    EstrucSched* s;
    s->init = 0;
    
    long pid;
    Estado e;
    short prio;
    float time;
    char cmd;
    
    //Proceso* p;
    
    FILE* fp = fopen (filename, "r");
    
    while (fscanf(fp, "%ld %c %hd %f %s", &pid, &e, &prio, &time, &cmd) != EOF) {
        
        Proceso* p = CrearProceso(pid, e, prio, time, cmd);
        InsertarProceso(s, p, p->prioridad);
        
    }
    
    fclose (fp);
    
    return s;
}
