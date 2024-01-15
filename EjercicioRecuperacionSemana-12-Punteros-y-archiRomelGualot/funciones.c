#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarProductos(int *cantidad, char productos[][C], float precio[], int cantidadProductos[]){
  printf("Ingrese el numero de productos\n");
  int num;
  scanf("%d", &num);
  *cantidad = num;
  for (int i = 0; i < *cantidad; i++){
    printf("Ingrese el nombre del producto %d: \n", i+1);
    scanf("%s", productos[i]);
    printf("Ingrese la cantidad del producto %d: \n", i+1);
    scanf("%d", &cantidadProductos[i]);
    printf("Ingrese el precio del producto %d: \n", i+1);
    scanf("%f", &precio[i]);
  }
}

void guardarEnArchivo(const int cantidad, char productos[][C], float precio[], int cantidadProductos[]){
  FILE *archivo;
  if ((archivo = fopen("inventario.txt", "a+")) != NULL){
    for (int i = 0; i < cantidad; i++){
      fprintf(archivo, "\n");
      fputs (productos[i], archivo);
      fputs (" ", archivo);
      fprintf(archivo, "%d", cantidadProductos[i]);
      fputs (" ", archivo);
      fprintf(archivo, "%.2f", precio[i]);
      fputs ("\n", archivo); 
    }
  }else
    printf( "Lamentablemente el archivo no logro abrirse" );

  fclose (archivo);
}

void modificarProductos() {
  FILE *archivo;
  if ((archivo = fopen("inventario.txt", "r+")) != NULL) {
    char productos[50];
    int cantidadProductos;
    float precio;
    long posicion = 0;
    printf("Ingrese el nombre del producto que desea editar: \n");
    char nuevoProducto[50];
    scanf("%s", nuevoProducto);
    rewind(archivo);
    while (fscanf(archivo, "%s %d %f", productos, &cantidadProductos, &precio) != EOF) {
      posicion = ftell(archivo);
      if (strcmp(productos, nuevoProducto) == 0) {
        fseek(archivo, posicion - strlen(productos) - sizeof(int) - sizeof(float), SEEK_SET);
        printf("Ingrese el nuevo nombre del producto: \n");
        scanf("%s", productos);
        printf("Ingrese la nueva cantidad del producto: \n");
        scanf("%d", &cantidadProductos);
        printf("Ingrese el nuevo precio del producto: \n");
        scanf("%f", &precio);
        fprintf(archivo, "\n%s %d %.2f\n", productos, cantidadProductos, precio);
        fclose(archivo);
        return;
      }
    }
    printf("Producto no encontrado.\n");
  } else {
      printf("Lamentablemente el archivo no logro abrirse\n");
  }

  fclose(archivo);
}

void sacarDatos(char productos[][C], float precio[], int cantidadProductos[]){
  FILE *archivo;
  if ((archivo = fopen("inventario.txt", "r")) != NULL){
    char productos[50];
    int cantidadProducto;
    float precioProducto;
    rewind(archivo);
    while(fscanf(archivo, "%s %d %f", productos, &cantidadProducto, &precioProducto) == 3){
      printf("Producto: %s\n", productos);
      printf("Cantidad: %d\n", cantidadProducto);
      printf("Precio: %.2f\n\n", precioProducto);
    }
    fclose (archivo);
  }else{
    printf("Lamentablemente el archivo no logro abrirse");
  }
}