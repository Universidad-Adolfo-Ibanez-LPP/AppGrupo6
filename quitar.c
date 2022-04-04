#include "libros.h"
#include <stdio.h>
#include <string.h>

extern int contador_sede;
extern int contador_libro;
extern Libro libros [];
extern char sedes[1500][100];
extern int contador_piso;
extern char pisos[1500][100];
extern int contador_seccion;
extern char estantes_secciones [1500][100];



int buscar_sede(char *nombre) {

    for (int i = 0; i < contador_libro; ++i) {
        if (strcmp(libros[i].sede, nombre) == 0) {
            return i;
        }
        return -1;
    }
}

int borrar_sedelista(char *nombre) {

    for (int i = 0; i < contador_sede; ++i) {
        if (strcmp(sedes[i],nombre)==0){

                for (i; i < contador_sede - 1; i++) {
                    strcpy(sedes[i], sedes[i + 1]);
                }
                contador_sede-1;
                borrar_sedelista(nombre);
            }
        }
    return 0;
    }

void borrar_sede(char *nombre) {


    for (int i = 0; i < contador_libro; ++i) {
        if (strcmp(libros[i].sede,nombre)==0){
            libros[i].to_delete=1;
        }
    }
    printf("Accion realizada\n");
}

int buscar_piso(char *nombre) {

    for (int i = 0; i < contador_libro; ++i) {
        if (strcmp(libros[i].piso, nombre) == 0) {
            return i;
        }
        return -1;
    }
}
void borrar_piso(char *nombre) {


    for (int i = 0; i < contador_libro; ++i) {
        if (strcmp(libros[i].piso,nombre)==0){
            libros[i].to_delete=1;
        }
    }
    printf("Accion realizada\n");
}

int borrar_pisolista(char *nombre) {

    for (int i = 0; i < contador_piso; ++i) {
        if (strcmp(pisos[i],nombre)==0){

            for (i; i < contador_piso - 1; i++) {
                strcpy(pisos[i], pisos[i + 1]);
            }
            contador_piso-1;
            borrar_pisolista(nombre);
        }
    }
    return 0;
}


int buscar_seccion(char *nombre) {

    for (int i = 0; i < contador_libro; ++i) {
        if (strcmp(libros[i].estante_seccion, nombre) == 0) {
            return i;
        }
        return -1;
    }
}
void borrar_seccion(char *nombre) {


    for (int i = 0; i < contador_libro; ++i) {
        if (strcmp(libros[i].estante_seccion,nombre)==0){
            libros[i].to_delete=1;
        }
    }
    printf("Accion realizada\n");
}

int borrar_seccionlista(char *nombre) {

    for (int i = 0; i < contador_seccion; ++i) {
        if (strcmp(estantes_secciones[i],nombre)==0){

            for (i; i < contador_seccion - 1; i++) {
                strcpy(estantes_secciones[i], estantes_secciones[i + 1]);
            }
            contador_seccion-1;
            borrar_seccionlista(nombre);
        }
    }
    return 0;
}