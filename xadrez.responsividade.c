#include <stdio.h>

// ========== FUNÇÕES RECURSIVAS ==========

// Torre: move 5 casas para a direita
void moverTorre(int casas) {
    if (casas == 0) return;
    printf("Direita\n");
    moverTorre(casas - 1);
}

// Bispo (recursivo): move 5 casas na diagonal (cima e direita)
void moverBispoRecursivo(int casas) {
    if (casas == 0) return;
    printf("Cima Direita\n");
    moverBispoRecursivo(casas - 1);
}

// Rainha: move 8 casas para a esquerda
void moverRainha(int casas) {
    if (casas == 0) return;
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

// ========== BISPO COM LOOPS ANINHADOS ==========
// Loop externo: vertical (cima), loop interno: horizontal (direita)
void moverBispoLoopsAninhados(int casas) {
    for (int vertical = 0; vertical < casas; vertical++) {
        for (int horizontal = 0; horizontal < 1; horizontal++) {  // apenas 1 passo horizontal por vertical
            printf("Cima Direita\n");
        }
    }
}

// ========== CAVALO COM LOOPS COMPLEXOS ==========
// Movimento em "L": 2 casas para cima e 1 para a direita
// Utiliza loops aninhados com múltiplas variáveis, continue e break
void moverCavalo() {
    // Matriz que define os passos: [0] = direção, [1] = número de repetições
    int passos[2][2] = {
        {1, 2},  // 1 = Cima, 2 repetições
        {2, 1}   // 2 = Direita, 1 repetição
    };
    
    for (int i = 0; i < 2; i++) {          // loop externo: percorre as duas direções
        int direcao = passos[i][0];
        int repeticoes = passos[i][1];
        int j = 0;
        
        while (j < repeticoes) {           // loop interno: repete o movimento
            // Exemplo de uso de continue (se direção inválida, pularia)
            if (direcao != 1 && direcao != 2) {
                j++;
                continue;                  // nunca ocorre aqui, mas demonstra o uso
            }
            
            // Imprime a direção correta
            if (direcao == 1)
                printf("Cima\n");
            else if (direcao == 2)
                printf("Direita\n");
            
            j++;
            
            // Exemplo de uso de break: interrompe antes se alguma condição (não usado aqui)
            // if (j == 2 && i == 0) break;   // apenas ilustrativo
        }
    }
}

int main() {
    // ========== TORRE (recursiva) ==========
    printf("=== MOVIMENTO DA TORRE (Recursivo) ===\n");
    printf("Movendo 5 casas para a direita:\n");
    moverTorre(5);
    printf("\n");
    
    // ========== BISPO (recursivo) ==========
    printf("=== MOVIMENTO DO BISPO (Recursivo) ===\n");
    printf("Movendo 5 casas na diagonal (cima e direita):\n");
    moverBispoRecursivo(5);
    printf("\n");
    
    // ========== BISPO (loops aninhados) ==========
    printf("=== MOVIMENTO DO BISPO (Loops Aninhados) ===\n");
    printf("Movendo 5 casas na diagonal (cima e direita):\n");
    moverBispoLoopsAninhados(5);
    printf("\n");
    
    // ========== RAINHA (recursiva) ==========
    printf("=== MOVIMENTO DA RAINHA (Recursivo) ===\n");
    printf("Movendo 8 casas para a esquerda:\n");
    moverRainha(8);
    printf("\n");
    
    // ========== CAVALO (loops complexos) ==========
    printf("=== MOVIMENTO DO CAVALO (Loops Complexos) ===\n");
    printf("Movendo 2 casas para cima e 1 para a direita:\n");
    moverCavalo();
    printf("\n");
    
    return 0;
}