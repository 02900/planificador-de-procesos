//  interfaz.h
//  Planificador de procesos
//
//  Created by Juan Ortiz & Andres Buelvas on 29/1/17.
//  Copyright © 2017 Juan Ortiz & Andres Buelvas. All rights reserved.
//

#ifndef interfaz_h
#define interfaz_h
#include <stdio.h>
#include "colasPrioridades.h"
#include "rutinas.h"

void menu(EstrucSched* s, char* salida);

void menuInterno(EstrucSched* s, char* salida);

void Imprime(EstrucSched *s);

void ImprimeProceso (Proceso* p);

void Salir (EstrucSched *s, char* salida);

void escribeSalida (Proceso *p, FILE* fp);

void LiberarMemoria (EstrucSched* s);

void msg_Insercion ();

void msg_ErrorInsertar (Proceso* p);

void msg_errorInsertPID (Proceso* p);

void msg_ErrorElim ();

void msg_Busy ();

void msg_readFile ();

void msg_endReadFile ();

void msg_ErrorOpenFile ();


#endif //interfaz_h