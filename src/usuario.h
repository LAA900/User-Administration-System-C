#ifndef USUARIO_H
#define USUARIO_H

#define MAX_USUARIOS 20
#define MAX_CADENA 15

typedef struct
{
    int id;

    char usuario[MAX_CADENA+1];
    char nombre[MAX_CADENA+1];
    char grupo[MAX_CADENA+1];
    char password[MAX_CADENA+1];

    int estado;

} Usuario;

extern Usuario usuarios[MAX_USUARIOS];

extern int totalUsuarios;

void cargarUsuarios(char *archivo);

void guardarUsuarios(char *archivo);

void crearUsuario(char *archivoLog);

void listarUsuarios(char *archivoLog);

void modificarUsuario(char *archivoLog);

void cambiarEstado(char *archivoLog);

void eliminarUsuario(char *archivoLog);

int buscarPorID(int id);

int buscarPorNombre(char *usuario);

#endif
