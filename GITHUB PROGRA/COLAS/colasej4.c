/*Simular turnos de atención
Simular un sistema de turnos con una cola. 
El usuario puede encolar personas por nombre y luego desencolar cuando se atiende una persona. 
Mostrar siempre la cola actual.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Nodo
{
    char nombre[20];
    struct nodo *siguiente;
}Nodo;

void encolar(Nodo **frente,Nodo **fin, char nombre[]) {
    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }
    strcpy(nuevo->nombre, nombre);
    nuevo->siguiente = NULL;

    if (*fin == NULL) {
        *frente = *fin = nuevo;
    } else {
        (*fin)->siguiente = nuevo;
        *fin = nuevo;
    }

    printf("Se encoló: %s\n", nombre);
}

void desencolar(Nodo **frente,Nodo **fin) {
    if (*frente == NULL) {
        printf("La cola está vacía.\n");
        return;
    }

    Nodo *temp = *frente;
    printf("Atendiendo a: %s\n", temp->nombre);
    *frente = (*frente)->siguiente;

    if (*frente == NULL) {
        *fin = NULL;
    }

    free(temp);
}
void mostrar(Nodo *frente) {
    printf("Contenido de la cola:\n");
    while (frente != NULL) {
        printf("%s -> ", frente->nombre);
        frente = frente->siguiente;
    }
    printf("NULL\n");
}

void Mostrarmenu()
{
    printf("\n--- Sistema de Turnos ---\n");
    printf("a) Encolar persona\n");
    printf("b) Atender persona (desencolar)\n");
    printf("c) Mostrar cola actual\n");
    printf("d) Salir\n");
    printf("Elija una opción: ");
}

int main()
{
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    char nombre[20];
    char opcion;

    do
    {
        Mostrarmenu();
        scanf(" %c", &opcion);
        switch (opcion)
        {
        case 'a':
            printf("Ingrese el nombre de la persona a encolar: ");
            scanf("%s", &nombre);
            encolar(&frente, &fin, nombre);
            mostrar(frente);
            break;
        case 'b':
            desencolar(&frente, &fin);
            mostrar(frente);
            break;
        case 'c':
            mostrar(frente);
            break;
        case 'd':
            printf("Saliendo del sistema de turnos.\n");
            break;
        default:
            printf("Opción no válida. Intente de nuevo.\n");
            break;
        }
        
    } while (opcion != 'd');
    
    
    return 0;
}

