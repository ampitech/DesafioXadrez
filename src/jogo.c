#include "xadrez.h"
#include <stdio.h>
#include <stdbool.h>

// Função para verificar se um movimento é válido
bool movimento_valido(TabuleiroDeXadrez *tabuleiro, int inicio_x, int inicio_y, int fim_x, int fim_y) {
    // Verificar se as posições estão dentro dos limites do tabuleiro
    if (inicio_x < 0 || inicio_x >= 8 || inicio_y < 0 || inicio_y >= 8 ||
        fim_x < 0 || fim_x >= 8 || fim_y < 0 || fim_y >= 8) {
        return false;
    }

    // Verificar se a posição inicial contém uma peça
    if (tabuleiro->tabuleiro[inicio_x][inicio_y] == ' ') {
        return false;
    }

    // Implementar regras de movimento específicas para cada tipo de peça
    // (Este é um exemplo básico e deve ser expandido para cada tipo de peça)
    char peca = tabuleiro->tabuleiro[inicio_x][inicio_y];
    if (peca == 'K' || peca == 'k') { // Rei
        // O rei pode mover-se uma casa em qualquer direção
        int delta_x = abs(fim_x - inicio_x);
        int delta_y = abs(fim_y - inicio_y);
        return (delta_x <= 1 && delta_y <= 1);
    }

    // Adicionar verificações para outras peças (Rainha, Bispo, Cavalo, Torre, Peão)

    return false;
}

// Função para verificar se o rei está em xeque
bool rei_em_xeque(TabuleiroDeXadrez *tabuleiro, char cor_do_rei) {

    int rei_x, rei_y;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tabuleiro->tabuleiro[i][j] == cor_do_rei) {
                rei_x = i;
                rei_y = j;
                break;
            }
        }
    }


    return false;
}

// Função para verificar se o jogo terminou (xeque-mate)
bool xeque_mate(TabuleiroDeXadrez *tabuleiro, char cor_do_rei) {
    // Verificar se o rei está em xeque
    if (!rei_em_xeque(tabuleiro, cor_do_rei)) {
        return false;
    }



    return true;
}

// Função para alternar turnos entre os jogadores
void alternar_turno(char *turno) {
    if (*turno == 'B') {
        *turno = 'P';
    } else {
        *turno = 'B';
    }
}

// Função para realizar um movimento no jogo
void realizar_movimento(TabuleiroDeXadrez *tabuleiro, int inicio_x, int inicio_y, int fim_x, int fim_y, char *turno) {
    if (movimento_valido(tabuleiro, inicio_x, inicio_y, fim_x, fim_y)) {
        fazer_movimento(tabuleiro, inicio_x, inicio_y, fim_x, fim_y);
        alternar_turno(turno);
    } else {
        printf("Movimento inválido!\n");
    }
}