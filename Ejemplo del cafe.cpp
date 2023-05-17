#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Producto {
    char nombre[50];
    float precio;
};

// Función de ordenamiento de selección
void selectionSort(struct Producto array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j].precio < array[minIndex].precio) {
                minIndex = j;
            }
        }
        // Intercambio de elementos si están en el orden incorrecto
        struct Producto temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

// Función de búsqueda lineal
int linearSearch(struct Producto array[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (i + 1 == target) {
            return i;
        }
    }
    return -1; // Si el producto no se encuentra en la lista
}

int main() {
    // Ingresar los productos y sus precios
    int n = 6; // Cantidad de productos
    struct Producto productos[n];

    strcpy(productos[0].nombre, "Cafe americano");
    productos[0].precio = 2.5;

    strcpy(productos[1].nombre, "Cafe espresso");
    productos[1].precio = 3.0;

    strcpy(productos[2].nombre, "Cafe latte");
    productos[2].precio = 3.5;

    strcpy(productos[3].nombre, "Cafe negro");
    productos[3].precio = 2.0;

    strcpy(productos[4].nombre, "Cafe capuchino");
    productos[4].precio = 4.0;

    strcpy(productos[5].nombre, "Chocolate caliente");
    productos[5].precio = 3.8;

    // Ordenamiento de productos de menor a mayor precio
    selectionSort(productos, n);

    // Impresión de los productos ordenados
    printf("\nProductos ordenados de menor a mayor precio:\n");
    for (int i = 0; i < n; i++) {
        printf("Producto %d - Nombre: %s - Precio: %.2f\n", i + 1, productos[i].nombre, productos[i].precio);
    }

    // Selección de productos
    int seleccion[10]; // Array para almacenar los productos seleccionados
    int numProductos = 0; // Contador de productos seleccionados

    printf("\nIngrese los numeros de los productos que desea seleccionar (1 al 6): ");
    char input[100];
    fgets(input, sizeof(input), stdin);
    char *token = strtok(input, " ");
    while (token != NULL) {
        int num = atoi(token);
        if (num >= 1 && num <= 6) {
            seleccion[numProductos] = num;
            numProductos++;
        } else {
            printf("Numero de producto invalido: %s\n", token);
        }
        token = strtok(NULL, " ");
    }

    // Impresión de los productos seleccionados y cálculo del precio total
	float precioTotal = 0.0;
	printf("\nProductos seleccionados:\n");
	for (int i = 0; i < numProductos; i++) {
		int indice = linearSearch(productos, n, seleccion[i]);
		if (indice != -1) {
			printf("Producto %d - Nombre: %s - Precio: %.2f\n", seleccion[i], productos[indice].nombre, productos[indice].precio);
			precioTotal += productos[indice].precio;
		}
	}
printf("\nPrecio total: %.2f\n", precioTotal);

return 0;
}
