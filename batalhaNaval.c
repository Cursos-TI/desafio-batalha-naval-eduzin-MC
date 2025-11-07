#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
// Desafio 1 concluido✅
// Desafio 2 concluido✅

#define tam 10

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    
    int tabuleiro[tam][tam] = {0}; // Inicializa o tabuleiro com 0 (água)
    int i, j;

    

    //navio 1 horizontal

    int linha1 = 2, coluna1 = 5;   // posição
    int tamanho1 = 3;  // tamanho do navio
    for (i = 0; i < tamanho1 ; i++) {
        tabuleiro[linha1][coluna1 + i] = 3;
    }


    //navio 2 vertical

    int linha2 = 5, coluna2 = 7;  // posição
    int tamanho2 = 3;  
    for (i = 0; i < tamanho2; i++) {
        tabuleiro[linha2 + i][coluna2] = 3;
    }


    //navio 3 diagonal principal

    int linha3 = 1, coluna3 = 1;  // posição
    int tamanho3 = 3;
    for (i = 0; i < tamanho3; i++) {
        tabuleiro[linha3 + i][coluna3 + i] = 3; //linha e coluna aumentam juntas
    }
    

    //navio 4 diagonal secundária

    int linha4 = 8, coluna4 = 2;
    int tamanho4 = 3;
    for (i = 0; i < tamanho4; i++) {
        tabuleiro[linha4 - i][coluna4 + i] = 3; // linha diminui, coluna aumenta
    }


    //Exibe o tabuleiro
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }


    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
