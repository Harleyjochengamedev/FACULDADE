#include <stdio.h>

int main() {
    // Declaração das variáveis para armazenar as três notas e a média
    float nota1, nota2, nota3;
    float media;

    // Entrada das três notas fornecidas pelo usuário
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    // Cálculo da média: soma das notas dividida por 3
    media = (nota1 + nota2 + nota3) / 3;

    // Exibição do resultado com duas casas decimais
    printf("\nA média das notas é: %.2f\n", media);

    return 0;
}