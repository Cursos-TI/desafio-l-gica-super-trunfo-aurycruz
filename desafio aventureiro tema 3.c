#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char estado;
    char codigo[4];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int num_pontos_turisticos;
    float densidade;
    float pibpercapita;
} Carta;

int main() {
    Carta carta1, carta2;
    int opcao;

    printf("=== SUPER TRUNFO - NIVEL INTERMEDIARIO ===\n\n");

    // Cadastro da Carta 1
    printf("*** CARTA 1 ***\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);

    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", carta1.codigo);

    printf("Nome da Cidade: ");
    scanf("%s", carta1.nome_cidade);

    printf("Populacao: ");
    scanf("%d", &carta1.populacao);

    printf("Area (em km2): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &carta1.pib);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta1.num_pontos_turisticos);

    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pibpercapita = carta1.pib * 1000000000 / carta1.populacao;

    // Cadastro da Carta 2
    printf("\n*** CARTA 2 ***\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);

    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", carta2.codigo);

    printf("Nome da Cidade: ");
    scanf("%s", carta2.nome_cidade);

    printf("Populacao: ");
    scanf("%d", &carta2.populacao);

    printf("Area (em km2): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &carta2.pib);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta2.num_pontos_turisticos);

    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pibpercapita = carta2.pib * 1000000000 / carta2.populacao;

    // Exibição das cartas
    printf("\n=== CARTAS CADASTRADAS ===\n");
    printf("Carta 1: %s (Estado %c)\n", carta1.nome_cidade, carta1.estado);
    printf("Carta 2: %s (Estado %c)\n", carta2.nome_cidade, carta2.estado);

    // Menu de comparação
    do {
        printf("\n--- MENU DE COMPARACAO ---\n");
        printf("1. Populacao\n");
        printf("2. Area\n");
        printf("3. PIB\n");
        printf("4. Numero de Pontos Turisticos\n");
        printf("5. Densidade Demografica\n");
        printf("6. Sair\n");
        printf("Escolha um atributo para comparar: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nComparando POPULACAO:\n");
                printf("%s: %d habitantes\n", carta1.nome_cidade, carta1.populacao);
                printf("%s: %d habitantes\n", carta2.nome_cidade, carta2.populacao);
                if (carta1.populacao > carta2.populacao)
                    printf("➡ %s venceu!\n", carta1.nome_cidade);
                else if (carta2.populacao > carta1.populacao)
                    printf("➡ %s venceu!\n", carta2.nome_cidade);
                else
                    printf("Empate!\n");
                break;

            case 2:
                printf("\nComparando AREA:\n");
                printf("%s: %.2f km²\n", carta1.nome_cidade, carta1.area);
                printf("%s: %.2f km²\n", carta2.nome_cidade, carta2.area);
                if (carta1.area > carta2.area)
                    printf("➡ %s venceu!\n", carta1.nome_cidade);
                else if (carta2.area > carta1.area)
                    printf("➡ %s venceu!\n", carta2.nome_cidade);
                else
                    printf("Empate!\n");
                break;

            case 3:
                printf("\nComparando PIB:\n");
                printf("%s: %.2f bilhoes\n", carta1.nome_cidade, carta1.pib);
                printf("%s: %.2f bilhoes\n", carta2.nome_cidade, carta2.pib);
                if (carta1.pib > carta2.pib)
                    printf("➡ %s venceu!\n", carta1.nome_cidade);
                else if (carta2.pib > carta1.pib)
                    printf("➡ %s venceu!\n", carta2.nome_cidade);
                else
                    printf("Empate!\n");
                break;

            case 4:
                printf("\nComparando PONTOS TURISTICOS:\n");
                printf("%s: %d pontos\n", carta1.nome_cidade, carta1.num_pontos_turisticos);
                printf("%s: %d pontos\n", carta2.nome_cidade, carta2.num_pontos_turisticos);
                if (carta1.num_pontos_turisticos > carta2.num_pontos_turisticos)
                    printf("➡ %s venceu!\n", carta1.nome_cidade);
                else if (carta2.num_pontos_turisticos > carta1.num_pontos_turisticos)
                    printf("➡ %s venceu!\n", carta2.nome_cidade);
                else
                    printf("Empate!\n");
                break;

            case 5:
                printf("\nComparando DENSIDADE DEMOGRAFICA:\n");
                printf("%s: %.2f hab/km²\n", carta1.nome_cidade, carta1.densidade);
                printf("%s: %.2f hab/km²\n", carta2.nome_cidade, carta2.densidade);
                // Regra invertida: menor vence!
                if (carta1.densidade < carta2.densidade)
                    printf("➡ %s venceu! (menor densidade)\n", carta1.nome_cidade);
                else if (carta2.densidade < carta1.densidade)
                    printf("➡ %s venceu! (menor densidade)\n", carta2.nome_cidade);
                else
                    printf("Empate!\n");
                break;

            case 6:
                printf("\nSaindo do jogo...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}

