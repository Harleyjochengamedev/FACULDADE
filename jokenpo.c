#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int jogador, computador, opcao;
    srand(time(NULL));
    
    do {
        printf("\n=== JOKENPO ===\n");
        printf("1. Jogar\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("\nEscolha sua jogada:\n");
                printf("1 - Pedra\n");
                printf("2 - Papel\n");
                printf("3 - Tesoura\n");
                printf("Sua jogada: ");
                scanf("%d", &jogador);
                
                if(jogador < 1 || jogador > 3) {
                    printf("Opção inválida!\n");
                    break;
                }
                
                computador = rand() % 3 + 1;
                
                printf("\nVocê: ");
                switch(jogador) {
                    case 1: printf("Pedra\n"); break;
                    case 2: printf("Papel\n"); break;
                    case 3: printf("Tesoura\n"); break;
                }
                printf("Computador: ");
                switch(computador) {
                    case 1: printf("Pedra\n"); break;
                    case 2: printf("Papel\n"); break;
                    case 3: printf("Tesoura\n"); break;
                }
                
                if(jogador == computador)
                    printf("\nEmpate!\n");
                else if((jogador == 1 && computador == 3) ||
                        (jogador == 2 && computador == 1) ||
                        (jogador == 3 && computador == 2))
                    printf("\nVocê venceu!\n");
                else
                    printf("\nComputador venceu!\n");
                break;
                
            case 0:
                printf("Saindo...\n");
                break;
                
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);
    
    return 0;
}