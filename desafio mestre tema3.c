#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da carta
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
    int opcao1, opcao2;
    float valor1_c1, valor1_c2;
    float valor2_c1, valor2_c2;
    float soma_c1, soma_c2;

    printf("=== SUPER TRUNFO - NIVEL MESTRE ===\n\n");

    // Cadastro da Carta 1
    printf("*** CADASTRO DA CARTA 1 ***\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);

    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", carta1.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta1.nome_cidade);

    printf("Populacao: ");
    scanf("%d", &carta1.populacao);

    printf("Area (em km2): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhoes): ");
    scanf("%f", &carta1.pib);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta1.num_pontos_turisticos);

    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pibpercapita = (carta1.pib * 1000000000) / carta1.populacao;

    // Cadastro da Carta 2
    printf("\n*** CADASTRO DA CARTA 2 ***\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);

    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", carta2.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta2.nome_cidade);

    printf("Populacao: ");
    scanf("%d", &carta2.populacao);

    printf("Area (em km2): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhoes): ");
    scanf("%f", &carta2.pib);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta2.num_pontos_turisticos);

    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pibpercapita = (carta2.pib * 1000000000) / carta2.populacao;

    // Menu de atributos
    printf("\n=== MENU DE ATRIBUTOS ===\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Numero de Pontos Turisticos\n");
    printf("5. Densidade Demografica\n");
    printf("6. PIB per Capita\n");

    // Escolha do primeiro atributo
    printf("\nEscolha o PRIMEIRO atributo para comparar: ");
    scanf("%d", &opcao1);

    // Menu dinâmico: não permite escolher o mesmo atributo duas vezes
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i != opcao1) {
            switch (i) {
                case 1: printf("1. Populacao\n"); break;
                case 2: printf("2. Area\n"); break;
                case 3: printf("3. PIB\n"); break;
                case 4: printf("4. Pontos Turisticos\n"); break;
                case 5: printf("5. Densidade Demografica\n"); break;
                case 6: printf("6. PIB per Capita\n"); break;
            }
        }
    }
    printf("Escolha: ");
    scanf("%d", &opcao2);

    // Função auxiliar: atribui valores baseados na escolha
    float pegarValor(Carta c, int opcao) {
        switch (opcao) {
            case 1: return c.populacao;
            case 2: return c.area;
            case 3: return c.pib;
            case 4: return c.num_pontos_turisticos;
            case 5: return c.densidade;
            case 6: return c.pibpercapita;
            default: return 0;
        }
    }

    // Pegando os valores escolhidos
    valor1_c1 = pegarValor(carta1, opcao1);
    valor1_c2 = pegarValor(carta2, opcao1);
    valor2_c1 = pegarValor(carta1, opcao2);
    valor2_c2 = pegarValor(carta2, opcao2);

    // Comparação e soma
    printf("\n=== RESULTADO DA COMPARACAO ===\n");
    printf("Comparando %s e %s\n", carta1.nome_cidade, carta2.nome_cidade);

    // Atributo 1
    printf("\nAtributo 1: ");
    switch (opcao1) {
        case 1: printf("Populacao\n"); break;
        case 2: printf("Area\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turisticos\n"); break;
        case 5: printf("Densidade Demografica\n"); break;
        case 6: printf("PIB per Capita\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n", carta1.nome_cidade, valor1_c1, carta2.nome_cidade, valor1_c2);

    // Atributo 2
    printf("\nAtributo 2: ");
    switch (opcao2) {
        case 1: printf("Populacao\n"); break;
        case 2: printf("Area\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turisticos\n"); break;
        case 5: printf("Densidade Demografica\n"); break;
        case 6: printf("PIB per Capita\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n", carta1.nome_cidade, valor2_c1, carta2.nome_cidade, valor2_c2);

    // Soma (lembrando: densidade é o único atributo onde MENOR vence)
    soma_c1 = valor1_c1 + valor2_c1;
    soma_c2 = valor1_c2 + valor2_c2;

    printf("\nSoma dos Atributos:\n");
    printf("%s: %.2f | %s: %.2f\n", carta1.nome_cidade, soma_c1, carta2.nome_cidade, soma_c2);

    // Lógica do vencedor
    if (soma_c1 == soma_c2)
        printf("\nResultado: EMPATE!\n");
    else {
        // Regra especial: se um dos atributos for densidade, inverta a comparação apenas dele
        float bonus1 = (opcao1 == 5) ? -valor1_c1 : valor1_c1;
        float bonus2 = (opcao2 == 5) ? -valor2_c1 : valor2_c1;
        float bonus3 = (opcao1 == 5) ? -valor1_c2 : valor1_c2;
        float bonus4 = (opcao2 == 5) ? -valor2_c2 : valor2_c2;

        soma_c1 = bonus1 + bonus2;
        soma_c2 = bonus3 + bonus4;

        printf("\n🏆 Vencedor: %s\n", (soma_c1 > soma_c2) ? carta1.nome_cidade : carta2.nome_cidade);
    }

    printf("\n=== FIM DA COMPARACAO ===\n");
    return 0;
}

