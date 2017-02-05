//  proceso.h
//  Planificador de procesos
//
//  Created by Juan Ortiz & Andres Buelvas on 29/1/17.
//  Copyright © 2017 Juan Ortiz & Andres Buelvas. All rights reserved.
//

#ifndef proceso_h
#define proceso_h

typedef char Estado;

typedef struct Proceso {
	long PID;
	Estado estado;
	short prioridad;
	float time;
	char comando [20];
} Proceso;

Proceso* CrearProceso (long pid, Estado e, short prio, float time, char* cmd);

#endif /* proceso_h */
