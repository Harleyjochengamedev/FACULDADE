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
    // Movimento: 5 casas na diagonal (cima e direita) usando WHILE
    printf("=== MOVIMENTO DO BISPO ===\n");
    printf("Movendo 5 casas na diagonal (cima e direita):\n");
    int casas = 1;
    while (casas <= 5) {
        printf("Cima Direita\n");
        casas++;
    }
    printf("\n");

    // ========== RAINHA ==========
    // Movimento: 8 casas para a esquerda usando DO-WHILE
    printf("=== MOVIMENTO DA RAINHA ===\n");
    printf("Movendo 8 casas para a esquerda:\n");
    int mov = 1;
    do {
        printf("Esquerda\n");
        mov++;
    } while (mov <= 8);
    printf("\n");

    // ========== CAVALO ==========
    // Movimento em "L": duas casas para baixo e uma para a esquerda
    // Utilizando loops aninhados: FOR (para as direções) e WHILE (para as casas)
    printf("=== MOVIMENTO DO CAVALO ===\n");
    printf("Movendo 2 casas para baixo e 1 para a esquerda:\n");
    
    // Definição das direções: primeiro "Baixo" (2 vezes), depois "Esquerda" (1 vez)
    // Array de estruturas (simulado com duas variáveis de controle)
    // Usaremos um loop FOR externo que itera sobre as duas direções
    for (int direcao = 0; direcao < 2; direcao++) {
        int repeticoes;
        char *direcaoStr;
        
        if (direcao == 0) {
            repeticoes = 2;  // duas casas para baixo
            direcaoStr = "Baixo";
        } else {
            repeticoes = 1;  // uma casa para a esquerda
            direcaoStr = "Esquerda";
        }
        
        // Loop interno (WHILE) para repetir a direção
        int contador = 0;
        while (contador < repeticoes) {
            printf("%s\n", direcaoStr);
            contador++;
        }
    }
    
    printf("\n");
    return 0;
}