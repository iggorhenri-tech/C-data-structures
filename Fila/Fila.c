#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct {
    int vet[TAM];
    int F, R;
} filavet;

void enfileirar(int valor, filavet *p) {
    if (p->R == TAM - 1) {
        printf("\n⚠️  Fila Cheia!\n");
        exit(0);
    }
    p->R++;
    p->vet[p->R] = valor;
}

int desenfileirar(filavet *p) {
    int aux;
    if (p->F == TAM) {
        printf("\n⚠️  Fila Vazia\n");
        exit(1);
    }
    aux = p->vet[p->F];
    p->F++;
    return aux;
}

int main() {
    int opc;
    filavet fila;
    int valor;
    fila.R = -1;
    fila.F = 0;
    
    printf("=====================================\n");
    printf("  🚀 Fila Simples com Vetor (TAM=10)\n");
    printf("=====================================\n\n");
    
    for (int i = 0; i < TAM; i++) {
        printf("Digite o valor [%d/%d]: ", i + 1, TAM);
        scanf("%d", &valor);
        enfileirar(valor, &fila);
    }
    
    printf("\n=====================================\n");
    printf("   📤 Removendo elementos da fila\n");
    printf("=====================================\n");
    
    for (int i = 0; i < TAM; i++) {
        printf("Elemento %2d ➝ %d\n", i + 1, desenfileirar(&fila));
    }
    
    printf("\n✅ Fim da execução!\n");
}
