/*dada una lista doblemente encadenada (doblemente enlazada)
a)ingresar por teclado la cantidad de elementos que va a tener la lista.
b)cargar la lista e indicar si se pudo cargar la cantidad indicada.
c) mostrar la lista de adelante hacia atras y viceversa.
ingresar un elemento por teclado, si es menor al primer elemento de la lista, insertarlo adelante, 
si es mayor que el ultimo elemento de la lista insertarlo al final, en otro caso mostrar mensaje de error por pantalla.
Mostrar el nuevo contenido de la lista en el sentido que corresponda con la insercion que se hizo.*/
#include <stdio.h>
#include <stdlib.h>

// Definición del nodo de la lista doblemente enlazada
typedef struct Nodo {
    int dato;
    struct Nodo *ant;
    struct Nodo *sig;
} Nodo;

// Crear nuevo nodo
Nodo* crearNodo(int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    nuevo->dato = valor;
    nuevo->ant = NULL;
    nuevo->sig = NULL;
    return nuevo;
}

// Insertar al final
void insertarFinal(Nodo **inicio, Nodo **fin, int valor) {
    Nodo* nuevo = crearNodo(valor);
    if (*inicio == NULL) {
        *inicio = *fin = nuevo;
    } else {
        (*fin)->sig = nuevo;
        nuevo->ant = *fin;
        *fin = nuevo;
    }
}

// Mostrar lista hacia adelante
void mostrarAdelante(Nodo *inicio) {
    printf("Lista de adelante hacia atrás:\n");
    Nodo* actual = inicio;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->sig;
    }
    printf("\n");
}

// Mostrar lista hacia atrás
void mostrarAtras(Nodo *fin) {
    printf("Lista de atrás hacia adelante:\n");
    Nodo* actual = fin;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->ant;
    }
    printf("\n");
}

// Insertar al principio
void insertarInicio(Nodo **inicio, Nodo **fin, int valor) {
    Nodo* nuevo = crearNodo(valor);
    if (*inicio == NULL) {
        *inicio = *fin = nuevo;
    } else {
        nuevo->sig = *inicio;
        (*inicio)->ant = nuevo;
        *inicio = nuevo;
    }
}

int main() {
    Nodo *inicio = NULL, *fin = NULL;
    int n, valor;

    // a) Ingresar cantidad de elementos
    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &n);

    // b) Cargar lista
    for (int i = 0; i < n; i++) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &valor);
        insertarFinal(&inicio, &fin, valor);
    }

    // Verificar carga
    int cont = 0;
    Nodo* aux = inicio;
    while (aux != NULL) {
        cont++;
        aux = aux->sig;
    }
    if (cont == n) {
        printf("Se cargaron correctamente los %d elementos.\n", n);
    } else {
        printf("Error: Se cargaron solo %d elementos.\n", cont);
    }

    // c) Mostrar lista en ambos sentidos
    mostrarAdelante(inicio);
    mostrarAtras(fin);

    // Ingresar nuevo elemento y decidir dónde insertarlo
    printf("Ingrese un nuevo elemento a insertar: ");
    scanf("%d", &valor);

    if (valor < inicio->dato) {
        insertarInicio(&inicio, &fin, valor);
        printf("Elemento insertado al principio.\n");
        mostrarAdelante(inicio);
    } else if (valor > fin->dato) {
        insertarFinal(&inicio, &fin, valor);
        printf("Elemento insertado al final.\n");
        mostrarAtras(fin);
    } else {
        printf("ERROR: El valor no es menor al primero ni mayor al último. No se insertó.\n");
    }

    // Liberar memoria
    aux = inicio;
    while (aux != NULL) {
        Nodo* temp = aux;
        aux = aux->sig;
        free(temp);
    }

    return 0;
}