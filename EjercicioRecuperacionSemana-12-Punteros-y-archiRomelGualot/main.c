//Romel Gualoto Taller semana 12
//Realizar un programa que permita controlar el inventario de una libreria en la cual los empleados puedan ingresar productos (numero de productos, nombre y la cantidad y el precio del producto)
//Que les permita editar los productos que ya estan en el inventario
//Que les permita sacar los datos de los productos que ya estan en el inventario y que todo esto se vaya guardando en un archivo txt 
//Ejercicio tomado de repositorio de ejercicio de curso de coursera "Archivos y punteros en C"
#include <stdio.h>
#include "lecturas.h"
#include "funciones.h"
#include "menu.h"
#define F 100
#define C 15

FILE*archivo;

int main() {
    char NombreProducto[F][C];
    int cantidadProductos[F];
    float precio[F];
    printf("Bienvenido al inventario de Libreria Las dalias  \n");
    if ((archivo = fopen("inventario.txt", "a+")) != NULL) {
        int tamanio;
        int opcion;
        do {
            opcion = Menu();
            switch (opcion) {
                case 1:
                    ingresarProductos(&tamanio, NombreProducto, precio, cantidadProductos);
                    guardarEnArchivo(tamanio, NombreProducto, precio, cantidadProductos);
                    break;
                case 2:
                    modificarProductos();
                    break;
                case 3:
                    sacarDatos(NombreProducto, precio, cantidadProductos);
                    break;
            }
        } while (opcion != 4);
    } else {
        printf("Lamentablemente el archivo no logro abrirse\n");
    }

    fclose(archivo);
    return 0;
}