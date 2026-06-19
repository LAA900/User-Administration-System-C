#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "usuario.h"
#include "log.h"

#define MAX_USUARIOS 20
#define MAX_CADENA 15


Usuario usuarios[MAX_USUARIOS];
int totalUsuarios = 0;

void crearUsuario(char *archivoLog) {

    if (totalUsuarios >= MAX_USUARIOS) {
        printf("Limite alcanzado.\n");
        return;
    }

    Usuario nuevo;

    nuevo.id = (totalUsuarios == 0)
               ? 1
               : usuarios[totalUsuarios - 1].id + 1;

    printf("Usuario: ");
    scanf("%15s", nuevo.usuario);

    if(buscarPorNombre(nuevo.usuario) != -1)
    {
    	printf("El usuario ya existe.\n");
    	return;
    }

    printf("Nombre completo: ");
    scanf("%15s", nuevo.nombre);

    printf("Grupo: ");
    scanf("%15s", nuevo.grupo);

    printf("Password: ");
    scanf("%15s", nuevo.password);

    nuevo.estado = 1;

    usuarios[totalUsuarios++] = nuevo;

    registrarLog(archivoLog,"CREAR",nuevo.usuario);

    printf("Usuario creado.\n");
}

void listarUsuarios(char *archivoLog) {

    printf("\n---- LISTA DE USUARIOS ----\n");

    for (int i = 0; i < totalUsuarios; i++) {

        printf("ID: %d\n",
               usuarios[i].id);

        printf("Nombre: %s\n",
               usuarios[i].nombre);

        printf("Grupo: %s\n",
               usuarios[i].grupo);

        printf("Estado: %s\n\n",
               usuarios[i].estado
               ? "Activo"
               : "Bloqueado");
    }

    registrarLog(archivoLog,"LISTAR","-");
}

int buscarPorID(int id) {

    for (int i = 0; i < totalUsuarios; i++) {

        if (usuarios[i].id == id)
            return i;
    }

    return -1;
}

int buscarPorNombre(char nombre[]) {

    for (int i = 0; i < totalUsuarios; i++) {

        if (strcmp(usuarios[i].usuario,
                   nombre) == 0)
            return i;
    }

    return -1;
}

void modificarUsuario(char *archivoLog) {

    int id;

    printf("Ingrese ID: ");
    scanf("%d", &id);

    int pos = buscarPorID(id);

    if (pos == -1) {
        printf("No encontrado.\n");
        return;
    }

    printf("Nuevo nombre: ");
    scanf("%15s", usuarios[pos].nombre);

    printf("Nuevo grupo: ");
    scanf("%15s", usuarios[pos].grupo);

    printf("Nueva password: ");
    scanf("%15s", usuarios[pos].password);

    registrarLog(archivoLog,"MODIFICAR",usuarios[pos].usuario);

    printf("Usuario actualizado.\n");
}

void cambiarEstado(char *archivoLog) {

    int id;

    printf("Ingrese ID: ");
    scanf("%d", &id);

    int pos = buscarPorID(id);

    if (pos == -1) {
        printf("No encontrado.\n");
        return;
    }

    usuarios[pos].estado =
        !usuarios[pos].estado;

    if (usuarios[pos].estado)
        registrarLog(archivoLog,"DESBLOQUEAR",usuarios[pos].usuario);
    else
        registrarLog(archivoLog,"BLOQUEAR",usuarios[pos].usuario);

    printf("Estado actualizado.\n");
}

void eliminarUsuario(char *archivoLog) {

    int id;
    char confirmar;

    printf("ID a eliminar: ");
    scanf("%d", &id);

    int pos = buscarPorID(id);

    if (pos == -1) {
        printf("No encontrado.\n");
        return;
    }

    printf("Confirmar (s/n): ");
    scanf(" %c", &confirmar);

    if (confirmar != 's' &&
        confirmar != 'S')
        return;

    registrarLog(archivoLog,"ELIMINAR",usuarios[pos].usuario);

    for (int i = pos;
         i < totalUsuarios - 1;
         i++) {

        usuarios[i] =
            usuarios[i + 1];
    }

    totalUsuarios--;

    printf("Usuario eliminado.\n");
}

void guardarUsuarios(char *archivo) {

    printf("Guardando en: %s\n", archivo);

    FILE *f = fopen(archivo, "w");


    if (f == NULL) {
        printf("Error archivo.\n");
        return;
    }

    for (int i = 0;
         i < totalUsuarios;
         i++) {

        fprintf(
            f,
            "%d,%s,%s,%s,%s,%d\n",
            usuarios[i].id,
            usuarios[i].usuario,
            usuarios[i].nombre,
            usuarios[i].grupo,
            usuarios[i].password,
            usuarios[i].estado
        );
    }

    printf("Total usuarios = %d\n", totalUsuarios);

    fclose(f);
}

void cargarUsuarios(char *archivo)
{
    FILE *f = fopen(archivo,"r");

    if(f == NULL)
        return;

    totalUsuarios = 0;

    while(
        fscanf(f,
        "%d,%15[^,],%15[^,],%15[^,],%15[^,],%d\n",
        &usuarios[totalUsuarios].id,
        usuarios[totalUsuarios].usuario,
        usuarios[totalUsuarios].nombre,
        usuarios[totalUsuarios].grupo,
        usuarios[totalUsuarios].password,
        &usuarios[totalUsuarios].estado
        ) == 6
    )
    {
        totalUsuarios++;

        if(totalUsuarios >= MAX_USUARIOS)
            break;
    }

    fclose(f);
}
