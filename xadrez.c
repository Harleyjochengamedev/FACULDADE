#include <stdio.h>

int main() {
    // ========== TORRE ==========
    // Movimento: 5 casas para a direita (usando FOR)
    printf("=== MOVIMENTO DA TORRE ===\n");
    printf("Movendo 5 casas para a direita:\n");
    for (int i = 1; i <= 5; i++) {
        printf("Direita\n");
    }
    printf("\n");

    // ========== BISPO ==========
    // Movimento: 5 casas na diagonal para cima e à direita (usando WHILE)
    printf("=== MOVIMENTO DO BISPO ===\n");
    printf("Movendo 5 casas na diagonal (cima e direita):\n");
    int casas = 1;
    while (casas <= 5) {
        printf("Cima Direita\n");  // Combinação das duas direções
        casas++;
    }
    printf("\n");

    // ========== RAINHA ==========
    // Movimento: 8 casas para a esquerda (usando DO-WHILE)
    printf("=== MOVIMENTO DA RAINHA ===\n");
    printf("Movendo 8 casas para a esquerda:\n");
    int mov = 1;
    do {
        printf("Esquerda\n");
        mov++;
    } while (mov <= 8);
    printf("\n");

    return 0;
}