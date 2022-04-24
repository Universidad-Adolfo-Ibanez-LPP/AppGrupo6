#include <stdio.h>
#include <string.h>
#include "libros.h"
#include "pablo.h"

extern Libro libros[];
extern char sedes[1000][100];
extern char pisos[1000][100];
extern char estantes_secciones[1000][100];

void EditSec() {
    char name[50];
    printf("A que libro le deseas cambiar la seccion \n");
    scanf("%s", &name);
    int index= buscar(name);

    int find = 0;

    printf("\nSeccion actual: %s\n", libros[index].estante_seccion);
    printf("Ingrese la seccion nueva:\n");

    scanf(" %[^\n]", name);
    if (strcmp(estantes_secciones[index],name)==0)
    {find=1;}
    if (find == 1) {
        strcpy(libros[index].estante_seccion, name);
        printf("la seccion nueva es: %s\n", libros[index].estante_seccion);
    }
    else {
        printf("No se encuentra la seccion ");
    }
}
void EditSede() {
    char name[50];
    printf("A que libro le deseas cambiar la sede \n");
    scanf("%s", &name);
    int index= buscar(name);

    int find = 0;

    printf("\nSede actual: %s\n", libros[index].sede);
    printf("Ingrese la sede nueva:\n");

    scanf(" %[^\n]", name);
    if (strcmp(sedes[index],name)==0)
    {find=1;}
    if (find == 1) {
        strcpy(libros[index].sede, name);
        printf("la sede nueva es: %s\n", libros[index].sede);
    }
    else {
        printf("No se encuentra la sede ");
    }
}

void EditPiso() {
    char name[50];
    printf("A que libro le deseas cambiar el piso \n");
    scanf("%s", &name);
    int index= buscar(name);

    int find = 0;

    printf("\nPiso actual: %s\n", libros[index].piso);
    printf("Ingrese el piso nuevo:\n");

    scanf(" %[^\n]", name);
    if (strcmp(pisos[index],name)==0)
    {find=1;}
    if (find == 1) {
        strcpy(libros[index].piso, name);
        printf("El piso nuevo es: %s\n", libros[index].piso);
    }
    else {
        printf("No se encuentra el piso ");
    }
}
