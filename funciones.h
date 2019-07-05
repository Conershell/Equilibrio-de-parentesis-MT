#include <stdio.h>
#include <stdlib.h>

int largoCadena = 0;
char pila[500000];
int lineas = 1;
int posPila;
int conLinea[500000];
int LineaError = 0;

void leerArchivo(char nombreArchivo[300],char cadena[500000]){
    FILE *archivo;
    lineas = 1;
    largoCadena = 0;
    char car;
    int pos = 0;
    if (fopen(nombreArchivo, "r") != NULL){
        archivo = fopen(nombreArchivo, "r");
    }else{
        printf("El archivo no existe!... el programa se va a cerrar");
        exit(1);
    }
    do{
        car = fgetc(archivo);
        cadena[pos] = car;
        conLinea[pos] = lineas;
        largoCadena++;
        pos++;
        if(car == '\n'){
            lineas++;
        }
    }while(car != EOF);
}

void verificaCadena(char cadena[500000]){
    pila[500000];
    pila[0] = 'Z';
    int estadoActual = 0;
    int i = 0;
    posPila = 0;
    for(i = 0; i < largoCadena - 1 ; i++){ //SE LE RESTA 1 AL LARGO DE CADENA POR EL ENTER DEL TXT
        //PUSH SI PILA ESTA VACIA
        if((estadoActual == 0 || estadoActual == 7 || estadoActual == 8 || estadoActual == 9) && cadena[i] == '(' && pila[posPila] == 'Z'){
            estadoActual = 3;
            posPila++;
            pila[posPila] = '(';
        }else if((estadoActual == 0 || estadoActual == 7 || estadoActual == 8 || estadoActual == 9) && cadena[i] == '[' && pila[posPila] == 'Z'){
            estadoActual = 2;
            posPila++;
            pila[posPila] = '[';
        }else if((estadoActual == 0 || estadoActual == 7 || estadoActual == 8 || estadoActual == 9) && cadena[i] == '{' && pila[posPila] == 'Z'){
            estadoActual = 1;
            posPila++;
            pila[posPila] = '{';
            //PUSH SI PILA NO ESTA VACIA
        }else if((estadoActual == 1 || estadoActual == 2 || estadoActual == 3 || estadoActual == 4 || estadoActual == 5 || estadoActual == 6 || estadoActual == 7 ||  estadoActual == 8 ||estadoActual == 9) && cadena[i] == '('){
            estadoActual = 6;
            posPila++;
            pila[posPila] = '(';
        }else if((estadoActual == 1 || estadoActual == 2 || estadoActual == 3 || estadoActual == 4 || estadoActual == 5 || estadoActual == 6 || estadoActual == 7 ||  estadoActual == 8 ||estadoActual == 9) && cadena[i] == '{'){
            estadoActual = 4;
            posPila++;
            pila[posPila] = '{';
        }else if((estadoActual == 1 || estadoActual == 2 || estadoActual == 3 || estadoActual == 4 || estadoActual == 5 || estadoActual == 6 || estadoActual == 7 ||  estadoActual == 8 ||estadoActual == 9) && cadena[i] == '['){
            estadoActual = 5;
            posPila++;
            pila[posPila] = '[';
            //POPS
        }else if((estadoActual == 1 || estadoActual == 4 || estadoActual == 7 || estadoActual == 8 || estadoActual == 9) && cadena[i] == '}' && pila[posPila] == '{'){
            estadoActual = 7;
            posPila--;
        }else if((estadoActual == 2 || estadoActual == 5 || estadoActual == 7 || estadoActual == 8 || estadoActual == 9) && cadena[i] == ']' && pila[posPila] == '['){
            estadoActual = 8;
            posPila--;
        }else if((estadoActual == 3 || estadoActual == 6 || estadoActual == 7 || estadoActual == 8 || estadoActual == 9) && cadena[i] == ')' && pila[posPila] == '('){
            estadoActual = 9;
            posPila--;
            //NODOS DE ERROR
        }else if((estadoActual == 1 || estadoActual == 2 || estadoActual == 3 || estadoActual == 7 || estadoActual == 8 || estadoActual == 9) && cadena[i] == '}' && pila[posPila] == '('){
            estadoActual = 11;
            LineaError = i;
        }else if((estadoActual == 1 || estadoActual == 2 || estadoActual == 3 || estadoActual == 7 || estadoActual == 8 || estadoActual == 9) && cadena[i] == '}' && pila[posPila] == '['){
            estadoActual = 12;
            LineaError = i;
        }else if((estadoActual == 1 || estadoActual == 2 || estadoActual == 3 || estadoActual == 7 || estadoActual == 8 || estadoActual == 9) && cadena[i] == ']' && pila[posPila] == '('){
            estadoActual = 13;
            LineaError = i;
        }else if((estadoActual == 1 || estadoActual == 2 || estadoActual == 3 || estadoActual == 7 || estadoActual == 8 || estadoActual == 9) && cadena[i] == ']' && pila[posPila] == '{'){
            estadoActual = 14;
            LineaError = i;
        }else if((estadoActual == 1 || estadoActual == 2 || estadoActual == 3 || estadoActual == 7 || estadoActual == 8 || estadoActual == 9) && cadena[i] == ')' && pila[posPila] == '['){
            estadoActual = 15;
            LineaError = i;
        }else if((estadoActual == 1 || estadoActual == 2 || estadoActual == 3 || estadoActual == 7 || estadoActual == 8 || estadoActual == 9) && cadena[i] == ')' && pila[posPila] == '{'){
            estadoActual = 16;
            LineaError = i;
        }else if((estadoActual == 1 || estadoActual == 2 || estadoActual == 3 || estadoActual == 7 || estadoActual == 8 || estadoActual == 9) && cadena[i] == ')' && pila[posPila] == 'Z'){
            estadoActual = 17;
            LineaError = i;
        }else if((estadoActual == 1 || estadoActual == 2 || estadoActual == 3 || estadoActual == 7 || estadoActual == 8 || estadoActual == 9) && cadena[i] == ']' && pila[posPila] == 'Z'){
            estadoActual = 18;
            LineaError = i;
        }else if((estadoActual == 1 || estadoActual == 2 || estadoActual == 3 || estadoActual == 7 || estadoActual == 8 || estadoActual == 9) && cadena[i] == '}' && pila[posPila] == 'Z'){
            estadoActual = 19;
            LineaError = i;
        }else if(estadoActual == 0 && cadena[i] == '}' && pila[posPila] == 'Z'){
            estadoActual = 19;
            LineaError = i;
        }else if(estadoActual == 0 && cadena[i] == ']' && pila[posPila] == 'Z'){
            estadoActual = 18;
            LineaError = i;
        }else if(estadoActual == 0 && cadena[i] == ')' && pila[posPila] == 'Z'){
            estadoActual = 17;
            LineaError = i;
        }else{//CUANDO LEE CUALQUIER OTRO CARACTER
            estadoActual = estadoActual;
        }
    }

    //SE VERIFICA QUE ESTA EN UN NODO FINAL, SI LA PILA ESTA VACIA Y SI SE REVISO TODA LA CADENA
    if((estadoActual == 1 || estadoActual == 2 || estadoActual == 3 || estadoActual == 4 || estadoActual == 5 || estadoActual == 6 || estadoActual == 7 || estadoActual == 8 || estadoActual == 9) && pila[posPila] == 'Z' && i == largoCadena - 1){
        printf("Los parentesis estan balanceados.");
    }else if(estadoActual == 1 || estadoActual == 4 || estadoActual == 7 || estadoActual == 14 || estadoActual == 16){
        printf("Tiene un error de balance de parentesis en la linea %d. Se esperaba un: }", conLinea[LineaError]);
    }else if(estadoActual == 2 || estadoActual == 5 || estadoActual == 8 || estadoActual == 12 || estadoActual == 15){
        printf("Tiene un error de balance de parentesis en la linea %d. Se esperaba un: ]", conLinea[LineaError]);
    }else if(estadoActual == 3 || estadoActual == 6 || estadoActual == 9 || estadoActual == 11 || estadoActual == 13){
        printf("Tiene un error de balance de parentesis en la linea %d. Se esperaba un: )", conLinea[LineaError]);
    }else if(estadoActual == 17){
        printf("Tiene un error de balance de parentesis en la linea %d. Se esperaba un: (", conLinea[LineaError]);
    }else if(estadoActual == 18){
        printf("Tiene un error de balance de parentesis en la linea %d. Se esperaba un: [", conLinea[LineaError]);
    }else if(estadoActual == 19){
        printf("Tiene un error de balance de parentesis en la linea %d. Se esperaba un: {", conLinea[LineaError]);
    }
}
