#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *c, int numero) {
    printf("\n--- Cadastro da Carta %d ---\n", numero);
    printf("Nome do país: ");
    scanf(" %[^\n]", c->nome);
    printf("População (habitantes): ");
    scanf("%lu", &c->populacao);
    printf("Área (km²): ");
    scanf("%f", &c->area);
    printf("PIB (em bilhões de dólares): ");
    scanf("%f", &c->pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);
    
    // Cálculo da densidade demográfica (habitantes / área)
    c->densidade = (float)c->populacao / c->area;
}

// Exibe o menu de atributos e retorna a escolha do usuário
int exibirMenuAtributos(const char *titulo, int opcaoProibida) {
    int escolha;
    printf("\n%s\n", titulo);
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    
    // Se houver um atributo proibido (já escolhido), informa
    if(opcaoProibida != -1) {
        printf("(Obs: atributo %d não está disponível)\n", opcaoProibida);
    }
    
    printf("Escolha: ");
    scanf("%d", &escolha);
    return escolha;
}

// Função que compara dois atributos e retorna o vencedor de cada um (1=carta1, 2=carta2, 0=empate)
int compararAtributo(Carta c1, Carta c2, int atributo, float *valor1, float *valor2) {
    // Obtém os valores dos atributos (convertidos para float para facilitar)
    switch(atributo) {
        case 1: *valor1 = (float)c1.populacao; *valor2 = (float)c2.populacao; break;
        case 2: *valor1 = c1.area; *valor2 = c2.area; break;
        case 3: *valor1 = c1.pib; *valor2 = c2.pib; break;
        case 4: *valor1 = (float)c1.pontosTuristicos; *valor2 = (float)c2.pontosTuristicos; break;
        case 5: *valor1 = c1.densidade; *valor2 = c2.densidade; break;
        default: return -1;
    }
    
    // Regra: densidade (atributo 5) vence o menor; outros vence o maior
    if(atributo == 5) {
        if(*valor1 < *valor2) return 1;
        else if(*valor2 < *valor1) return 2;
        else return 0;
    } else {
        if(*valor1 > *valor2) return 1;
        else if(*valor2 > *valor1) return 2;
        else return 0;
    }
}

// Exibe o nome do atributo
void nomeAtributo(int atributo, char *nome) {
    switch(atributo) {
        case 1: sprintf(nome, "População"); break;
        case 2: sprintf(nome, "Área"); break;
        case 3: sprintf(nome, "PIB"); break;
        case 4: sprintf(nome, "Pontos Turísticos"); break;
        case 5: sprintf(nome, "Densidade Demográfica"); break;
        default: sprintf(nome, "Desconhecido");
    }
}

int main() {
    Carta carta1, carta2;
    int opcaoMenu, atributo1, atributo2;
    
    printf("===== SUPER TRUNFO - NÍVEL MESTRE =====\n");
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);
    
    do {
        printf("\n========== MENU PRINCIPAL ==========\n");
        printf("1 - Jogar (comparar duas cartas)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcaoMenu);
        
        switch(opcaoMenu) {
            case 1:
                // Escolha do PRIMEIRO atributo
                atributo1 = exibirMenuAtributos("Escolha o PRIMEIRO atributo para comparação:", -1);
                if(atributo1 < 1 || atributo1 > 5) {
                    printf("Opção inválida! Tente novamente.\n");
                    break;
                }
                
                // Escolha do SEGUNDO atributo (não pode ser igual ao primeiro)
                do {
                    atributo2 = exibirMenuAtributos("Escolha o SEGUNDO atributo (diferente do primeiro):", atributo1);
                    if(atributo2 == atributo1) {
                        printf("ERRO: Você não pode escolher o mesmo atributo! Escolha outro.\n");
                    } else if(atributo2 < 1 || atributo2 > 5) {
                        printf("Opção inválida! Escolha entre 1 e 5.\n");
                        atributo2 = atributo1;  // força repetir
                    }
                } while(atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5);
                
                // Nomes dos atributos para exibição
                char nomeAttr1[30], nomeAttr2[30];
                nomeAtributo(atributo1, nomeAttr1);
                nomeAtributo(atributo2, nomeAttr2);
                
                printf("\n==============================================\n");
                printf("Comparando: %s vs %s\n", carta1.nome, carta2.nome);
                printf("Atributos escolhidos: %s e %s\n", nomeAttr1, nomeAttr2);
                printf("==============================================\n");
                
                // Comparação individual dos dois atributos
                float val1_1, val1_2, val2_1, val2_2;
                int res1 = compararAtributo(carta1, carta2, atributo1, &val1_1, &val1_2);
                int res2 = compararAtributo(carta1, carta2, atributo2, &val2_1, &val2_2);
                
                // Exibe valores do primeiro atributo
                printf("\n[%s]\n", nomeAttr1);
                printf("  %s: %.2f\n", carta1.nome, val1_1);
                printf("  %s: %.2f\n", carta2.nome, val1_2);
                if(res1 == 1) printf("  -> Vantagem: %s\n", carta1.nome);
                else if(res1 == 2) printf("  -> Vantagem: %s\n", carta2.nome);
                else printf("  -> Empate neste atributo!\n");
                
                // Exibe valores do segundo atributo
                printf("\n[%s]\n", nomeAttr2);
                printf("  %s: %.2f\n", carta1.nome, val2_1);
                printf("  %s: %.2f\n", carta2.nome, val2_2);
                if(res2 == 1) printf("  -> Vantagem: %s\n", carta1.nome);
                else if(res2 == 2) printf("  -> Vantagem: %s\n", carta2.nome);
                else printf("  -> Empate neste atributo!\n");
                
                // Soma dos valores dos dois atributos para cada carta (valores numéricos brutos)
                float soma1 = val1_1 + val2_1;
                float soma2 = val1_2 + val2_2;
                
                printf("\n==============================================\n");
                printf("SOMA DOS ATRIBUTOS:\n");
                printf("  %s: %.2f\n", carta1.nome, soma1);
                printf("  %s: %.2f\n", carta2.nome, soma2);
                
                // Operador ternário aninhado para determinar vencedor
                printf("\nRESULTADO FINAL: ");
                printf("%s\n", (soma1 > soma2) ? "VENCEDOR: " + carta1.nome ? 
                       (soma1 > soma2) ? carta1.nome : (soma1 < soma2) ? carta2.nome : "Empate!"); // simplificar
                // Melhor escrever com if-else para clareza (mas o desafio pede operador ternário)
                // Vamos usar ternário mesmo:
                printf("%s\n", soma1 > soma2 ? carta1.nome : (soma1 < soma2 ? carta2.nome : "Empate!"));
                printf("==============================================\n");
                break;
                
            case 0:
                printf("\nEncerrando o Super Trunfo. Até a próxima!\n");
                break;
                
            default:
                printf("\nOpção inválida! Digite 1 para jogar ou 0 para sair.\n");
        }
    } while(opcaoMenu != 0);
    
    return 0;
}