/*Crear un programa que permita:
a)encolar una serie de numeros enteros por teclado. Ingresar la cantidad de elementos de la cola.
b)Desencolar los elementos de la cola y cargarlos en un arreglo.
c)Mostrar los elementos del arreglo, usando un procedimiento y respetando el orden de desencolar.

Siguiente
Ordenar los elementos de los arreglos de menor a mayor, usar funcion.
Encolar los elementos del arreglo ordenado
Desencolar los elementos de la cola.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

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

    printf("Se encolo: %d\n", valor);
}

void desencolar(Nodo **frente, Nodo **fin, int *arreglo, int *indice) {
    if (*frente == NULL) {
        printf("La cola esta vacia.\n");
        return;
    }

    Nodo *temp = *frente;
    arreglo[*indice] = temp->dato;
    (*indice)++;
    *frente = (*frente)->siguiente;

    if (*frente == NULL) {
        *fin = NULL;
    }

    free(temp);
}
void mostrarArreglo(int *arreglo, int tam) {
    printf("Elementos del arreglo:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

void ordenarArreglo(int *arreglo, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}




int main()
{
    Nodo *frente = NULL, *fin = NULL;
    int cantidad, valor;
    int arreglo[100];
    
    printf("Ingrese la cantidad de elementos a encolar: ");
    scanf("%d",&cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        printf("Ingrese el elemento a encolar: ");
        scanf("%d",&valor);
        encolar(&frente,&fin,valor);
    }
    int indice=0;
    
    for (int i = 0; i < cantidad; i++)
    {
        desencolar(&frente,&fin,arreglo,&indice);
    }

    mostrarArreglo(arreglo,cantidad);

    ordenarArreglo(arreglo,cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        encolar(&frente,&fin,arreglo[i]);
    }
    printf("Elementos desencolados y ordenados:\n");
    indice = 0; // Reiniciar el índice para desencolar nuevamente
    for (int i = 0; i < cantidad; i++)
    {
        desencolar(&frente,&fin,arreglo,&indice);
    }
    mostrarArreglo(arreglo,cantidad);
    

    return 0;
}
