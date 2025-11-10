#include <stdio.h>
#include <stdlib.h>  // Necessário para usar abs()

#define TAM 10
#define HABILIDADE 5

int main() {
    int linha[TAM] = {1,2,3,4,5,6,7,8,9,10}; 
    char coluna[TAM] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[TAM][TAM];
    int i, j;

    // Inicializa o tabuleiro com '0'
    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // POSICIONAR NAVIOS (em áreas sem habilidades)

    int linhahorizontal = 2;
    int colunahorizontal = 0;

    int linhavertical = 0;
    int colunavertical = 9;

    int diagonallinha1 = 3;
    int diagonalcoluna1 = 6;

    int diagonallinha2 = 9;   // novo ponto inicial
    int diagonalcoluna2 = 2;  // novo ponto inicial

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            // Navio horizontal
            if (i == linhahorizontal && j >= colunahorizontal && j < colunahorizontal + 3)
                tabuleiro[i][j] = 3;

            // Navio vertical
            else if (j == colunavertical && i >= linhavertical && i < linhavertical + 3)
                tabuleiro[i][j] = 3;

            // Navio diagonal ↘
            else if ((i == diagonallinha1 && j == diagonalcoluna1) ||
                     (i == diagonallinha1 + 1 && j == diagonalcoluna1 + 1) ||
                     (i == diagonallinha1 + 2 && j == diagonalcoluna1 + 2))
                tabuleiro[i][j] = 3;

            // Navio diagonal ↙
            else if ((i == diagonallinha2 && j == diagonalcoluna2) ||
                     (i == diagonallinha2 - 1 && j == diagonalcoluna2 - 1) ||
                     (i == diagonallinha2 - 2 && j == diagonalcoluna2 - 2))
                tabuleiro[i][j] = 3;
        }
    }

    
    //  CONSTRUIR AS MATRIZES DE HABILIDADE (5x5)
    
    int cone[HABILIDADE][HABILIDADE];
    int cruz[HABILIDADE][HABILIDADE];
    int octaedro[HABILIDADE][HABILIDADE];

    // CONE 
    for(i = 0; i < HABILIDADE; i++) {
        for(j = 0; j < HABILIDADE; j++) {
            if (j >= (HABILIDADE/2 - (HABILIDADE - 1 - i)) && j <= (HABILIDADE/2 + (HABILIDADE - 1 - i)) && i >= HABILIDADE/2)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // CRUZ
    for(i = 0; i < HABILIDADE; i++) {
        for(j = 0; j < HABILIDADE; j++) {
            if (i == HABILIDADE/2 || j == HABILIDADE/2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // OCTAEDRO 
    for(i = 0; i < HABILIDADE; i++) {
        for(j = 0; j < HABILIDADE; j++) {
            if (abs(i - HABILIDADE/2) + abs(j - HABILIDADE/2) <= HABILIDADE/2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    
    // DEFINIR POSIÇÃO DAS HABILIDADES NO TABULEIRO
    
    int origemConeLinha = 2, origemConeColuna = 4;  
    int origemCruzLinha = 5, origemCruzColuna = 2;
    int origemOctaLinha = 7, origemOctaColuna = 7;

    
    // SOBREPOR AS HABILIDADES NO TABULEIRO
    
    int centro = HABILIDADE / 2;
    for (i = 0; i < HABILIDADE; i++) {
        for (j = 0; j < HABILIDADE; j++) {
            int linTab, colTab;

            // Cone
            if (cone[i][j] == 1) {
                linTab = origemConeLinha + (i - centro);
                colTab = origemConeColuna + (j - centro);
                if (linTab >= 0 && linTab < TAM && colTab >= 0 && colTab < TAM)
                    if (tabuleiro[linTab][colTab] == 0)
                        tabuleiro[linTab][colTab] = 5;
            }

            // Cruz
            if (cruz[i][j] == 1) {
                linTab = origemCruzLinha + (i - centro);
                colTab = origemCruzColuna + (j - centro);
                if (linTab >= 0 && linTab < TAM && colTab >= 0 && colTab < TAM)
                    if (tabuleiro[linTab][colTab] == 0)
                        tabuleiro[linTab][colTab] = 5;
            }

            // Octaedro
            if (octaedro[i][j] == 1) {
                linTab = origemOctaLinha + (i - centro);
                colTab = origemOctaColuna + (j - centro);
                if (linTab >= 0 && linTab < TAM && colTab >= 0 && colTab < TAM)
                    if (tabuleiro[linTab][colTab] == 0)
                        tabuleiro[linTab][colTab] = 5;
            }
        }
    }


    // IMPRIMIR TABULEIRO FINAL

    printf("\n   *** BATALHA NAVAL - HABILIDADES E NAVIOS ***\n");
    printf("   ");
    for(j = 0; j < TAM; j++) {
        printf("%c ", coluna[j]);
    }
    printf("\n");

    for(i = 0; i < TAM; i++) {
        if (linha[i] < 10)
            printf(" %d ", linha[i]);
        else
            printf("%d ", linha[i]);

        for(j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0)
                printf("0 ");
            else if (tabuleiro[i][j] == 3)
                printf("3 ");
            else if (tabuleiro[i][j] == 5)
                printf("5 ");
        }
        printf("\n");
    }

    printf("\nLegenda:\n");
    printf("0 = Água\n");
    printf("3 = Navio\n");
    printf("5 = Área de habilidade (Cone, Cruz, Octaedro)\n");

    return 0;
}
