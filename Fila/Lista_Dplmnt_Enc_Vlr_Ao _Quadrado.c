#include <stdio.h>
#include <stdlib.h>

typedef struct dupla {
    int dado;
    struct dupla *elink, *dlink;
} no;

no *crialde(int n) {
    no *ini = NULL, *p, *aux = NULL;
    int valor;
    
    for (int i = 1; i <= n; i++) {
        printf("Digite o valor [%d/%d]: ", i, n);
        scanf("%d", &valor);
        
        p = (no*) malloc(sizeof(no));
        p->dado = valor;
        p->elink = NULL;
        p->dlink = ini;
        
        if (ini != NULL)
            ini->elink = p;
        else
            aux = p;
        ini = p;
    }
    return aux;
}

void escrevelista(no *p) {
    printf("\n=====================================\n");
    printf("   📋 Lista Duplamente Encadeada\n");
    printf(" ➝ Impressão dos valores ao quadrado\n");
    printf("=====================================\n");
    printf("Elementos ➝ ");
    while (p != NULL) {
        printf("%d ", p->dado * p->dado);
        p = p->elink;
    }
    printf("\n=====================================\n");
}

int main() {
    no *primeira;
    int n;
    
    printf("=============================================\n");
    printf("  🚀 Criando uma Lista Duplamente Encadeada\n");
    printf("==============================================\n");
    
    do {
        printf("Entre com o número de nós (maior ou igual a zero): ");
        scanf("%d", &n);
    } while (n < 0);
    
    primeira = crialde(n);
    
    if (primeira != NULL) {
        printf("\n✅ Lista Criada com sucesso!\n");
        escrevelista(primeira);
    } else {
        printf("\n⚠️ Lista Vazia\n");
    }
    
    printf("\n✅ Fim da execução!\n");
    return 0;
}
