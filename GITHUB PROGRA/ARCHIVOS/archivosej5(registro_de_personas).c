/*Crea una estructura para representar una persona con nombre (cadena) y edad (entero). 
El programa debe permitir al usuario ingresar cuantas personas quiera (hasta que desee detenerse).
También debe poder leer el archivo y mostrar los datos del archivo en pantalla. 
Al inicio del programa se solicita al usuario que indique si lo que desea es guardar personas o leer el archivo. 
Guarda todos los registros en un archivo personas.txt, uno por línea, por ejemplo:
Ana 25
Luis 32
Carla 19
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct persona
{
    char nombre [30];
    int edad;
}persona;

void GuardarPersonas()
{
    FILE *archivo;
    int seguir;

    archivo = fopen("personas.txt","a");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.");
        return;
    }

    do
    {
        persona p;/*Se declara una variable de tipo persona para almacenar los datos que se van a guardar en el archivo*/

       printf("Ingrese un nombre: ");
       scanf("%s",&p.nombre);

       printf("Ingrese una edad: ");
       scanf("%d",&p.edad);

       fprintf(archivo,"%s %d",p.nombre, p.edad);

       printf("Desea continuar cargando? 1-si 2-no");
       scanf("%d", &seguir);
        
    } while (seguir == 1);

    fclose(archivo);
    
}
void leerpersonas() 
{
    FILE *archivo = fopen("personas.txt","r");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        exit(1); /*Si no se pudo abrir el archivo, se sale del programa*/
    }

    persona p; /*Se declara una variable de tipo persona para almacenar los datos leidos del archivo*/
    while (fscanf(archivo, "%s %d", p.nombre, &p.edad) == 2) /*fscanf lee el nombre y la edad de cada persona */ 
    /*Lee el archivo mientras fscanf pueda leer 2 elementos (un string y un int)*/
    {
        printf("%s %d\n", p.nombre, p.edad);
    }
    
    fclose(archivo);

}


int main()
{
    int opcion;
    do
    {
        printf("Seleccione una opcion:\n");
        printf("1. Guardar personas\n");
        printf("2. Leer personas\n");
        printf("3.salir\n");

    scanf("%d", &opcion);
    switch (opcion)
    {
        case 1:
            GuardarPersonas();
            break;
        case 2:
            leerpersonas();
            break;
        case 3:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opcion no valida.\n");
            break;
    }
        
    } while (opcion != 3);
    

    return 0;
}
