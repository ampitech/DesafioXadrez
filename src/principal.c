#include <stdio.h>
#include "xadrez.h"

int main() {
    TabuleiroDeXadrez tabuleiro;
    inicializar_tabuleiro(&tabuleiro);
    imprimir_tabuleiro(&tabuleiro);

    // Exemplo de movimento
    fazer_movimento(&tabuleiro, 1, 1, 2, 2);
    imprimir_tabuleiro(&tabuleiro);

    return 0;
}
