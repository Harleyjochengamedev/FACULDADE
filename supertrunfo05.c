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

// Função que compara duas cartas com base no atributo escolhido
void compararCartas(Carta c1, Carta c2, int atributo) {
    printf("\n========================================\n");
    printf("Comparando: %s vs %s\n", c1.nome, c2.nome);
    
    // Exibe o atributo escolhido e seus valores
    switch(atributo) {
        case 1:
            printf("Atributo: População (vence o maior)\n");
            printf("%s: %lu habitantes\n", c1.nome, c1.populacao);
            printf("%s: %lu habitantes\n", c2.nome, c2.populacao);
            if(c1.populacao > c2.populacao)
                printf("\nVencedor: %s\n", c1.nome);
            else if(c2.populacao > c1.populacao)
                printf("\nVencedor: %s\n", c2.nome);
            else
                printf("\nEmpate!\n");
            break;
        case 2:
            printf("Atributo: Área (vence o maior)\n");
            printf("%s: %.2f km²\n", c1.nome, c1.area);
            printf("%s: %.2f km²\n", c2.nome, c2.area);
            if(c1.area > c2.area)
                printf("\nVencedor: %s\n", c1.nome);
            else if(c2.area > c1.area)
                printf("\nVencedor: %s\n", c2.nome);
            else
                printf("\nEmpate!\n");
            break;
        case 3:
            printf("Atributo: PIB (vence o maior)\n");
            printf("%s: %.2f bilhões US$\n", c1.nome, c1.pib);
            printf("%s: %.2f bilhões US$\n", c2.nome, c2.pib);
            if(c1.pib > c2.pib)
                printf("\nVencedor: %s\n", c1.nome);
            else if(c2.pib > c1.pib)
                printf("\nVencedor: %s\n", c2.nome);
            else
                printf("\nEmpate!\n");
            break;
        case 4:
            printf("Atributo: Pontos Turísticos (vence o maior)\n");
            printf("%s: %d pontos\n", c1.nome, c1.pontosTuristicos);
            printf("%s: %d pontos\n", c2.nome, c2.pontosTuristicos);
            if(c1.pontosTuristicos > c2.pontosTuristicos)
                printf("\nVencedor: %s\n", c1.nome);
            else if(c2.pontosTuristicos > c1.pontosTuristicos)
                printf("\nVencedor: %s\n", c2.nome);
            else
                printf("\nEmpate!\n");
            break;
        case 5:
            printf("Atributo: Densidade Demográfica (vence o menor)\n");
            printf("%s: %.2f hab/km²\n", c1.nome, c1.densidade);
            printf("%s: %.2f hab/km²\n", c2.nome, c2.densidade);
            // Regra invertida: menor densidade vence
            if(c1.densidade < c2.densidade)
                printf("\nVencedor: %s\n", c1.nome);
            else if(c2.densidade < c1.densidade)
                printf("\nVencedor: %s\n", c2.nome);
            else
                printf("\nEmpate!\n");
            break;
        default:
            printf("Atributo inválido!\n");
    }
    printf("========================================\n");
}

int main() {
    Carta carta1, carta2;
    int opcao;
    
    printf("===== SUPER TRUNFO - CADASTRO DAS CARTAS =====\n");
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);
    
    // Menu interativo
    do {
        printf("\n========== MENU DE COMPARAÇÃO ==========\n");
        printf("Escolha o atributo para comparar as cartas:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("0 - Sair\n");
        printf("Sua escolha: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                compararCartas(carta1, carta2, opcao);
                break;
            case 0:
                printf("\nEncerrando o jogo. Até mais!\n");
                break;
            default:
                printf("\nOpção inválida! Digite um número entre 0 e 5.\n");
        }
    } while(opcao != 0);
    
    return 0;
}