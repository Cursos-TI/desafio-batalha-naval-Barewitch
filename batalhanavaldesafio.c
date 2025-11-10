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

    // Inicializar o tabuleiro com '0'
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            tabuleiro[i][j] = '0';
        }
    }

    // Imprimir cabeçalho (colunas)
    printf ("   ");
    printf ("***BATALHA NAVAL***\n");
    printf("   "); // Espaço para alinhar os números à esquerda
    for(j = 0; j < 10; j++) {
        printf("%c ", coluna[j]);
    }
    printf("\n");

    // Imprimir linhas com conteúdo do tabuleiro
    for(i = 0; i < 10; i++) {
        if (linha[i] < 10) {
            printf(" %d ", linha[i]); // Alinha números de 1 dígito
        } else {
            printf("%d ", linha[i]);  // Alinha o número 10
        }

       for (j = 0; j < 10; j++) {
            // Verifica se a posição atual pertence ao navio horizontal, em caso positivo imprime 3
            if (i == linhahorizontal && j >= colunahorizontal && j < colunahorizontal + 3) {
                printf("3 ");
            }
            // Verifica se a posição atual pertence ao navio vertical, em caso positivo imprime 3
            else if (j == colunavertical && i >= linhavertical && i < linhavertical + 3) {
                printf("3 ");
            }
            // Caso contrário, imprime água 
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
     

    return 0;
}
