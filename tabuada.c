#include <stdio.h>

int main() {
    int numero, i, opcao;
    
    printf("=== TABUADA - FOR, WHILE e DO-WHILE ===\n");
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);
    
    do {
        printf("\nEscolha o tipo de loop:\n");
        printf("1 - for\n");
        printf("2 - while\n");
        printf("3 - do-while\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: // LOOP FOR
                printf("\n--- Tabuada do %d usando FOR ---\n", numero);
                for(i = 1; i <= 10; i++) {
                    printf("%d x %2d = %2d\n", numero, i, numero * i);
                }
                break;
                
            case 2: // LOOP WHILE
                printf("\n--- Tabuada do %d usando WHILE ---\n", numero);
                i = 1;
                while(i <= 10) {
                    printf("%d x %2d = %2d\n", numero, i, numero * i);
                    i++;
                }
                break;
                
            case 3: // LOOP DO-WHILE
                printf("\n--- Tabuada do %d usando DO-WHILE ---\n", numero);
                i = 1;
                do {
                    printf("%d x %2d = %2d\n", numero, i, numero * i);
                    i++;
                } while(i <= 10);
                break;
                
            case 0:
                printf("Encerrando o programa.\n");
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 0);
    
    return 0;
}