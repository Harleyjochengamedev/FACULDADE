#include <stdio.h>

#define MAX_ALUNOS 50
#define MAX_MATERIAS 10

int main() {
    // ========== DECLARAÇÃO ==========
    // Vetor para armazenar os nomes dos alunos (strings)
    char nomes[MAX_ALUNOS][50];
    
    // Matriz para armazenar as notas: linhas = alunos, colunas = matérias
    float notas[MAX_ALUNOS][MAX_MATERIAS];
    
    // Vetor para guardar a média de cada aluno
    float medias[MAX_ALUNOS];
    
    int numAlunos, numMaterias;
    
    // ========== ENTRADA DE DADOS ==========
    printf("=== SISTEMA DE NOTAS - ALUNOS x MATÉRIAS ===\n");
    printf("Quantos alunos? (máx %d): ", MAX_ALUNOS);
    scanf("%d", &numAlunos);
    printf("Quantas matérias? (máx %d): ", MAX_MATERIAS);
    scanf("%d", &numMaterias);
    
    // Leitura dos nomes dos alunos
    for (int i = 0; i < numAlunos; i++) {
        printf("\nNome do aluno %d: ", i + 1);
        scanf(" %[^\n]", nomes[i]);  // lê string com espaços
    }
    
    // Leitura das notas (matriz)
    printf("\n--- LANÇAMENTO DE NOTAS ---\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("\nAluno: %s\n", nomes[i]);
        for (int j = 0; j < numMaterias; j++) {
            printf("  Nota da matéria %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }
    
    // ========== CÁLCULO DAS MÉDIAS ==========
    for (int i = 0; i < numAlunos; i++) {
        float soma = 0;
        for (int j = 0; j < numMaterias; j++) {
            soma += notas[i][j];
        }
        medias[i] = soma / numMaterias;
    }
    
    // ========== EXIBIÇÃO DOS RESULTADOS ==========
    printf("\n\n=== BOLETIM ESCOLAR ===\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("\nAluno: %s\n", nomes[i]);
        printf("Notas: ");
        for (int j = 0; j < numMaterias; j++) {
            printf("%.1f  ", notas[i][j]);
        }
        printf("\nMédia: %.2f\n", medias[i]);
        
        // Situação simples com operador ternário
        printf("Situação: %s\n", medias[i] >= 6.0 ? "APROVADO" : "REPROVADO");
    }
    
    return 0;
}