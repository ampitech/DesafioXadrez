#include <stdio.h>
#include "xadrez.h"

void inicializar_tabuleiro(TabuleiroDeXadrez *tabuleiro) {
    // Inicializar o tabuleiro com a configuração inicial do xadrez
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tabuleiro->tabuleiro[i][j] = ' ';
        }
    }
    // Configuração inicial das peças
    // ...
}

void imprimir_tabuleiro(const TabuleiroDeXadrez *tabuleiro) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", tabuleiro->tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void fazer_movimento(TabuleiroDeXadrez *tabuleiro, int inicio_x, int inicio_y, int fim_x, int fim_y) {
    // Implementar a lógica para mover uma peça no tabuleiro
    tabuleiro->tabuleiro[fim_x][fim_y] = tabuleiro->tabuleiro[inicio_x][inicio_y];
    tabuleiro->tabuleiro[inicio_x][inicio_y] = ' ';
}
