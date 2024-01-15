#include <stdio.h>
#include "menu.h"

int Menu() {
    int opcion;

    printf("\nMenú de Inventario:\n");
    printf("1. Ingresar producto\n");
    printf("2. Editar producto\n");
    printf("3. Mostrar productos\n");
    printf("5. Salir\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);

    return opcion;
}
