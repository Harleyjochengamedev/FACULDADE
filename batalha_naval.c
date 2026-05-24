#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // 1. Declaração e inicialização do tabuleiro (matriz 10x10) com água
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
    
    // 2. Definição das coordenadas e orientações dos navios
    // Navio Horizontal: começa na linha 2, coluna 4 (índices começam em 0)
    int navioHorizontal_linha = 2;
    int navioHorizontal_coluna = 4;
    
    // Navio Vertical: começa na linha 5, coluna 7
    int navioVertical_linha = 5;
    int navioVertical_coluna = 7;
    
    // 3. Validação de limites para o navio horizontal
    if (navioHorizontal_coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("ERRO: Navio horizontal ultrapassa o limite direito do tabuleiro!\n");
        return 1;
    }
    if (navioHorizontal_linha < 0 || navioHorizontal_linha >= TAMANHO_TABULEIRO) {
        printf("ERRO: Linha do navio horizontal inválida!\n");
        return 1;
    }
    
    // Validação de limites para o navio vertical
    if (navioVertical_linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("ERRO: Navio vertical ultrapassa o limite inferior do tabuleiro!\n");
        return 1;
    }
    if (navioVertical_coluna < 0 || navioVertical_coluna >= TAMANHO_TABULEIRO) {
        printf("ERRO: Coluna do navio vertical inválida!\n");
        return 1;
    }
    
    // 4. Validação de sobreposição (verifica se alguma posição do navio horizontal coincide com o vertical)
    int sobreposicao = 0;
    // Verifica cada posição do navio horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linhaH = navioHorizontal_linha;
        int colunaH = navioHorizontal_coluna + i;
        // Verifica se esta posição está dentro da área do navio vertical
        if (linhaH >= navioVertical_linha && linhaH < navioVertical_linha + TAMANHO_NAVIO &&
            colunaH == navioVertical_coluna) {
            sobreposicao = 1;
            break;
        }
    }
    
    if (sobreposicao) {
        printf("ERRO: Os navios estão sobrepostos! Ajuste as coordenadas.\n");
        return 1;
    }
    
    // 5. Posicionamento dos navios no tabuleiro
    // Navio horizontal: preenche as posições à direita a partir da coluna inicial
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navioHorizontal_linha][navioHorizontal_coluna + i] = NAVIO;
    }
    
    // Navio vertical: preenche as posições para baixo a partir da linha inicial
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navioVertical_linha + i][navioVertical_coluna] = NAVIO;
    }
    
    // 6. Exibição do tabuleiro
    printf("=== TABULEIRO BATALHA NAVAL ===\n");
    printf("   ");
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
    
    return 0;
}