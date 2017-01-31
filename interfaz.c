//interfaz.c
#include "interfaz.h"
#include "colasPrioridades.h"

// Metodo que imprime opciones en la terminal
void menu(EstrucSched* s){
    
    int opcion=-1;
    
    long pid;
    Estado e;
    short prio;
    float time;
    char* cmd;
    
    printf("\nBienvenido");
    
    while (opcion!=0) {
        printf("\nPlanificador de Procesos A&J\n");
        printf("\n1.- Insertar proceso");
        printf("\n2.- Eliminar proceso");
        printf("\n3.- Iniciar proximo proceso");
        printf("\n4.- Imprimir el contenido del planificador de Procesos");
        printf("\n0.- Salir del programa");
        printf("\n> ");
        
        scanf("%d", &opcion);
        fflush(stdin);
        
        switch (opcion) {
            case 0:
                printf("\n---> Gracias por usar el planificador de Procesos A&J <---\n");
                exit(0);
                
            case 1:
                printf("Indique en el siguiente formato el proceso que desea agregar\n");
                printf("PID Estado Prioridad Tiempo Comando\n");
                scanf("%ld %c %hd %f %s", &pid, &e, &prio, &time, cmd);
                fflush(stdin);
                
                Proceso* p = CrearProceso(pid, e, prio, time, cmd);
                InsertarProceso(s, p, p->prioridad);
                break;
                
            case 2:
                menuInterno(s);
                break;
                
            case 3:
                ProxProceso(s);
                break;
                
            case 4:
                Imprime(s);
                break;
                
            default:
                printf("\nNo ha marcado una opcion valida. Intente nuevamente");
                break;
        }
    }
}

void menuInterno(EstrucSched* s){
    
    int opcion;
    long pid;
    short prio;
    
    printf("\n1.- Eliminar proceso");
    printf("\n2.- Elminar ultimo proceso ejecutado");
    printf("\n0.- Regresar al menu principal");
    printf("\n> ");
    
    scanf("%d", &opcion);
    fflush(stdin);
    
    switch (opcion) {
            
        case 1:
            printf("Introduzca el PID del proceso a eliminar");
            printf("\n> ");
            scanf("%ld", &pid);
            fflush(stdin);
            
            printf("Marque el numero correspondiente a la cola de prioridad del proceso a eliminar:\n1.- q0 \n2.- q1 \n3.- q2 \n4.- q3 \n5.- q4 \n6.- q5");
            printf("\n> ");
            scanf("%hd", &prio);
            fflush(stdin);
            
            ElimProceso (s, pid, prio);
            
            printf("Eliminacion completada\n");
            
            menu(s);
            break;
            
        case 2:
            if (s->enEjecucion) {
                ElimProcesoE(s);
            }
            else
                printf("\nNo se ha podido realizar esta operacion.\nNo hay algun proceso en ejecucion. \nTodos los procesos estan listos para su ejecucion");
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
    Proceso* p;
    s->q0->cabeza = s->q0->primero;
    s->q1->cabeza = s->q1->primero;
    s->q2->cabeza = s->q2->primero;
    s->q3->cabeza = s->q3->primero;
    s->q4->cabeza = s->q4->primero;
    s->q5->cabeza = s->q5->primero;
    
    while (s->q0->cabeza) {
        p = s->q0->cabeza->proceso;
        ImprimeProceso(p);
        s->q0->cabeza = s->q0->cabeza->siguiente;
    }
    
    while (s->q1->cabeza) {
        p = s->q1->cabeza->proceso;
        ImprimeProceso(p);
        s->q1->cabeza = s->q1->cabeza->siguiente;
    }
    
    while (s->q2->cabeza) {
        p = s->q2->cabeza->proceso;
        ImprimeProceso(p);
        s->q2->cabeza = s->q2->cabeza->siguiente;
    }
    
    while (s->q3->cabeza) {
        p = s->q3->cabeza->proceso;
        ImprimeProceso(p);
        s->q3->cabeza = s->q3->cabeza->siguiente;
    }
    
    while (s->q4->cabeza) {
        p = s->q4->cabeza->proceso;
        ImprimeProceso(p);
        s->q4->cabeza = s->q4->cabeza->siguiente;
    }
    
    while (s->q5->cabeza) {
        p = s->q5->cabeza->proceso;
        ImprimeProceso(p);
        s->q5->cabeza = s->q5->cabeza->siguiente;
    }
}

void ImprimeProceso (Proceso* p) {
    printf("\n%ld %c %hd %f %s", p->PID, p->estado, p->prioridad, p->time, p->comando);
}