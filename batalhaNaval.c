#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
// Desafio 1 concluido✅
// Desafio 2 concluido✅
// Desafio 3 concluido✅


#define tam 10
#define HAB 5

int main() {
    int tabuleiro[tam][tam] = {0}; // Inicializa o tabuleiro com 0 (água)
    int i, j;

    

    //navio 1 horizontal

    int linha1 = 2, coluna1 = 5, tamanho1 = 3;
    for (i = 0; i < tamanho1 && (coluna1 + i) < tam; i++) {
        tabuleiro[linha1][coluna1 + i] = 3;
    }


    //navio 2 vertical

    int linha2 = 5, coluna2 = 7, tamanho2 = 3;
    for (i = 0; i < tamanho2 && (linha2 + i) < tam; i++) {
        tabuleiro[linha2 + i][coluna2] = 3;
    }


    //navio 3 diagonal principal

    int linha3 = 1, coluna3 = 1, tamanho3 = 3;
    for (i = 0; i < tamanho3 && (linha3 + i) < tam && (coluna3 + i) < tam; i++) {
        tabuleiro[linha3 + i][coluna3 + i] = 3;
    }
    

    //navio 4 diagonal secundária

    int linha4 = 8, coluna4 = 2;
    int tamanho4 = 3;
    for (i = 0; i < tamanho4 && (linha4 - i) >= 0 && (coluna4 + i) < tam; i++) {
        tabuleiro[linha4 - i][coluna4 + i] = 3;
    }


    //Habilidades: cone, cruz, octaedro.

    int cone[HAB][HAB] = {0};
    int cruz[HAB][HAB] = {0};
    int octaedro[HAB][HAB] = {0};

    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (j >= (HAB / 2 - i) && j <= (HAB / 2 + i) && i < HAB) {
                cone[i][j] = 1; //forma triangular (cone)
            }
        }
    }

    //HABILIDADE EM CRUZ
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (i == HAB / 2 || j == HAB / 2) {
                cruz[i][j] = 1; //forma de cruz (linha + coluna central)
            }
        }
    }

    //HABILIDADE EM OCTAEDRO
    int centro = HAB / 2;

    for (i = 0; i < HAB; i++) {
    for (j = 0; j < HAB; j++) {
    int distI = (i > centro) ? (i - centro) : (centro - i); // distância vertical até o centro
    int distJ = (j > centro) ? (j - centro) : (centro - j); // distância horizontal até o centro

        if (distI + distJ <= centro) {
            octaedro[i][j] = 1;  //dentro da forma
        } else {
            octaedro[i][j] = 0;  //fora da forma
        }
    }
}


    //Ponto de origem de cada habilidade no tabuleiro

    int origemConeL = 1, origemConeC = 5;
    int origemCruzL = 5, origemCruzC = 5;
    int origemOctaedroL = 7, origemOctaedroC = 2;

    // --- Função genérica de sobreposição ---
    for (int tipo = 0; tipo < 3; tipo++) {
        int (*habilidade)[HAB]; // ponteiro para a matriz da habilidade atual
        int origemL, origemC;

        if (tipo == 0) { habilidade = cone; origemL = origemConeL; origemC = origemConeC; }
        if (tipo == 1) { habilidade = cruz; origemL = origemCruzL; origemC = origemCruzC; }
        if (tipo == 2) { habilidade = octaedro; origemL = origemOctaedroL; origemC = origemOctaedroC; }

        for (i = 0; i < HAB; i++) {
            for (j = 0; j < HAB; j++) {
                if (habilidade[i][j] == 1) {
                    int linhaTab = origemL - HAB / 2 + i;
                    int colunaTab = origemC - HAB / 2 + j;

                    // Verifica se está dentro do tabuleiro
                    if (linhaTab >= 0 && linhaTab < tam && colunaTab >= 0 && colunaTab < tam) {
                        if (tabuleiro[linhaTab][colunaTab] == 0) {
                            tabuleiro[linhaTab][colunaTab] = 5; // marca área afetada
                        }
                    }
                }
            }
        }
    }

   
    // EXIBIR TABULEIRO FINAL
   
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            if (tabuleiro[i][j] == 0)
                printf("~ "); // água
            else if (tabuleiro[i][j] == 3)
                printf("N "); // navio
            else if (tabuleiro[i][j] == 5)
                printf("* "); // área afetada
        }
        printf("\n");
    }



    return 0;
}
