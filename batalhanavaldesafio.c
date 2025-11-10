#include <stdio.h>

int main() {
    int linha[10] = {1,2,3,4,5,6,7,8,9,10}; 
    char coluna[10] = {'A','B','C','D','E','F','G','H','I','J'};
    char tabuleiro[10][10];
    int i, j;

    // Posicionar navio 3 casas na horizontal
    int linhahorizontal = 1;
    int colunahorizontal = 2;
           
    // Posicionar navio 3 casas na vertical
    int linhavertical = 4;
    int colunavertical = 6;

    // Posicionar o primeiro navio da diagonal 
    int diagonallinha1 = 2;
    int diagonalcoluna1 = 1;

    // Posicionar o segundo navio da diagonal 
    int diagonallinha2 = 6;
    int diagonalcoluna2 = 8;
    
    // Inicializar o tabuleiro com '0'
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            tabuleiro[i][j] = '0';
        }
    }

    // Imprimir cabeçalho (colunas)
    printf("   ");
    printf("***BATALHA NAVAL***\n");
    printf("   "); 
    for(j = 0; j < 10; j++) {
        printf("%c ", coluna[j]);
    }
    printf("\n");

    // Imprimir linhas com conteúdo do tabuleiro
    for(i = 0; i < 10; i++) {
        if (linha[i] < 10) {
            printf(" %d ", linha[i]);
        } else {
            printf("%d ", linha[i]);
        }

        for (j = 0; j < 10; j++) {
            // Navio horizontal
            if (i == linhahorizontal && j >= colunahorizontal && j < colunahorizontal + 3) {
                printf("3 ");
            }
            // Navio vertical
            else if (j == colunavertical && i >= linhavertical && i < linhavertical + 3) {
                printf("3 ");
            }
            // Navio diagonal 1
            else if ((i == diagonallinha1 && j == diagonalcoluna1) ||
                     (i == diagonallinha1 + 1 && j == diagonalcoluna1 + 1) ||
                     (i == diagonallinha1 + 2 && j == diagonalcoluna1 + 2)) {
                printf("3 ");
            }
            // Navio diagonal 2
            else if ((i == diagonallinha2 && j == diagonalcoluna2) ||
                     (i == diagonallinha2 + 1 && j == diagonalcoluna2 - 1) ||
                     (i == diagonallinha2 + 2 && j == diagonalcoluna2 - 2)) {
                printf("3 ");
            }
            // Água
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
        
    return 0;
}

