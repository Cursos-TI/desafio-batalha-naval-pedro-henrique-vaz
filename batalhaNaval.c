#include <stdio.h>

#define tamanhoDoTabuleiro 10

void tabuleiroFinal(int tabuleiro[tamanhoDoTabuleiro][tamanhoDoTabuleiro]) {
    for (int i = 0; i < tamanhoDoTabuleiro; i++) {
        for (int j = 0; j < tamanhoDoTabuleiro; j++) {
            if (tabuleiro[i][j] == 0)
                printf("0 ");  // agua
            else if (tabuleiro[i][j] == 3)
                printf("3 ");  // navio
            else if (tabuleiro[i][j] == 5)
                printf("5 ");  // habilidade
        }
        printf("\n");
    }
}

void habilidadeCone(int tabuleiro[tamanhoDoTabuleiro][tamanhoDoTabuleiro], int origemX, int origemY) {
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    
    // sobreposicao do cone/tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {
                int x = origemX - 2 + i;
                int y = origemY - 2 + j;
                if (x >= 0 && x < tamanhoDoTabuleiro && y >= 0 && y < tamanhoDoTabuleiro)
                    tabuleiro[x][y] = 5;  // area que foi afetada
            }
        }
    }
}

void habilidadeCruz(int tabuleiro[tamanhoDoTabuleiro][tamanhoDoTabuleiro], int origemX, int origemY) {
    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    // sobreposicao da cruz/tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                int x = origemX - 2 + i;
                int y = origemY - 2 + j;
                if (x >= 0 && x < tamanhoDoTabuleiro && y >= 0 && y < tamanhoDoTabuleiro)
                    tabuleiro[x][y] = 5;  // area que foi afetada
            }
        }
    }
}

void habilidadeOctaedro(int tabuleiro[tamanhoDoTabuleiro][tamanhoDoTabuleiro], int origemX, int origemY) {
    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // sobreposicao do octaedro/tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) {
                int x = origemX - 2 + i;
                int y = origemY - 2 + j;
                if (x >= 0 && x < tamanhoDoTabuleiro && y >= 0 && y < tamanhoDoTabuleiro)
                    tabuleiro[x][y] = 5;  // area que foi afetada
            }
        }
    }
}

int main() {
    int tabuleiro[tamanhoDoTabuleiro][tamanhoDoTabuleiro];
    for (int i = 0; i < tamanhoDoTabuleiro; i++) {
        for (int j = 0; j < tamanhoDoTabuleiro; j++) {
            tabuleiro[i][j] = 0;  // agua
        }
    }

    // navios
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;
    tabuleiro[5][6] = 3;
    tabuleiro[6][6] = 3;
    tabuleiro[7][6] = 3;

    // habilidades
    habilidadeCone(tabuleiro, 4, 4);
    habilidadeCruz(tabuleiro, 5, 5);
    habilidadeOctaedro(tabuleiro, 6, 6);

    // imprimindo o tabuleiro
    printf("Batalha Naval - Habilidades: \n");
    tabuleiroFinal(tabuleiro);

    return 0;
}