#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo
{
    int dato;
    struct nodo *siguiente;
}Nodo;
/*ENCOLAR(agregar al final)*/
void encolar(Nodo **frente,Nodo **fin, int valor) {
    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (*fin == NULL) {
        *frente = *fin = nuevo;
    } else {
        (*fin)->siguiente = nuevo;
        *fin = nuevo;
    }

    printf("Se encoló: %d\n", valor);
}

// DESENCOLAR (sacar del frente)
int desencolar(Nodo **frente,Nodo **fin) {
    if (*frente == NULL) {
        printf("La cola está vacía.\n");
        return -1;
    }

    Nodo *temp = *frente;
    int valor = temp->dato;
    *frente = (*frente)->siguiente;

    if (*frente == NULL) {
        *fin = NULL;
    }

    free(temp);
    return valor;
}

// Mostrar la cola
void mostrar(Nodo *frente) {
    printf("Contenido de la cola:\n");
    while (frente != NULL) {
        printf("%d -> ", frente->dato);
        frente = frente->siguiente;
    }
    printf("NULL\n");
}
/*Implementacion en el main*/
int main()
{
    Nodo *frente = NULL;
    Nodo *fin = NULL;

    encolar(&frente, &fin, 5);
    encolar(&frente, &fin, 6);
    encolar(&frente, &fin, 7);

    mostrar(frente);

    int desencolado = desencolar(&frente, &fin);
    printf("\nSe desencolo: %d", desencolado);
    mostrar(frente);
    
    return 0;
}
