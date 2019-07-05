//Fabian Cardenas
//Andre Ducheylard L.
//Correccion Laboratorio 2

#include "funciones.h"

int main(){
    char cadena[500000];
    char nombreArchivo[300];
    char menu = 'N';
    do{
        system("cls");
        printf("Ingrese nombre de archivo: ");
        scanf("%s",nombreArchivo);
        leerArchivo(nombreArchivo,cadena);
        verificaCadena(cadena);
        printf("\nDesea probar otro archivo S/N? ");
        scanf("%s", &menu);
        largoCadena = 0;
        lineas = 1;
    }while(menu == 's' || menu == 'S');
    return 0;
}
