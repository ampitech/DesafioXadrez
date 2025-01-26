#ifndef XADREZ_H
#define XADREZ_H

typedef struct {
    char tabuleiro[8][8];
} TabuleiroDeXadrez;

void inicializar_tabuleiro(TabuleiroDeXadrez *tabuleiro);
void imprimir_tabuleiro(const TabuleiroDeXadrez *tabuleiro);
void fazer_movimento(TabuleiroDeXadrez *tabuleiro, int inicio_x, int inicio_y, int fim_x, int fim_y);

#endif // XADREZ_H
