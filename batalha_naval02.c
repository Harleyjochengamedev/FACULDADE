#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se uma posição está dentro dos limites
bool posicaoValida(int linha, int coluna) {
    return (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO);
}

// Função para verificar se um navio horizontal pode ser posicionado (sem sobreposição)
bool podePosicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica limites
    if (!posicaoValida(linha, coluna) || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return false;
    }
    // Verifica sobreposição
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != AGUA) {
            return false;
        }
    }
    return true;
}

// Função para verificar se um navio vertical pode ser posicionado
bool podePosicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (!posicaoValida(linha, coluna) || linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return false;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != AGUA) {
            return false;
        }
    }
    return true;
}

// Função para verificar se um navio diagonal (descendente: linha++ e coluna++) pode ser posicionado
bool podePosicionarDiagonalDesc(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (!posicaoValida(linha, coluna) || linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return false;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] != AGUA) {
            return false;
        }
    }
    return true;
}

// Função para verificar se um navio diagonal (ascendente: linha++ e coluna--) pode ser posicionado
bool podePosicionarDiagonalAsc(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (!posicaoValida(linha, coluna) || linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - TAMANHO_NAVIO + 1 < 0) {
        return false;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna - i] != AGUA) {
            return false;
        }
    }
    return true;
}

// Funções para posicionar os navios (marcam no tabuleiro)
void posicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
}

void posicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
}

void posicionarDiagonalDesc(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = NAVIO;
    }
}

void posicionarDiagonalAsc(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = NAVIO;
    }
}

// Exibe o tabuleiro formatado
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n   ");
    for (int col = 0; col < TAMANHO_TABULEIRO; col++) {
        printf("%2d ", col);
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);
    
    // ========== DEFINIÇÃO DAS COORDENADAS DOS NAVIOS ==========
    // Navio horizontal: linha 1, coluna 2 (posições: (1,2),(1,3),(1,4))
    int horiz_lin = 1, horiz_col = 2;
    // Navio vertical: linha 5, coluna 7 (posições: (5,7),(6,7),(7,7))
    int vert_lin = 5, vert_col = 7;
    // Navio diagonal descendente (\\ ): linha 2, coluna 2 → (2,2),(3,3),(4,4)
    int diag_desc_lin = 2, diag_desc_col = 2;
    // Navio diagonal ascendente (/ ): linha 6, coluna 8 → (6,8),(7,7),(8,6)
    int diag_asc_lin = 6, diag_asc_col = 8;
    
    // ========== VALIDAÇÕES E POSICIONAMENTO ==========
    bool erro = false;
    
    // Horizontal
    if (podePosicionarHorizontal(tabuleiro, horiz_lin, horiz_col)) {
        posicionarHorizontal(tabuleiro, horiz_lin, horiz_col);
        printf("Navio horizontal posicionado em (%d,%d)\n", horiz_lin, horiz_col);
    } else {
        printf("ERRO: Não foi possível posicionar o navio horizontal em (%d,%d)\n", horiz_lin, horiz_col);
        erro = true;
    }
    
    // Vertical
    if (podePosicionarVertical(tabuleiro, vert_lin, vert_col)) {
        posicionarVertical(tabuleiro, vert_lin, vert_col);
        printf("Navio vertical posicionado em (%d,%d)\n", vert_lin, vert_col);
    } else {
        printf("ERRO: Não foi possível posicionar o navio vertical em (%d,%d)\n", vert_lin, vert_col);
        erro = true;
    }
    
    // Diagonal descendente
    if (podePosicionarDiagonalDesc(tabuleiro, diag_desc_lin, diag_desc_col)) {
        posicionarDiagonalDesc(tabuleiro, diag_desc_lin, diag_desc_col);
        printf("Navio diagonal descendente posicionado em (%d,%d)\n", diag_desc_lin, diag_desc_col);
    } else {
        printf("ERRO: Não foi possível posicionar o navio diagonal descendente em (%d,%d)\n", diag_desc_lin, diag_desc_col);
        erro = true;
    }
    
    // Diagonal ascendente
    if (podePosicionarDiagonalAsc(tabuleiro, diag_asc_lin, diag_asc_col)) {
        posicionarDiagonalAsc(tabuleiro, diag_asc_lin, diag_asc_col);
        printf("Navio diagonal ascendente posicionado em (%d,%d)\n", diag_asc_lin, diag_asc_col);
    } else {
        printf("ERRO: Não foi possível posicionar o navio diagonal ascendente em (%d,%d)\n", diag_asc_lin, diag_asc_col);
        erro = true;
    }
    
    if (erro) {
        printf("\nHouve erro no posicionamento. Verifique as coordenadas.\n");
        return 1;
    }
    
    // Exibe o tabuleiro final
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}