#include <stdio.h>

typedef struct {
    char estado;
    char codigo[4]; // Ex: "A01" + '\0'
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int num_pontos_turisticos;
    float densidade;
    float densidadeinv;
    float pibpercapita;
    float superpoder;
    float totalatributos;
} Carta;

int main (){
    printf("Desafio comparando cartas da logica do jogo  de super trunfo nivel novato.\n");

Carta carta1, carta2;

// carta1
printf("*** CARTA 1 ***\n");

printf("Estado (A-H): ");
scanf("%s", &carta1.estado);

printf("Codigo da Carta (ex: A01): ");
scanf("%s", &carta1.codigo);

printf("Nome da Cidade: ");
scanf("%s", &carta1.nome_cidade);

printf("Populacao: ");
scanf("%d", &carta1.populacao);

printf("Area (em km2): ");
scanf("%f", &carta1.area);

printf("PIB (em bilhoes de reais): ");
scanf("%f", &carta1.pib);

printf("Numero de Pontos Turísticos: ");
scanf("%d", &carta1.num_pontos_turisticos);

carta1.densidade = (float)carta1.populacao / carta1.area;
carta1.densidadeinv = carta1.area / (float)carta1.populacao;
carta1.pibpercapita = carta1.pib * 1000000000 / (float)carta1.populacao ;
carta1.superpoder = (float)carta1.populacao + carta1.area + carta1.pib + (float)carta1.num_pontos_turisticos + carta1.densidadeinv + carta1.pibpercapita;

//Carta2
printf("*** CARTA 2 ***\n");

printf("Estado (A-H): ");
scanf("%s", &carta2.estado);

printf("Codigo da Carta (ex: A01): ");
scanf("%s", &carta2.codigo);

printf("Nome da Cidade: ");
scanf("%s", &carta2.nome_cidade);

printf("Populacao: ");
scanf("%d", &carta2.populacao);

printf("Area (em km2): ");
scanf("%f", &carta2.area);

printf("PIB (em bilhoes de reais): ");
scanf("%f", &carta2.pib);

printf("Numero de Pontos Turísticos: ");
scanf("%d", &carta2.num_pontos_turisticos);

carta2.densidade = (float)carta2.populacao / carta2.area;
carta2.densidadeinv = carta2.area / (float)carta2.populacao;
carta2.pibpercapita = carta2.pib * 1000000000 / (float)carta2.populacao ;
carta2.superpoder = (float)carta2.populacao + carta2.area + carta2.pib + (float)carta2.num_pontos_turisticos + carta2.densidadeinv + carta2.pibpercapita;

printf(" ### Cartas Cadastradas ###\n");

    //Dados Carta 1

    // Exibicao da Carta 1
    printf("\nCarta 1 =>\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Codigo: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.nome_cidade);
    printf("Populacao: %d\n", carta1.populacao);
    printf("Area: %.2f km2\n", carta1.area);
    printf("PIB: %.2f bilhoes de reais\n", carta1.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta1.num_pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidade);
    printf("PIB per Capita: %.2f reais\n", carta1.pibpercapita);


    // Exibicao da Carta 2
    printf("\nCarta 2 =>\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.nome_cidade);
    printf("Populacao: %d\n", carta2.populacao);
    printf("Area: %.2f km2\n", carta2.area);
    printf("PIB: %.2f bilhoes de reais\n", carta2.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta2.num_pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidade);
    printf("PIB per Capita: %.2f reais\n", carta2.pibpercapita);

    printf("**** Comparacao dos atributos das duas Cartas ****\n");

    if (carta1.populacao > carta2.populacao) {
        printf("carta1 venceu!\n");
    } else {
        printf("carta2 venceu!\n");
    }

    if (carta1.area > carta2.area) {
        printf("carta1 venceu!\n");
    } else {
        printf("carta2 venceu!\n");
    }

        if (carta1.pib > carta2.pib) {
        printf("carta1 venceu!\n");
    } else {
        printf("carta2 venceu!\n");
    }

        if (carta1.num_pontos_turisticos > carta2.num_pontos_turisticos) {
        printf("carta1 venceu!\n");
    } else {
        printf("carta2 venceu!\n");
    }

        if (carta1.densidadeinv > carta2.densidadeinv) {
        printf("carta1 venceu!\n");
    } else {
        printf("carta2 venceu!\n");
    }

        if (carta1.pibpercapita > carta2.pibpercapita) {
        printf("carta1 venceu!\n");
    } else {
        printf("carta2 venceu!\n");
    }

        if (carta1.superpoder > carta2.superpoder) {
        printf("carta1 venceu!\n");
    } else {
        printf("carta2 venceu!\n");
    }

    printf("****Resultado da comparacao dos atributos das duas cartas****\n");
    
    if (carta1.totalatributos > carta2.totalatributos) {
        printf("carta1 venceu!\n");
    } else {
        printf(" carta2 venceu!\n");
    }

   
   


   

    

return 0;
}