#include "interfaz.h"
#include "colasPrioridades.h"

// Metodo que imprime opciones en la terminal
void menu(EstrucSched* s){

	int opcion=-1;

    long pid;
    Estado e;
    short prio;
    float time;
    char *cmd;
    
    printf("\nBienvenido al Planificador de Procesos A&J\n");

	while (opcion!=0) {
		printf("\n1.- Insertar proceso");
		printf("\n2. Eliminar proceso");
		printf("\n3. Imprimir el contenido del planificador de Procesos");
		printf("\n0. Salir del programa");
		printf("\n>>>>>> ");
        
        
		scanf("%d", &opcion);
        
        switch (opcion) {
            case 0:
                printf("Gracias por usar el planificador de Procesos A&J\n\n");
                break;
            case 1:
                printf("Indique en el siguiente formato el proceso que desea agregar\n");
                printf("PID Estado Prioridad Tiempo Comando\n");
                scanf("%ld %c %hd %f %s", &pid, &e, &prio, &time, cmd);
            
                Proceso* p = CrearProceso(pid, e, prio, time, cmd);
                InsertarProceso(s, p, p->prioridad);
            
                menu(s);
                break;
            case 2:
                menuInterno(s);
                menu(s);
                break;

            case 3:
                Imprime(s);
                menu(s);
                break;
                
            default:
                printf("Opcion Invalida. Intente nuevamente\n");
                menu(s);
                break;
        }
    }
}

void menuInterno(EstrucSched* s){
   
    int opcion;
    long pid;
    short prio;
    
    printf("\n1. Eliminar proceso");
    printf("\n2. Elminar ultimo proceso ejecutado");
    printf("\n0. Regresar al menu principal");

    printf("\n >>>>>> ");
    
    scanf("%d", &opcion);

    switch (opcion) {
            
        case 1:
            printf("Introduzca el PID del proceso a eliminar");
            scanf("%ld", &pid);
            printf("Marque el numero correspondiente a la cola de prioridad del proceso a eliminar:\n1. q0, \n2. q1, \n3. q2, \n4. q3, \n5. q4, \n6. q5?");
            scanf("%hd", &prio);
            
            ElimProceso (s, pid, prio);
            
            printf("Eliminacion completada\n");
            
            menu(s);
            break;
            
        case 2:
            ElimProcesoE(s);
            printf("Eliminacion completada\n");
            menu(s);
            break;
            
        case 0:
            printf("Devuelta al menu principal\n");
            menu(s);
            break;
            
        default:
            printf("No ha introducido una opcion valida. Vuelva a intentarlo \n");
            menuInterno(s);
            break;
    }
}

void Imprime(EstrucSched *s){
    printf("Hola voy a intentar imprimir");

    Proceso* p;
    s->q0->cabeza = s->q0->primero;
    while (s->q0->cabeza) {
        p = s->q0->cabeza->proceso;
        printf("%ld %c %hd %f %s", p->PID, p->estado, p->prioridad, p->time, p->comando);
        s->q0->cabeza = s->q0->cabeza->siguiente;
    }
    
    while (s->q1->cabeza) {
        printf("%ld %c %hd %f %s", s->q1->cabeza->proceso->PID, s->q1->cabeza->proceso->estado, s->q1->cabeza->proceso->prioridad, s->q1->cabeza->proceso->time, s->q1->cabeza->proceso->comando);
        s->q1->cabeza = s->q1->cabeza->siguiente;
    }
    
    while (s->q2->cabeza) {
        printf("%ld %c %hd %f %s", s->q2->cabeza->proceso->PID, s->q2->cabeza->proceso->estado, s->q2->cabeza->proceso->prioridad, s->q2->cabeza->proceso->time, s->q2->cabeza->proceso->comando);
        s->q2->cabeza = s->q2->cabeza->siguiente;
    }
    
    while (s->q3->cabeza) {
        printf("%ld %c %hd %f %s", s->q3->cabeza->proceso->PID, s->q3->cabeza->proceso->estado, s->q3->cabeza->proceso->prioridad, s->q3->cabeza->proceso->time, s->q3->cabeza->proceso->comando);
        s->q3->cabeza = s->q3->cabeza->siguiente;
    }
    
    while (s->q4->cabeza) {
        printf("%ld %c %hd %f %s", s->q4->cabeza->proceso->PID, s->q4->cabeza->proceso->estado, s->q4->cabeza->proceso->prioridad, s->q4->cabeza->proceso->time, s->q4->cabeza->proceso->comando);
        s->q4->cabeza = s->q4->cabeza->siguiente;
    }
    
    while (s->q5->cabeza) {
        printf("%ld %c %hd %f %s", s->q5->cabeza->proceso->PID, s->q5->cabeza->proceso->estado, s->q5->cabeza->proceso->prioridad, s->q5->cabeza->proceso->time, s->q5->cabeza->proceso->comando);
        s->q5->cabeza = s->q5->cabeza->siguiente;
    }
}