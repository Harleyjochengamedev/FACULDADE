#include <stdio.h>
#include <stdbool.h>

#define LIN 4
#define COL 4

// Função para exibir a matriz
void exibirMatriz(int mat[LIN][COL]) {
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // ========== 1. INICIALIZAÇÃO DA MATRIZ ==========
    int matriz[LIN][COL] = {
        {5, 2, 9, 1},
        {8, 3, 7, 4},
        {6, 0, 2, 5},
        {9, 1, 4, 3}
    };
    
    printf("=== MATRIZ ORIGINAL ===\n");
    exibirMatriz(matriz);
    
    // ========== 2. CONTAR ELEMENTOS COM CONDIÇÃO ==========
    int contPares = 0;
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            if (matriz[i][j] % 2 == 0) {  // condicional: par
                contPares++;
            }
        }
    }
    printf("\nQuantidade de números pares: %d\n", contPares);
    
    // ========== 3. BUSCAR UM ELEMENTO (primeira ocorrência) ==========
    int busca = 7;
    int linhaEncontrada = -1, colunaEncontrada = -1;
    for (int i = 0; i < LIN && linhaEncontrada == -1; i++) {
        for (int j = 0; j < COL && linhaEncontrada == -1; j++) {
            if (matriz[i][j] == busca) {
                linhaEncontrada = i;
                colunaEncontrada = j;
            }
        }
    }
    
    if (linhaEncontrada != -1)
        printf("Valor %d encontrado na posição (%d, %d)\n", busca, linhaEncontrada, colunaEncontrada);
    else
        printf("Valor %d não encontrado na matriz.\n", busca);
    
    // ========== 4. SUBSTITUIR ELEMENTOS COM CONDIÇÃO ==========
    // Substituir todos os números maiores que 5 por 0
    printf("\n=== SUBSTITUIR > 5 POR 0 ===\n");
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            if (matriz[i][j] > 5) {
                matriz[i][j] = 0;
            }
        }
    }
    exibirMatriz(matriz);
    
    // ========== 5. MODIFICAR COM CONDIÇÃO MÚLTIPLA ==========
    // Incrementar elementos que são iguais a 0 (agora após substituição)
    printf("\n=== INCREMENTAR ZEROS PARA 1 ===\n");
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            if (matriz[i][j] == 0) {
                matriz[i][j] = 1;
            }
        }
    }
    exibirMatriz(matriz);
    
    // ========== 6. CONTAR ELEMENTOS EM UMA LINHA ESPECÍFICA ==========
    int linhaEscolhida = 2;
    int soma = 0;
    for (int j = 0; j < COL; j++) {
        soma += matriz[linhaEscolhida][j];
    }
    printf("\nSoma dos elementos da linha %d: %d\n", linhaEscolhida, soma);
    
    // ========== 7. VALIDAR SIMETRIA (CONDIÇÃO COMPLEXA) ==========
    // Verifica se a matriz é simétrica (quadrada e A[i][j] == A[j][i])
    bool simetrica = true;
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            if (i != j && matriz[i][j] != matriz[j][i]) {
                simetrica = false;
                break;
            }
        }
        if (!simetrica) break;
    }
    printf("A matriz %s simétrica.\n", simetrica ? "é" : "não é");
    
    // ========== 8. DIAGONAL PRINCIPAL COM CONDIÇÃO ==========
    printf("\n=== DIAGONAL PRINCIPAL ===\n");
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == j)
                printf("%3d ", matriz[i][j]);
            else
                printf("    ");
        }
        printf("\n");
    }
    
    return 0;
}