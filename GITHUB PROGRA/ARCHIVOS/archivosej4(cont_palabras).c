/*Crea un archivo llamado texto.txt que contenga varias frases escritas por el usuario. 
Luego, haz un programa en C que lea cada línea del archivo y cuente cuántas palabras tiene en total 
(considerando que las palabras están separadas por espacios). 
Usa fgets para leer líneas y luego analiza los caracteres.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *archivo;
    char linea [100];
    int i;

    archivo = fopen("texto.txt","w");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.");
        return 1;
    }
    for ( i = 0; i < 3; i++)
    {
        printf("Escribe una frase: ");
        fgets(linea, sizeof(linea),stdin);

        fputs(linea, archivo);
    }
    fclose(archivo);

    archivo = fopen("texto.txt", "r");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.");
        return 1;
    }
    int total_words = 0;

    while (fgets(linea,sizeof(linea),archivo) != NULL)
    {
        int in_word = 0; // Flag to indicate if we are inside a word
        for (i = 0; linea[i] != '\0'; i++) 
        {
            if (linea[i] != ' ' && linea[i] != '\n' && linea[i] != '\t') 
            {
                if (!in_word) 
                {
                    in_word = 1; // We found the start of a new word
                    total_words++;
                }
            } 
            else 
            {
                in_word = 0; // We are outside a word
            }
        }
         
    }
    
  fclose(archivo);

  printf("El archivo contiene %d palabras.\n",total_words);
  return 0;


}
