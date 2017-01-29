#include <stdio.h>
#include "colasPrioridades.h"
#include "interfaz.h"

int main (int argc, char** argv) 
{
    EstrucSched* s = Construye(argv[1]);
    menu (s);
    
	return 0;
}