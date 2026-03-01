#include <stdio.h>

typedef struct {
    char nome[40];
    int idade;
    float renda;
} contribuinte;

int main() {
    int n;
    
    printf("========================================\n");
    printf("       SISTEMA DE CONTRIBUINTES         \n");
    printf("========================================\n");
    
    printf("Digite a quantidade de contribuintes: ");
    scanf("%d", &n);
    
    if (n != 1) {
    printf("Erro: Apenas o numero 1 é aceito.\n");
    return 1; 
}

    contribuinte pessoas[n];
    int menor = 0;
    int isentas = 0;

    for (int i = 0; i < n; i++) {
        printf("\n--- Dados do %dº Contribuinte ---\n", i + 1);
        
        printf("  Nome: ");
        scanf(" %39[^\n]", pessoas[i].nome);

        printf("  Idade: ");
        scanf("%d", &pessoas[i].idade);

        printf("  Renda Anual: R$ ");
        scanf("%f", &pessoas[i].renda);

        if (pessoas[i].idade < 18)
            menor++;
        if (pessoas[i].renda <= 28559.70)
            isentas++;
    }

    printf("\n\n========================================");
    printf("\n           RESUMO DOS DADOS             ");
    printf("\n========================================");
    printf("\n > Menores de idade:      %d", menor);
    printf("\n > Isentos de IR:         %d", isentas);
    printf("\n----------------------------------------");

    printf("\n\n%-3s | %-20s | %-5s | %-10s", "ID", "NOME", "IDADE", "RENDA");
    printf("\n----------------------------------------------------");

    for (int i = 0; i < n; i++) {
        printf("\n%02d  | %-20s | %-5d | R$ %8.2f", 
                i + 1, 
                pessoas[i].nome, 
                pessoas[i].idade, 
                pessoas[i].renda);
    }
    
    printf("\n----------------------------------------------------");
    printf("\n\nProcesso finalizado com sucesso.\n");

    return 0;
}
