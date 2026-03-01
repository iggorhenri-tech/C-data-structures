#include <stdio.h>

typedef struct {
    int id;
    char marca[30];
    char modelo[30];
    int ano;
    float tanque;
    float consumo;
} carro;

carro cadastrar(void) {
    carro c;
    
    printf("  Placa: ");
    scanf("%d", &c.id);
    
    printf("  Marca: ");
    scanf("%29s", c.marca);
    
    printf("  Modelo: ");
    scanf("%29s", c.modelo);
    
    printf("  Ano: ");
    scanf("%d", &c.ano);
    
    printf("  Tanque (litros): ");
    scanf("%f", &c.tanque);
    
    printf("  Consumo (km/l): ");
    scanf("%f", &c.consumo);
    
    return c;
}

void imprimir(carro c) {
    
    printf("\n [%03d] %-12s | %-12s | %d", c.id, c.marca, c.modelo, c.ano);
    printf("\n       Tanque: %4.1fL  | Consumo: %4.1f km/l | Autonomia: %.1f km", 
           c.tanque, c.consumo, c.tanque * c.consumo);
    printf("\n ------------------------------------------------------------------");
}

int main(void) {
    int n;
    
    printf("========================================");
    printf("\n       SISTEMA DE GESTAO DE FROTA       ");
    printf("\n========================================\n");
    
    printf(" Quantos carros serao cadastrados? ");
    scanf("%d", &n);

 if (n <= 0) {
    printf("\nQuantidade inválida!\nDigite um valor maior que 0,\n");
    return 1; 
}

    carro veiculo[n];

    for (int i = 0; i < n; i++) {
        printf("\n>>> CADASTRO DO CARRO #%d <<<\n", i + 1);
        veiculo[i] = cadastrar();
    }
    
    printf("\n\n===================================================================");
    printf("\n                  LISTA DE CARROS E AUTONOMIA");
    printf("\n===================================================================");
    
    for (int i = 0; i < n; i++) {
        imprimir(veiculo[i]);
    }
    
    printf("\n\n Fim do relatorio.\n");

    return 0;
}
