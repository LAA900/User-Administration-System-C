#include <stdio.h>
#include <time.h>
#include "log.h"

void registrarLog(char *archivoLog,
                  char *accion,
                  char *usuario)
{
    FILE *log = fopen(archivoLog,"a");

    if(log == NULL)
        return;

    time_t t = time(NULL);

    struct tm *tm_info =
        localtime(&t);

    char fecha[30];

    strftime(fecha,
             sizeof(fecha),
             "%Y-%m-%d %H:%M:%S",
             tm_info);

    fprintf(log,
            "%s | admin | %s | %s\n",
            fecha,
            accion,
            usuario);

    fclose(log);
}
