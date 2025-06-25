#include <stdio.h>
#include <stdlib.h>

/*Declaracion de estructura del nodo*/
typedef struct nododoble
{
    int dato;
    struct nododoble *siguiente;
    struct nododoble *anterior;

}nododoble;

/*Crear NODO*/
nododoble *Crearelemento(int dato)
{

    nododoble *nuevo = (nododoble*)malloc(sizeof(nododoble)); 
    if (nuevo != NULL)
    {
        nuevo->dato = dato;
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL;
    }
    return nuevo;
}
/*ELIMINAR NODO*/
void EliminarNodo(nododoble **cabeza, int dato)
{
    nododoble *actual = *cabeza, *ant = NULL, *sig = NULL;

    while(actual != NULL)
    {
        if(actual->dato == dato)
        {
            if( actual == *cabeza)
            {
                *cabeza = actual->siguiente;
                if( actual->siguiente != NULL)
                    actual->siguiente->anterior = NULL;
            }
            else if( actual->siguiente == NULL)
            {
                ant = actual->anterior;
                actual->anterior = NULL;
                ant->siguiente = NULL;
            }
            else
            {
                ant = actual->anterior;
                actual->anterior = NULL;
                sig = actual->siguiente;
                actual->siguiente = NULL;
                ant->siguiente = sig;
                sig->anterior = ant;
            }
            free(actual);
        }
        actual = actual->siguiente;
    }

}
/*INSERTAR al INICIO*/
void insertarAlInicio(nododoble **cabeza, int dato)
{
    nododoble *nuevo = CrearPersona(dato);
    if (nuevo != NULL)
    {
        nuevo->siguiente = *cabeza;
        nuevo->anterior = NULL;
        if (*cabeza != NULL)
        {
            (*cabeza)->anterior = nuevo;
            *cabeza = nuevo;
        }
        
    }
}
void insertarAlFinal(nododoble **cabeza, int dato)
{
    nododoble *nuevo = CrearPersona(dato);
    if (*cabeza == NULL)
    {
        *cabeza = nuevo;
        return;
    }
    nododoble *temp = *cabeza;
    while (temp->siguiente != NULL)
    {
        temp = temp->siguiente;

    }
    nuevo->anterior = temp; 
    temp->siguiente = nuevo;
}
/*IMPRIMIR LISTA*/
void ImprimirLista(nododoble *cabeza)
{
    nododoble *ntemp = cabeza;
    if (ntemp == NULL)
    {
        printf("La lista esta vacia. \n");
        return;
    }
    printf("Listado de elementos: \n");
    while (ntemp != NULL)
    {
        printf("\n Dato:%d", ntemp->dato);
        ntemp = ntemp->siguiente;
    }

}

int main()
{
    nododoble *cabeza = NULL;

    
    return 0;
}
