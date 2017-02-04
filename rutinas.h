// rutinas.h
// created by Juan Ortiz on 28/01/2017
// Copyright c 2017 Juan Ortiz. All rights reserved

#ifndef rutinas_h
#define rutinas_h

#include <stdlib.h>
#include "proceso.h"
#include "colasPrioridades.h"

void InsertarProceso(EstrucSched* s, Proceso* p, short prioridad);

void ElimProceso(EstrucSched *s, long pid, short prio);

void ElimProcesoE(EstrucSched *s);

Proceso *ProxProceso(EstrucSched *s);

void CambiarEstado(EstrucSched *s, Proceso* p, Estado newestado);

void DetenerEjecucion (EstrucSched *s);
#endif //rutinas_h