/*Crea un programa que permita al usuario administrar 
un listado de personas que poseen los datos de dni, nombre y apellido. 
El sistema debe permitir llevar adelante las tareas de:
MENU DE OPCIONES:
'i' - Insertar al inicio
'f' - Insertar al final
'e' - Eliminar persona
'm' - Mostrar listado
'b' - Buscar Persona
's' - Salir
Seleccione una opción:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct persona
{
    int dni;
    char nombre[50];
    char apellido[50];
    struct persona *siguiente;
}persona;

typedef struct datos
{
    int dni;
    char nombre[50];
    char apellido[50];
}datos;

persona* CrearPersona (int dni, char nombre[50], char apellido[50])
{
    persona *nuevo = (persona*)malloc(sizeof(persona)); 
    if (nuevo != NULL)
    {
        nuevo->dni = dni;
        strcpy(nuevo->nombre, nombre);
        strcpy(nuevo->apellido, apellido);
        nuevo->siguiente = NULL;
    }
    return nuevo;
}
void eliminarPersona(persona **cabeza, int dni)
{
    persona *temp = *cabeza;
    persona *anterior = NULL;
    while (temp != NULL && temp->dni != dni) 
    {
        anterior = temp;
        temp = temp->siguiente;
    }
    if (temp == NULL)
    {
        printf("Dni no encontrado en la lista.\n");
        return;
    }
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
    printf("Persona con dni: %d eliminado\n",dni);
}
void insertarAlInicio(persona **cabeza, int dni, char nombre[50], char apellido[50])
{
    persona *nuevo = CrearPersona(dni,nombre,apellido);
    if (nuevo != NULL)
    {
        nuevo->siguiente = *cabeza;
        *cabeza = nuevo;
    }
};
void insertarAlFinal(persona **cabeza, int dni, char nombre[50], char apellido[50])
{
    persona *nuevo = CrearPersona(dni,nombre,apellido);
    if (*cabeza == NULL)
    {
        *cabeza = nuevo;
        return;
    }
    persona *temp = *cabeza;
    while (temp->siguiente != NULL)
    {
        temp = temp->siguiente;

    }
    temp->siguiente = nuevo;
}
void ImprimirLista(persona *cabeza)
{
    persona *ntemp = cabeza;
    if (ntemp == NULL)
    {
        printf("La lista esta vacia. \n");
        return;
    }
    printf("Listado de personas: \n");
    while (ntemp != NULL)
    {
        printf("\n Dni:%d | Nombre: %s | Apellido: %s \n", ntemp->dni, ntemp->nombre, ntemp->apellido);
        ntemp = ntemp->siguiente;
    }

}
void BuscarPersona (persona *cabeza, int dni, char nombre[50], char apellido[50])
{
    
    persona *temp = cabeza;
    while (temp != NULL)
    {
        if (temp->dni == dni && strcmp(temp->nombre, nombre) == 0 && strcmp(temp->apellido, apellido) == 0)
        {
            printf("\n Dni:%d | Nombre: %s | Apellido: %s \n", temp->dni, temp->nombre, temp->apellido);
            return;
        }
        temp = temp->siguiente;
    }
    printf("Persona no encontrada en la lista.\n");

}
void MostrarMenu()
{
    printf("MENU DE OPCIONES:\n");
    printf("'i' - Insertar al inicio\n");
    printf("'f' - Insertar al final\n");
    printf("'e' - Eliminar persona\n");
    printf("'m' - Mostrar listado\n");
    printf("'b' - Buscar Persona\n");
    printf("'s' - Salir\n");
    printf("Seleccione una opción:\n");
}

datos pedirdatos()
{
    datos d;
    printf("Ingrese el DNI de la persona: ");
    scanf("%d", &d.dni);
    printf("Ingrese el nombre de la persona: ");
    scanf("%s", d.nombre);
    printf("Ingrese el apellido de la persona: ");
    scanf("%s", d.apellido);
    return d;

}
int main()
{

    int dni;
    persona *cabeza = NULL; // Inicializamos la cabeza de la lista como NULL
    char opcion;
    datos d; // Estructura para almacenar los datos de la persona
    do
    {
        MostrarMenu();
        scanf(" %c",&opcion);
        if (opcion == 's')
        {
            break;
        }
        switch (opcion)
        {
            case 'i':
                d = pedirdatos();
                insertarAlInicio(&cabeza, d.dni, d.nombre, d.apellido);
                break;
            case 'f':
                d = pedirdatos();
                insertarAlFinal(&cabeza, d.dni, d.nombre, d.apellido);
                break;
            case 'e':
                printf("Ingrese el DNI de la persona a eliminar: ");
                scanf("%d", &dni);
                eliminarPersona(&cabeza, dni);
                break;
            case 'm':
                ImprimirLista(cabeza);
                break;
            case 'b':
                d = pedirdatos();
                BuscarPersona(cabeza, d.dni, d.nombre, d.apellido);
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }

    } while (opcion != 's');
    
    return 0;
}
