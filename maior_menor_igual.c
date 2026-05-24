#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int opcao, numJogador, tipo, numComputador;
    int venceu;  // 1 = vitória, 0 = derrota
    
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));
    
    do {
        // Menu principal
        printf("\n=== JOGO: MAIOR, MENOR OU IGUAL ===\n");
        printf("1 - Jogar\n");
        printf("2 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                // Entrada do jogador
                printf("\nDigite um número (inteiro): ");
                scanf("%d", &numJogador);
                
                printf("Escolha a comparação:\n");
                printf("1 - Maior\n");
                printf("2 - Menor\n");
                printf("3 - Igual\n");
                printf("Opção: ");
                scanf("%d", &tipo);
                
                // Gera número aleatório entre 1 e 10
                numComputador = rand() % 10 + 1;
                
                printf("\nSeu número: %d\n", numJogador);
                printf("Número do computador: %d\n", numComputador);
                
                // Lógica de comparação usando if/else if/else
                if(tipo == 1) {          // Jogador escolheu "Maior"
                    venceu = (numJogador > numComputador);
                }
                else if(tipo == 2) {     // Jogador escolheu "Menor"
                    venceu = (numJogador < numComputador);
                }
                else if(tipo == 3) {     // Jogador escolheu "Igual"
                    venceu = (numJogador == numComputador);
                }
                else {
                    printf("Opção de comparação inválida!\n");
                    break;  // Sai do case sem mostrar resultado
                }
                
                // Exibe resultado usando operador ternário
                printf("\n%s\n", venceu ? "PARABÉNS! Você venceu!" : "QUE PENA! Você perdeu!");
                break;
                
            case 2:
                printf("\nSaindo do jogo. Até mais!\n");
                break;
                
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while(opcao != 2);
    
    return 0;
}