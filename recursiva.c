#include <stdio.h>

// Função recursiva para imprimir de 1 até n
void imprimirRecursivo(int atual, int limite) {
    if (atual > limite) return;  // caso base
    printf("%d ", atual);
    imprimirRecursivo(atual + 1, limite);
}

int main() {
    printf("=== Imprimindo de 1 a 10 ===\n\n");
    
    // 1. Usando loop FOR
    printf("1. Usando FOR:\n");
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n\n");
    
    // 2. Usando loop WHILE
    printf("2. Usando WHILE:\n");
    int j = 1;
    while (j <= 10) {
        printf("%d ", j);
        j++;
    }
    printf("\n\n");
    
    // 3. Usando loop DO-WHILE
    printf("3. Usando DO-WHILE:\n");
    int k = 1;
    do {
        printf("%d ", k);
        k++;
    } while (k <= 10);
    printf("\n\n");
    
    // 4. Usando recursividade
    printf("4. Usando RECURSIVIDADE:\n");
    imprimirRecursivo(1, 10);
    printf("\n\n");
    
    return 0;
}