#include "lib.h"

int contar_digitos(int n) {
    if (n == 0) return 1;
    int contador = 0;
    while (n != 0) {
        n /= 10;
        contador++;
    }
    return contador;
}