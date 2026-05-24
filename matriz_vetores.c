#include <stdio.h>

#define TAM_VET 5
#define LINHAS 3
#define COLUNAS 3

// Função para exibir um vetor
void exibirVetor(int vet[], int tamanho) {
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
    printf("]\n");
}

// Função para exibir uma matriz
void exibirMatriz(int mat[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        printf("  ");
        for (int j = 0; j < COLUNAS; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("=== MANIPULAÇÃO DE VETORES E MATRIZES EM C ===\n\n");

    // ==================== PARTE 1: VETORES ====================
    printf("--- 1. VETORES (arrays unidimensionais) ---\n");
    
    int numeros[TAM_VET] = {10, 20, 30, 40, 50};
    int soma = 0;
    
    // Loop para somar os elementos
    for (int i = 0; i < TAM_VET; i++) {
        soma += numeros[i];
    }
    
    float media = (float)soma / TAM_VET;
    
    printf("Vetor: ");
    exibirVetor(numeros, TAM_VET);
    printf("Soma: %d\n", soma);
    printf("Média: %.2f\n\n", media);
    
    // ==================== PARTE 2: MATRIZES ====================
    printf("--- 2. MATRIZES (arrays bidimensionais) ---\n");
    
    int matrizA[LINHAS][COLUNAS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int matrizB[LINHAS][COLUNAS] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    
    int matrizSoma[LINHAS][COLUNAS];
    
    // Soma de duas matrizes (acesso linha a linha = eficiente)
    printf("Matriz A:\n");
    exibirMatriz(matrizA);
    printf("\nMatriz B:\n");
    exibirMatriz(matrizB);
    
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            matrizSoma[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
    
    printf("\nMatriz Soma (A + B):\n");
    exibirMatriz(matrizSoma);
    
    // ==================== PARTE 3: ACESSO EFICIENTE ====================
    printf("\n--- 3. ACESSO EFICIENTE (linha a linha) ---\n");
    printf("Acessar matriz linha por linha é mais rápido porque os elementos ficam contíguos na memória.\n");
    printf("Exemplo de preenchimento de matriz identidade (ordem correta):\n");
    
    int identidade[LINHAS][COLUNAS];
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (i == j)
                identidade[i][j] = 1;
            else
                identidade[i][j] = 0;
        }
    }
    exibirMatriz(identidade);
    
    // ==================== PARTE 4: TRANSPOSIÇÃO DE MATRIZ ====================
    printf("\n--- 4. TRANSPOSIÇÃO DE MATRIZ ---\n");
    
    int matrizOriginal[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int matrizTransposta[3][2];
    
    printf("Matriz original (2x3):\n");
    for (int i = 0; i < 2; i++) {
        printf("  ");
        for (int j = 0; j < 3; j++) {
            printf("%3d ", matrizOriginal[i][j]);
        }
        printf("\n");
    }
    
    // Transposição: linhas viram colunas
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            matrizTransposta[j][i] = matrizOriginal[i][j];
        }
    }
    
    printf("\nMatriz transposta (3x2):\n");
    for (int i = 0; i < 3; i++) {
        printf("  ");
        for (int j = 0; j < 2; j++) {
            printf("%3d ", matrizTransposta[i][j]);
        }
        printf("\n");
    }
    
    // ==================== DICAS FINAIS ====================
    printf("\n=== DICAS PARA CÓDIGO CLARO E OTIMIZADO ===\n");
    printf("1. Use constantes (#define) para tamanhos de vetores/matrizes.\n");
    printf("2. Percorra matrizes linha por linha (loop externo linhas, interno colunas).\n");
    printf("3. Evite acessos fora dos limites (índices de 0 a N-1).\n");
    printf("4. Use nomes descritivos para variáveis (linhas, colunas, soma, etc.).\n");
    printf("5. Divida o código em funções para reuso e clareza.\n");
    printf("6. Comente o que não é óbvio, mas deixe o código autoexplicativo.\n");
    
    return 0;
}