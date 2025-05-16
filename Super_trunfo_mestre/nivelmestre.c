#include <stdio.h>

#define MAX_CARTAS 3  // Número máximo de cartas a cadastrar

// Estrutura para armazenar os dados da carta
typedef struct {
    char estado;
    char codigo[6];
    char nomeCidade[85];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
} Carta;

// Função para cadastrar uma carta (entrada de dados)
void cadastrarCarta(Carta *carta, int numero) {
    printf("\n=== Cadastro da Carta %d ===\n", numero + 1);
    printf("Estado: ");
    scanf(" %c", &carta->estado);
    printf("Código: ");
    scanf("%5s", carta->codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);
    printf("População: ");
    scanf("%d", &carta->populacao);
    printf("Área (km²): ");
    scanf("%f", &carta->area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);
    printf("Pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

// Função para calcular a densidade populacional
float calcularDensidade(int populacao, float area) {
    return populacao / area;
}

// Função para calcular o PIB per capita
float calcularPIBPerCapita(float pib, int populacao) {
    return (pib * 1000000000) / populacao;
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta, int numero) {
    printf("\n=== Dados da Carta %d ===\n", numero + 1);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade populacional: %.2f habitantes/km²\n", carta.densidade);
    printf("PIB per capita: R$ %.2f\n", carta.pibPerCapita);
}

int main() {
    Carta cartas[MAX_CARTAS];

    // Cadastra todas as cartas e calcula os indicadores
    for (int i = 0; i < MAX_CARTAS; i++) {
        cadastrarCarta(&cartas[i], i);
        cartas[i].densidade = calcularDensidade(cartas[i].populacao, cartas[i].area);
        cartas[i].pibPerCapita = calcularPIBPerCapita(cartas[i].pib, cartas[i].populacao);
    }

    // Exibe todas as cartas cadastradas
    for (int i = 0; i < MAX_CARTAS; i++) {
        exibirCarta(cartas[i], i);
    }

    return 0;
}
