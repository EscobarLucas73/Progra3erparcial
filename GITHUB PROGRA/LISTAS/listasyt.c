#include <stdlib.h>
#include <stdio.h>
/*Definicion de estructura del nodo*/
typedef struct nodo
{
    int dato;
    struct nodo *siguiente;
}nodo;

/*Funcion CREAR NODO*/
nodo* CrearNodo (int dato)
{
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));/*Reserva memoria dinamica*/
    if (nuevo != NULL)
    {
        nuevo->dato = dato;
        nuevo->siguiente = NULL;
    }
    return nuevo;
};
void eliminarNodo(nodo **cabeza, int dato)
{
    nodo *temp = *cabeza;
    nodo *anterior = NULL;
    while (temp != NULL && temp->dato != dato) 
    {
        anterior = temp;
        temp = temp->siguiente;
    }
    if (temp == NULL)
        printf("Valor no encontrado en la lista.\n");
        return; 

    if (anterior == NULL)
    {
        // El nodo a eliminar es el primero
        *cabeza = temp->siguiente;
    }
    else
    {
        // Saltamos el nodo a eliminar
        anterior->siguiente = temp->siguiente;
    }

    free(temp); // Liberamos la memoria del nodo eliminado
    printf("Nodo con valor %d eliminado",dato);
}
/*Funcion INSERTAR AL INICIO*/
void insertarAlInicio(nodo **cabeza, int dato)
{
    nodo *nuevo = CrearNodo(dato);
    if (nuevo != NULL)
    {
        nuevo->siguiente = *cabeza;
        *cabeza = nuevo;
    }
    
};
/*Funcion MOSTRAR LA LISTA*/
void ImprimirLista(nodo *cabeza)
{

    nodo *ntemp = cabeza;
    if (ntemp == NULL)
    {
        printf("La lista esta vacia. \n");
        return;
    }
    printf("Valores de la lista: \n");
    while (ntemp != NULL)
    {
        printf(" %d ", ntemp->dato);
        ntemp = ntemp->siguiente;
    }

}
/*Funcion INSERTAR AL FINAL*/
void insertarAlFinal(nodo **cabeza, int dato)
{
    nodo *nuevo = CrearNodo(dato);
    if (*cabeza == NULL)
    {
        *cabeza = nuevo;
        return;
    }
    nodo *temp = *cabeza;
    while (temp->siguiente != NULL)
    {
        temp = temp->siguiente;

    }
    temp->siguiente = nuevo;
}
/*Funcion BUSCAR DATO*/
void Buscardato (nodo *cabeza, int dato)
{
    nodo *temp = cabeza;
    while (temp != NULL)
    {
        if (temp->dato == dato)
        {
            printf("\nSe ha encontrado el dato en la lista.\n");
            return;
        }
        temp = temp->siguiente;
    }
    printf("Valor no encontrado en la lista.\n");

}

int main()
{
    nodo *cabeza = NULL;
    /*nodo *nuevo;/*Se define la estructura de un nodo llamado nuevo de tipo puntero

    nuevo = CrearNodo(5);
    printf("El dato del nuevo nodo es %d ", nuevo->dato);*/

    insertarAlInicio(&cabeza, 8);
    insertarAlInicio(&cabeza, 1);
    insertarAlFinal(&cabeza, 15);
    insertarAlFinal(&cabeza, 54);
    ImprimirLista(cabeza);
    Buscardato(cabeza, 15);





    
    return 0;
}
