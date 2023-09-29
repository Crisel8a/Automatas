#include <iostream>
#include <string>

using namespace std;

// Definición de estados y transiciones del AFD
enum Estado { q0, q1, q2 };

Estado transiciones[3][2] = {
    {q0, q1},
    {q2, q0},
    {q1, q2}
};

// Función para verificar si la cadena es divisible por 3
bool automata_modulo_tres(const string& cadena) {
    Estado estado_actual = q0;

    for (size_t i = 0; i < cadena.length(); i++) {
        char simbolo = cadena[i];
        int simbolo_int = simbolo - '0';

        if (simbolo_int != 0 && simbolo_int != 1) {
            return false; // La entrada no es válida para el AFD
        }

        estado_actual = transiciones[estado_actual][simbolo_int];
    }

    return estado_actual == q0;
}

int main() {
    string cadena;
    cout << "Ingrese una cadena binaria: ";
    cin >> cadena;

    if (automata_modulo_tres(cadena)) {
        cout << "La cadena es divisible por 3." << endl;
    } else {
        cout << "La cadena NO es divisible por 3." << endl;
    }

    return 0;
}

