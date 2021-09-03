#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "scanner.h"

void get_token(void) {

    int ch = getchar();

    while (ch != EOF) {
        if (pertenece_a_CAD(ch)) {
            printf("\nCadena: ");
            while (pertenece_a_CAD(ch)) {
                printf("%c", ch);
                ch = getchar();
            }
        } else {
            if (es_SEP(ch)) {
                printf("\nSeparador: %c", ch);
                ch = getchar();
            } else {
                /*  En este caso, el caracter es un espacio en
                    blanco, por lo que lo ignoramos */
                ch = getchar();
            }
        }
    }
    printf("\nFin De Texto: %c", ch);
}

bool es_SEP (char caracter) {

    bool respuesta = caracter == ',';

    return respuesta;

}

bool pertenece_a_CAD (char caracter) {

    if (es_SEP(caracter) == false && isspace(caracter) == false && caracter != EOF) {
        return true;
    } else {
        return false;
    }

}
