#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Nodo de la PILA*/
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
}Nodo;

/*Agregar (PUSH)*/
void Agregar (Nodo **tope, int valor) {
    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = *tope;
    *tope = nuevo;
    printf("Se apiló: %d\n", valor);
}
/*Sacar(POP)*/
int sacar(Nodo **tope) {
    if (*tope == NULL) {
        printf("La pila está vacía.\n");
        return -1;
    }
    Nodo *temp = *tope;
    int valor = temp->dato;
    *tope = temp->siguiente;
    free(temp);
    return valor;
}
/*Mostrar Pila*/
void mostrar(Nodo *tope) {
    printf("Contenido de la pila:\n");
    while (tope != NULL) {
        printf("%d\n", tope->dato);
        tope = tope->siguiente;
    }
}

/*Implementacion en el Main*/
int main()
{
    Nodo *pila = NULL; /*Se crea la pila*/

    Agregar(&pila,5);
    Agregar(&pila,6);
    Agregar(&pila,7);

    mostrar(pila);

    int desapilado = sacar(&pila); /*Se guarda en la variable desapilado siempre el ultimo numero de la pila.*/

    printf("Se desapilo el %d\n", desapilado);

    mostrar(pila);
    
    return 0;
}
