# User Management System (C)

Aplicación desarrollada en lenguaje C para la administración de usuarios mediante persistencia en archivos y registro de auditoría.

## Descripción

Este proyecto implementa un sistema de gestión de usuarios desde consola, permitiendo realizar operaciones de creación, consulta, modificación, bloqueo y eliminación de cuentas.

La información se almacena de forma persistente en archivos, mientras que las acciones realizadas sobre los usuarios son registradas automáticamente en un archivo de auditoría.

Además, la aplicación permite configurar los nombres de los archivos utilizados mediante argumentos de línea de comandos.

## Funcionalidades

- Crear usuarios.
- Listar usuarios registrados.
- Modificar información de usuarios.
- Bloquear y desbloquear usuarios.
- Eliminar usuarios.
- Persistencia de datos mediante archivos.
- Registro de acciones en archivo de auditoría.
- Configuración mediante argumentos de línea de comandos.

## Tecnologías Utilizadas

- Lenguaje C
- GCC
- Make
- Archivos de texto

## Conceptos Aplicados

- Programación estructurada.
- Modularización mediante archivos `.c` y `.h`.
- Uso de estructuras (`struct`).
- Manejo de archivos.
- Argumentos de línea de comandos.
- Registro de auditoría (logging).
- Persistencia de datos.

## Estructura del Proyecto

```text
User-Management-System-C/
│
├── README.md
├── Makefile
├── .gitignore
│
└── src/
    ├── main.c
    ├── usuario.c
    ├── usuario.h
    ├── log.c
    └── log.h
```

## Compilación

Compilar el proyecto utilizando:

```bash
make
```

## Ejecución

Ejecutar el programa:

```bash
./usuarios
```

### Parámetros disponibles

Especificar archivo de usuarios:

```bash
./usuarios -u usuarios.dat
```

Especificar archivo de auditoría:

```bash
./usuarios -a transacciones.log
```

Especificar ambos:

```bash
./usuarios -u usuarios.dat -a transacciones.log
```

Eliminar el archivo de auditoría antes de iniciar:

```bash
./usuarios -n
```

## Menú Principal

El sistema permite realizar las siguientes operaciones:

```text
1 Crear
2 Listar
3 Modificar
4 Bloquear
5 Eliminar
0 Salir
```

## Aspectos Destacados

- Implementación completa de operaciones CRUD sobre usuarios.
- Persistencia de información entre ejecuciones.
- Sistema de auditoría para registrar acciones realizadas.
- Configuración flexible mediante argumentos de línea de comandos.
- Separación de responsabilidades mediante módulos independientes.

## Autoría

Proyecto académico desarrollado en lenguaje C.

Este repositorio se mantiene con fines de portafolio y demostración técnica.
