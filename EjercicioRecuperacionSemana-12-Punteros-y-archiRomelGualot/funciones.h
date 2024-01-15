#define F 100
#define C 15

int menu();
void ingresarProductos(int *cantidad, char NombreProducto[][C], float precio[], int cantidadProductos[]);
void guardarEnArchivo(const int cantidad, char NombreProducto[][C], float precio[], int cantidadProductos[]);
void modificarProductos();
void sacarDatos(char NombreProducto[][C], float precio[], int cantidadProductos[]);

