#include <stdio.h>
#include <string.h>

// Definição da estrutura para uma carta
typedef struct {
    char estado[50];
    char codigo[10];
    char nomeCidade[100];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para cadastrar uma nova carta
Carta cadastrarCarta(int numeroCarta) {
    Carta novaCarta;
    
    printf("\n=== CADASTRO DA CARTA %d ===\n", numeroCarta);
    
    printf("Digite o estado: ");
    fgets(novaCarta.estado, sizeof(novaCarta.estado), stdin);
    novaCarta.estado[strcspn(novaCarta.estado, "\n")] = '\0';
    
    printf("Digite o código da carta: ");
    fgets(novaCarta.codigo, sizeof(novaCarta.codigo), stdin);
    novaCarta.codigo[strcspn(novaCarta.codigo, "\n")] = '\0';
    
    printf("Digite o nome da cidade: ");
    fgets(novaCarta.nomeCidade, sizeof(novaCarta.nomeCidade), stdin);
    novaCarta.nomeCidade[strcspn(novaCarta.nomeCidade, "\n")] = '\0';
    
    printf("Digite a população: ");
    scanf("%lu", &novaCarta.populacao);
    
    printf("Digite a área (em km²): ");
    scanf("%f", &novaCarta.area);
    
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &novaCarta.pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &novaCarta.pontosTuristicos);
    
    limparBuffer();
    
    // Cálculo das propriedades derivadas
    if (novaCarta.area > 0) {
        novaCarta.densidadePopulacional = novaCarta.populacao / novaCarta.area;
    } else {
        novaCarta.densidadePopulacional = 0;
    }
    
    if (novaCarta.populacao > 0) {
        novaCarta.pibPerCapita = (novaCarta.pib * 1000000000) / novaCarta.populacao;
    } else {
        novaCarta.pibPerCapita = 0;
    }
    
    return novaCarta;
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta, int numeroCarta) {
    printf("\n=== CARTA %d ===\n", numeroCarta);
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %lu habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", carta.pibPerCapita);
}

// Função para comparar duas cartas
void compararCartas(Carta carta1, Carta carta2) {
    printf("\n=== COMPARAÇÃO ENTRE AS CARTAS ===\n");
    
    printf("\nAtributos para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional (menor vence)\n");
    printf("6. PIB per Capita\n");
    
    int opcao;
    printf("\nEscolha o atributo para comparar (1-6): ");
    scanf("%d", &opcao);
    
    printf("\n--- COMPARAÇÃO ---\n");
    printf("%s vs %s\n\n", carta1.nomeCidade, carta2.nomeCidade);
    
    switch(opcao) {
        case 1: // População
            printf("População:\n");
            printf("%s: %lu habitantes\n", carta1.nomeCidade, carta1.populacao);
            printf("%s: %lu habitantes\n", carta2.nomeCidade, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Vencedor: %s\n", carta1.nomeCidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Vencedor: %s\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
            }
            break;
            
        case 2: // Área
            printf("Área:\n");
            printf("%s: %.2f km²\n", carta1.nomeCidade, carta1.area);
            printf("%s: %.2f km²\n", carta2.nomeCidade, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Vencedor: %s\n", carta1.nomeCidade);
            } else if (carta2.area > carta1.area) {
                printf("Vencedor: %s\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
            }
            break;
            
        case 3: // PIB
            printf("PIB:\n");
            printf("%s: %.2f bilhões\n", carta1.nomeCidade, carta1.pib);
            printf("%s: %.2f bilhões\n", carta2.nomeCidade, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Vencedor: %s\n", carta1.nomeCidade);
            } else if (carta2.pib > carta1.pib) {
                printf("Vencedor: %s\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
            }
            break;
            
        case 4: // Pontos Turísticos
            printf("Pontos Turísticos:\n");
            printf("%s: %d\n", carta1.nomeCidade, carta1.pontosTuristicos);
            printf("%s: %d\n", carta2.nomeCidade, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Vencedor: %s\n", carta1.nomeCidade);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Vencedor: %s\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
            }
            break;
            
        case 5: // Densidade Populacional (menor vence)
            printf("Densidade Populacional (quanto menor, melhor):\n");
            printf("%s: %.2f hab/km²\n", carta1.nomeCidade, carta1.densidadePopulacional);
            printf("%s: %.2f hab/km²\n", carta2.nomeCidade, carta2.densidadePopulacional);
            if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
                printf("Vencedor: %s\n", carta1.nomeCidade);
            } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
                printf("Vencedor: %s\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
            }
            break;
            
        case 6: // PIB per Capita
            printf("PIB per Capita:\n");
            printf("%s: R$ %.2f\n", carta1.nomeCidade, carta1.pibPerCapita);
            printf("%s: R$ %.2f\n", carta2.nomeCidade, carta2.pibPerCapita);
            if (carta1.pibPerCapita > carta2.pibPerCapita) {
                printf("Vencedor: %s\n", carta1.nomeCidade);
            } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
                printf("Vencedor: %s\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
            }
            break;
            
        default:
            printf("Opção inválida!\n");
    }
}

int main() {
    printf("=== SUPER TRUNFO - PAÍSES ===\n");
    printf("Sistema de Cadastro de Cartas\n\n");
    
    // Cadastrar duas cartas
    Carta carta1 = cadastrarCarta(1);
    Carta carta2 = cadastrarCarta(2);
    
    // Exibir as cartas cadastradas
    printf("\n=== CARTAS CADASTRADAS ===\n");
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);
    
    // Opção para comparar cartas
    int opcao;
    printf("\nDeseja comparar as cartas? (1 - Sim, 0 - Não): ");
    scanf("%d", &opcao);
    
    if (opcao == 1) {
        compararCartas(carta1, carta2);
    }
    
    printf("\n=== FIM DO PROGRAMA ===\n");
    return 0;
}