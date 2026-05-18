#include <stdio.h>

int main() {
    // ================= PRODUTO 1 =================
    char codigo1[20], nome1[50];
    unsigned long int estoque1;        // quantidade em estoque (sem sinal, para números grandes)
    long double precoUnitario1;        // preço unitário com alta precisão
    long double valorTotal1;           // valor total do estoque

    printf("Cadastro do Produto 1:\n");
    printf("Código: ");
    scanf("%s", codigo1);
    printf("Nome: ");
    scanf(" %[^\n]", nome1);
    printf("Quantidade em estoque: ");
    scanf("%lu", &estoque1);
    printf("Preço unitário (R$): ");
    scanf("%Lf", &precoUnitario1);

    // Cálculo do valor total do estoque
    valorTotal1 = estoque1 * precoUnitario1;

    // ================= PRODUTO 2 =================
    char codigo2[20], nome2[50];
    unsigned long int estoque2;
    long double precoUnitario2;
    long double valorTotal2;

    printf("\nCadastro do Produto 2:\n");
    printf("Código: ");
    scanf("%s", codigo2);
    printf("Nome: ");
    scanf(" %[^\n]", nome2);
    printf("Quantidade em estoque: ");
    scanf("%lu", &estoque2);
    printf("Preço unitário (R$): ");
    scanf("%Lf", &precoUnitario2);

    // Cálculo do valor total do estoque
    valorTotal2 = estoque2 * precoUnitario2;

    // ================= COMPARAÇÕES (sem if/else) =================
    // Usamos operadores relacionais e armazenamos o resultado (0 ou 1)
    int maiorEstoque = (estoque1 > estoque2);           // 1 se Produto 1 tiver mais estoque
    int maiorValorTotal = (valorTotal1 > valorTotal2);  // 1 se Produto 1 tiver maior valor total
    int estoqueIgual = (estoque1 == estoque2);          // 1 se quantidades forem iguais

    // ================= EXIBIÇÃO DOS RESULTADOS =================
    printf("\n--- INVENTÁRIO ---\n");

    printf("\nProduto 1: %s (%s)\n", nome1, codigo1);
    printf("  Estoque: %lu unidades\n", estoque1);
    printf("  Preço unitário: R$ %.2Lf\n", precoUnitario1);
    printf("  Valor total: R$ %.2Lf\n", valorTotal1);

    printf("\nProduto 2: %s (%s)\n", nome2, codigo2);
    printf("  Estoque: %lu unidades\n", estoque2);
    printf("  Preço unitário: R$ %.2Lf\n", precoUnitario2);
    printf("  Valor total: R$ %.2Lf\n", valorTotal2);

    // Exibição das comparações (1 = verdadeiro, 0 = falso)
    printf("\n--- COMPARAÇÕES (1 = Verdadeiro, 0 = Falso) ---\n");
    printf("Produto 1 tem MAIS estoque que Produto 2? %d\n", maiorEstoque);
    printf("Produto 1 tem MAIOR valor total que Produto 2? %d\n", maiorValorTotal);
    printf("Os estoques são IGUAIS? %d\n", estoqueIgual);

    return 0;
}