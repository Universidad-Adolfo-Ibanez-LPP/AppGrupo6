
#include "libros.h"
#include <stdio.h>
#include <string.h>

extern Libro libros[];
extern int contador_libro;
extern int contador_sede;
extern int contador_seccion;
extern int contador_piso;
extern char sedes[1000][100];
extern char pisos[1000][100];
extern char estantes_secciones[1000][100];


void llenar(){
        for (int i = 0; i < contador_libro; ++i) {
        strcpy(sedes[i], libros[i].sede);
        strcpy(pisos[i], libros[i].piso);
        strcpy(estantes_secciones[i], libros[i].estante_seccion);
        }
}

void sede_add(char * sede){
    strcpy(sedes[contador_sede],sede);
    contador_sede++;
}

void piso_add(char * piso){
    strcpy(pisos[contador_piso],piso);
    contador_piso++;
}

void seccion_add(char * estant_seccion){
    strcpy(estantes_secciones[contador_seccion],estant_seccion);
    contador_seccion++;
}
