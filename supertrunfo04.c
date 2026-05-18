#include <stdio.h>

int main() {
    // ================= CARTA 1 =================
    char estado1;
    char codigo1[10];
    char nomeCidade1[50];
    unsigned long int populacao1;      // populacão agora suporta números maiores
    float area1;
    float pib1;                        // PIB em bilhões de reais
    int pontosTuristicos1;

    float densidade1;
    float pibPerCapita1;
    float superPoder1;

    // ================= CARTA 2 =================
    char estado2;
    char codigo2[10];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    float densidade2;
    float pibPerCapita2;
    float superPoder2;

    // ================= LEITURA DA CARTA 1 =================
    printf("Cadastro da Carta 1:\n");
    printf("Estado (letra de A a H): ");
    scanf(" %c", &estado1);
    printf("Código (ex: A01): ");
    scanf("%s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculos da Carta 1
    densidade1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0f) / (float)populacao1;
    superPoder1 = (float)populacao1 + area1 + pib1 + (float)pontosTuristicos1 
                  + pibPerCapita1 + (1.0f / densidade1);

    // ================= LEITURA DA CARTA 2 =================
    printf("\nCadastro da Carta 2:\n");
    printf("Estado (letra de A a H): ");
    scanf(" %c", &estado2);
    printf("Código (ex: B02): ");
    scanf("%s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos da Carta 2
    densidade2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0f) / (float)populacao2;
    superPoder2 = (float)populacao2 + area2 + pib2 + (float)pontosTuristicos2 
                  + pibPerCapita2 + (1.0f / densidade2);

    // ================= EXIBIÇÃO DAS CARTAS =================
    printf("\n--- DADOS DAS CARTAS ---\n");
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // ================= COMPARAÇÕES =================
    // Array com os resultados (1 = Carta 1 vence, 0 = Carta 2 vence)
    int resultado[7];
    resultado[0] = (populacao1 > populacao2);                 // População (maior vence)
    resultado[1] = (area1 > area2);                           // Área (maior vence)
    resultado[2] = (pib1 > pib2);                             // PIB (maior vence)
    resultado[3] = (pontosTuristicos1 > pontosTuristicos2);   // Pontos Turísticos (maior vence)
    resultado[4] = (densidade1 < densidade2);                 // Densidade (menor vence)
    resultado[5] = (pibPerCapita1 > pibPerCapita2);           // PIB per Capita (maior vence)
    resultado[6] = (superPoder1 > superPoder2);               // Super Poder (maior vence)

    // Nomes dos atributos e strings de resultado
    const char* atributos[] = {"População", "Área", "PIB", "Pontos Turísticos",
                               "Densidade Populacional", "PIB per Capita", "Super Poder"};
    // Array para evitar if: índice 1 -> "Carta 1 venceu", índice 0 -> "Carta 2 venceu"
    const char* vencedor[] = {"Carta 2 venceu", "Carta 1 venceu"};

    printf("\n--- COMPARAÇÃO DE CARTAS ---\n");
    int i;
    for (i = 0; i < 7; i++) {
        printf("%s: %s (%d)\n", atributos[i], vencedor[resultado[i]], resultado[i]);
    }

    return 0;
}