//  main.c
//  Planificador de procesos
//
//  Created by Juan Ortiz & Andres Buelvas on 29/1/17.
//  Copyright © 2017 Juan Ortiz & Andres Buelvas. All rights reserved.
//

#include "colasPrioridades.h"
#include "interfaz.h"

int main (int argc, char** argv) 
{
    EstrucSched* s = NULL;
    s = Construye(argv[1]);
    menu (s, argv[2]);
    
	return 0;
}