#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "libros.h"
#include "archivo.h"

extern Libro libros[];
extern int contador_libro;

int leer(int argc, char *argv[]){
        char archivo[30];

    strcpy(archivo,argv[1]);

    FILE *fp = fopen(archivo,"r"); //abrir en write
    if (!fp){
        printf("FP NO EXISTE");
    }

    char buff[2000];
    int contador_fila = 0;
    int contador_campo = 0;

    int i = 0;

    while(fgets(buff,2000,fp)){
        contador_campo = 0;
        contador_fila ++;

        if(contador_fila == 1){
            continue; //No nos importa la primer fila, ya que son los nombres de cada columna
        }


        char *campo = strtok(buff,","); //Separa una string en una serie de "tokens" usando el delimitador coma https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm

        while (campo){

             switch(contador_campo){
                 case 0: strcpy(libros[i].titulo,campo);
                 break;

                 case 1: strcpy(libros[i].autor,campo);
                 break;

                 case 2: strcpy(libros[i].anio,campo);
                 break;

                case 3: strcpy(libros[i].estante_numero,campo);
                 break;

                 case 4: strcpy(libros[i].estante_seccion,campo);
                 break;

                 case 5: strcpy(libros[i].piso,campo);
                 break;

                 case 6: strcpy(libros[i].edificio,campo);
                 break;

                 case 7: strcpy(libros[i].sede,campo);
                 break;

                 default:
                     break;
             }
             campo = strtok(NULL,","); //actualizar valor del campo
             contador_campo ++;
        }
        libros[i].to_delete=0;
        i++;

    }

    fclose(fp);

    contador_libro=contador_fila-1;


}


void guardar(int argc, char *argv[]){
    char archivo[30];
    strcpy(archivo,argv[1]);
    FILE *fput;
    fput= fopen(archivo,"w"); //abrir en write

    fprintf(fput,"titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");
    for (int i=0; i<contador_libro;++i){
        if (libros[i].to_delete !=1){
            fprintf(fput,"%s,%s,%s,%s,%s,%s,%s,%s",libros[i].titulo,libros[i].autor,libros[i].anio,libros[i].estante_numero,libros[i].estante_seccion,libros[i].piso,libros[i].edificio,libros[i].sede);
        }
    }

    fclose(fput);
}
