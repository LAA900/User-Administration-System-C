#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "usuario.h"

int main(int argc,char *argv[])
{
    char archivoUsuarios[100] = "usuarios.dat";

    char archivoLog[100] = "transacciones.log";

    for(int i=1;i<argc;i++)
    {
        if(strcmp(argv[i],"-u") == 0)
        {
            if(i+1 < argc)
            {
                strcpy(archivoUsuarios,argv[++i]);
            }
        }
        else if(strcmp(argv[i],"-a")==0)
        {
            if(i+1<argc)
            {
                strcpy(archivoLog,argv[++i]);
            }
        }
        else if(strcmp(argv[i],"-n")==0)
        {
            remove(archivoLog);
        }
    }

    cargarUsuarios(archivoUsuarios);

    int opcion;

    do
    {
        printf("\n1 Crear\n");
        printf("2 Listar\n");
        printf("3 Modificar\n");
        printf("4 Bloquear\n");
        printf("5 Eliminar\n");
        printf("0 Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                crearUsuario(archivoLog);
                break;

            case 2:
                listarUsuarios(archivoLog);
                break;

            case 3:
                modificarUsuario(archivoLog);
                break;

            case 4:
                cambiarEstado(archivoLog);
                break;

            case 5:
                eliminarUsuario(archivoLog);
                break;

            case 0:
                guardarUsuarios(archivoUsuarios);
                break;

            default:
                printf(
                    "Opcion invalida\n");
        }

    }while(opcion!=0);

    return 0;
}
