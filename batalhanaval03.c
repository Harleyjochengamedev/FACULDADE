#include <stdio.h>
#include <stdbool.h>

#define TAM_TAB 10          // Tabuleiro 10x10
#define TAM_HAB 5           // Matriz de habilidade 5x5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++)
        for (int j = 0; j < TAM_TAB; j++)
            tabuleiro[i][j] = AGUA;
}

// Função para posicionar um navio horizontal
void posicionarHorizontal(int tabuleiro[TAM_TAB][TAM_TAB], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++)
        if (linha >= 0 && linha < TAM_TAB && coluna + i >= 0 && coluna + i < TAM_TAB)
            tabuleiro[linha][coluna + i] = NAVIO;
}

// Função para posicionar um navio vertical
void posicionarVertical(int tabuleiro[TAM_TAB][TAM_TAB], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++)
        if (linha + i >= 0 && linha + i < TAM_TAB && coluna >= 0 && coluna < TAM_TAB)
            tabuleiro[linha + i][coluna] = NAVIO;
}

// Função para posicionar um navio diagonal descendente (\)
void posicionarDiagonalDesc(int tabuleiro[TAM_TAB][TAM_TAB], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++)
        if (linha + i >= 0 && linha + i < TAM_TAB && coluna + i >= 0 && coluna + i < TAM_TAB)
            tabuleiro[linha + i][coluna + i] = NAVIO;
}

// Função para posicionar um navio diagonal ascendente (/)
void posicionarDiagonalAsc(int tabuleiro[TAM_TAB][TAM_TAB], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++)
        if (linha + i >= 0 && linha + i < TAM_TAB && coluna - i >= 0 && coluna - i < TAM_TAB)
            tabuleiro[linha + i][coluna - i] = NAVIO;
}

// -------------------- HABILIDADE 1: CONE --------------------
// Forma de cone apontando para baixo (topo estreito, base larga)
void criarMatrizCone(int matriz[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;  // índice central (2 para 5x5)
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // O cone se expande conforme aumenta a linha (i)
            // A largura em cada linha é (i+1) para baixo, mas centralizado
            int offset = centro - i;
            if (i <= centro) {
                if (j >= offset && j <= offset + 2*i)
                    matriz[i][j] = 1;
                else
                    matriz[i][j] = 0;
            } else {
                // Para i > centro, mantém a base máxima (última linha)
                if (j >= 0 && j < TAM_HAB)
                    matriz[i][j] = 1;
                else
                    matriz[i][j] = 0;
            }
        }
    }
    // Ajuste para formato exato: Para 5x5, teremos:
    // Linha0: [0,0,1,0,0]
    // Linha1: [0,1,1,1,0]
    // Linha2: [1,1,1,1,1]
    // Linha3: [1,1,1,1,1]
    // Linha4: [1,1,1,1,1]
    // Mas vamos refinar para ficar igual ao exemplo do enunciado (3 linhas de cone puro)
    // O exemplo dado mostra apenas 3 linhas, mas como nossa matriz é 5x5 faremos uma versão alongada.
    // Para seguir o exemplo, podemos fazer um cone de 3 linhas e centralizar. Vou fazer de forma que as últimas linhas sejam totalmente preenchidas.
}

// Versão mais simples e exata conforme exemplo:
void criarMatrizConeExato(int matriz[TAM_HAB][TAM_HAB]) {
    // Inicializa tudo 0
    for (int i = 0; i < TAM_HAB; i++)
        for (int j = 0; j < TAM_HAB; j++)
            matriz[i][j] = 0;
    // Define o cone nas 3 primeiras linhas (0,1,2) e mantém as outras como base
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        if (i == 0) matriz[i][centro] = 1;
        else if (i == 1) { matriz[i][centro-1] = 1; matriz[i][centro] = 1; matriz[i][centro+1] = 1; }
        else if (i == 2) { for (int j = 0; j < TAM_HAB; j++) matriz[i][j] = 1; }
        else { for (int j = 0; j < TAM_HAB; j++) matriz[i][j] = 1; }
    }
}

// -------------------- HABILIDADE 2: CRUZ --------------------
void criarMatrizCruz(int matriz[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == centro || j == centro)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// -------------------- HABILIDADE 3: OCTAEDRO (LOSANGO) --------------------
void criarMatrizOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int dist = abs(i - centro) + abs(j - centro);
            if (dist <= centro)  // losango (distância Manhattan)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Função para sobrepor uma matriz de habilidade ao tabuleiro a partir de um ponto de origem
void aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB], int habilidade[TAM_HAB][TAM_HAB], int origemLin, int origemCol) {
    int metade = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int tabLin = origemLin + (i - metade);
                int tabCol = origemCol + (j - metade);
                // Verifica se está dentro dos limites do tabuleiro
                if (tabLin >= 0 && tabLin < TAM_TAB && tabCol >= 0 && tabCol < TAM_TAB) {
                    tabuleiro[tabLin][tabCol] = HABILIDADE;
                }
            }
        }
    }
}

// Exibe o tabuleiro com legenda
void exibirTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    printf("\n   ");
    for (int col = 0; col < TAM_TAB; col++)
        printf("%2d ", col);
    printf("\n");
    for (int i = 0; i < TAM_TAB; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM_TAB; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\nLegenda: 0 = Água | 3 = Navio | 5 = Área de Habilidade\n");
}

int main() {
    int tabuleiro[TAM_TAB][TAM_TAB];
    inicializarTabuleiro(tabuleiro);
    
    // Posicionamento dos navios (4 navios: horizontal, vertical, diagonal descendente, ascendente)
    // Sem sobreposição e dentro dos limites
    posicionarHorizontal(tabuleiro, 0, 2, 3);   // (0,2),(0,3),(0,4)
    posicionarVertical(tabuleiro, 3, 7, 3);     // (3,7),(4,7),(5,7)
    posicionarDiagonalDesc(tabuleiro, 5, 0, 3); // (5,0),(6,1),(7,2)
    posicionarDiagonalAsc(tabuleiro, 7, 6, 3);  // (7,6),(8,5),(9,4)
    
    // Criar matrizes das habilidades
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];
    
    criarMatrizConeExato(cone);
    criarMatrizCruz(cruz);
    criarMatrizOctaedro(octaedro);
    
    // Aplicar habilidades no tabuleiro (origens escolhidas)
    aplicarHabilidade(tabuleiro, cone, 2, 5);      // Cone centrado em (2,5)
    aplicarHabilidade(tabuleiro, cruz, 5, 3);      // Cruz centrada em (5,3)
    aplicarHabilidade(tabuleiro, octaedro, 7, 8);  // Octaedro centrado em (7,8)
    
    // Exibir resultado final
    printf("=== BATALHA NAVAL - HABILIDADES ESPECIAIS ===\n");
    exibirTabuleiro(tabuleiro);
    
    // Exibir as matrizes de habilidade para conferência (opcional)
    printf("\n--- Matriz Cone (5x5) ---\n");
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++)
            printf("%d ", cone[i][j]);
        printf("\n");
    }
    printf("--- Matriz Cruz ---\n");
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++)
            printf("%d ", cruz[i][j]);
        printf("\n");
    }
    printf("--- Matriz Octaedro ---\n");
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++)
            printf("%d ", octaedro[i][j]);
        printf("\n");
    }
    
    return 0;
}