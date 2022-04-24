#include "libros.h"
#include <stdio.h>
#include <string.h>

extern Libro libros[];


extern int contador_libro;


int buscar(char *nombre) {

    for (int i = 0; i < contador_libro; ++i) {
        if (strcmp(libros[i].titulo, nombre) == 0) {
            return i;
        }
    }
}

void editar_libro(char *nombre){

    int index=buscar(nombre);

    printf("Que quieres editar de este libro?\n");
    printf("Ingresa el numero para hacer la accion de su derecha\n");
    printf("1. Editar titulo\n");
    printf("2. Editar autor\n");
    printf("3. Editar anio\n");

    int option;
    scanf(" %d",&option);
    switch (option)
    {
    case 1:
        printf("Ingresa el nuevo titulo para el texto %s\n",nombre);
        char nombre[50];
        scanf(" %[^\n]",nombre);
        strcpy(libros[index].titulo,nombre);
        break;

    case 2:

        printf("Ingresa el nuevo autor para el texto %s\n",nombre);
        char autor[50];
        scanf(" %[^\n]",autor);
        strcpy(libros[index].autor,autor);
        break;
    
    case 3:

        printf("Ingresa el nuevo anio para el texto %s\n",nombre);
        char anio[10];
        scanf(" %[^\n]",anio);
        strcpy(libros[index].anio,anio);
        break;


    default:
        break;
    }

}


void borrar_libro(char *nombre) {

     int index=buscar(nombre);

     for (int i = 0; i < contador_libro; ++i) {
         if (strcmp(libros[i].titulo,nombre)==0){
             libros[i].to_delete=1;
        }
    }
    printf("Accion realizada\n");
}



void infoLibro(int index) {
   printf( "Titulo del libro: %s\n", libros[index].titulo);
   printf( "Autor del libro: %s\n", libros[index].autor);
   printf( "Anio de publicacion: %s\n", libros[index].anio);
   printf( "Numero del estante: %s\n", libros[index].estante_numero);
   printf( "Seccion del estante: %s\n", libros[index].estante_seccion);
   printf( "Piso: %s\n", libros[index].piso);
   printf( "Edificio: %s\n", libros[index].edificio);
   printf( "Sede: %s\n", libros[index].sede);
}

void cambiar_sede(int index,char sede[90]){

    strcpy(libros[index].sede,sede);

}


void nuevo(int c_libros){


    if (strstr(libros[c_libros-1].sede,"\n")){
        
    }
    else{
        strcat(libros[c_libros-1].sede,"\n");
    }

    printf("Nombre del libro a ingresar:");
    char nombre[300];
    scanf(" %[^\n]",nombre);
  

    printf("Autor de libro a ingresar:");
    char autor[300];
    scanf(" %[^\n]",autor);


    printf("Anio del libro a ingresar:");
    char anio[300];
    scanf(" %[^\n]",anio);

    printf("Numero del estante de libro a ingresar:");
    char nest[300];
    scanf(" %[^\n]",nest);

    printf("Seccion del libro a ingresar:");
    char seccion[300];
    scanf(" %[^\n]",seccion);

    printf("Piso del libro a ingresar:");
    char piso[300];
    scanf(" %[^\n]",piso);

    printf("Edificio del libro a ingresar:");
    char edificio[300];
    scanf(" %[^\n]",edificio);

    printf("Sede del libro a ingresar:");
    char sede[300];
    scanf(" %[^\n]",sede);

    Libro libro;

    strcpy(libro.titulo,nombre);

    strcpy(libro.autor,autor);

    strcpy(libro.anio,anio);

    strcpy(libro.estante_numero,nest);

    strcpy(libro.estante_seccion,seccion);

    strcpy(libro.piso,piso);

    strcpy(libro.edificio,edificio);

    strcpy(libro.sede,sede);

    libro.to_delete=0;

    libros[c_libros]=libro;
    contador_libro++;


}
