#include <stdio.h>
#include <string.h>

// Definición de estados y transiciones del AFD
enum Estado { q0, q1, q2 };

enum Estado transiciones[3][2] = {
    {q0, q1},
    {q2, q0},
    {q1, q2}
};

// Función para verificar si la cadena es divisible por 3
int automata_modulo_tres(char *cadena) {
    enum Estado estado_actual = q0;

    for (int i = 0; cadena[i] != '\0'; i++) {
        char simbolo = cadena[i];
        int simbolo_int = simbolo - '0';

        if (simbolo_int != 0 && simbolo_int != 1) {
            return 0; // La entrada no es válida para el AFD
        }

        estado_actual = transiciones[estado_actual][simbolo_int];
    }

    return estado_actual == q0;
}

int main() {
    char cadena[100];
    printf("Ingrese una cadena binaria: ");
    scanf("%s", cadena);

    if (automata_modulo_tres(cadena)) {
        printf("La cadena es divisible por 3.\n");
    } else {
        printf("La cadena NO es divisible por 3.\n");
    }

    return 0;
}

