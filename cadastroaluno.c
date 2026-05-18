#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 100

/* Estrutura para armazenar os dados de cada aluno */
struct Aluno {
    char nome[50];
    int matricula;
    float altura;
    int idade;
};

int main() {
    struct Aluno turma[MAX_ALUNOS];
    int total = 0;
    int opcao;
    int i, encontrado, mat;
    int len; /* substitui size_t para compatibilidade simples */

    do {
        printf("\n=== Cadastro de Alunos da Turma ===\n");
        printf("1 - Cadastrar novo aluno\n");
        printf("2 - Listar todos os alunos\n");
        printf("3 - Aumentar altura de um aluno (ex.: +5 cm)\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); /* limpa o '\n' deixado pelo scanf */

        switch(opcao) {
            case 1:
                if (total >= MAX_ALUNOS) {
                    printf("Limite de alunos atingido!\n");
                    break;
                }

                printf("\nCadastrando aluno %d:\n", total + 1);
                printf("Nome: ");
                fgets(turma[total].nome, 50, stdin);
                /* remove o newline que o fgets armazena */
                len = strlen(turma[total].nome);
                if (len > 0 && turma[total].nome[len - 1] == '\n')
                    turma[total].nome[len - 1] = '\0';

                printf("Matricula: ");
                scanf("%d", &turma[total].matricula);

                printf("Altura (em metros, ex: 1.75): ");
                scanf("%f", &turma[total].altura);

                printf("Idade: ");
                scanf("%d", &turma[total].idade);
                getchar(); /* limpa buffer apos leitura de inteiro */

                total++;
                printf("Aluno cadastrado com sucesso!\n");
                break;

            case 2:
                if (total == 0) {
                    printf("\nNenhum aluno cadastrado.\n");
                } else {
                    printf("\n--- Alunos Cadastrados ---\n");
                    for (i = 0; i < total; i++) {
                        printf("Aluno %d:\n", i + 1);
                        printf("  Nome: %s\n", turma[i].nome);
                        printf("  Matricula: %d\n", turma[i].matricula);
                        printf("  Altura: %.2f m\n", turma[i].altura);
                        printf("  Idade: %d anos\n\n", turma[i].idade);
                    }
                }
                break;

            case 3:
                if (total == 0) {
                    printf("\nNenhum aluno cadastrado para alterar.\n");
                } else {
                    printf("\nDigite a matricula do aluno que tera a altura aumentada: ");
                    scanf("%d", &mat);
                    getchar();
                    encontrado = 0;
                    for (i = 0; i < total; i++) {
                        if (turma[i].matricula == mat) {
                            /* Uso do operador de atribuicao composto += */
                            turma[i].altura += 0.05;  /* aumenta 5 cm */
                            printf("Altura do aluno %s atualizada para %.2f m.\n",
                                   turma[i].nome, turma[i].altura);
                            encontrado = 1;
                            break;
                        }
                    }
                    if (!encontrado)
                        printf("Matricula nao encontrada.\n");
                }
                break;

            case 4:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}