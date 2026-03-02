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

void ordenalista(no *inicio) {
    no *i, *j;
    int temp;
    if (inicio == NULL) return;
    for (i = inicio; i->elink != NULL; i = i->elink) {
        for (j = i->elink; j != NULL; j = j->elink) {
            if (i->dado > j->dado) {
                temp = i->dado;
                i->dado = j->dado;
                j->dado = temp;
            }
        }
    }
}

void escrevelista(no *p) {
    while (p != NULL) {
        printf("%d ", p->dado);
        p = p->elink;
    }
    printf("\n");
}

int main() {
    no *primeira;
    int n;
    
    printf("=====================================\n");
    printf("   🚀 Lista Duplamente Encadeada\n");
    printf("   ➝ Impressão em ordem crescente\n");
    printf("=====================================\n");
    
    do {
        printf("Entre com o número de nós (maior ou igual a zero): ");
        scanf("%d", &n);
    } while (n < 0);
    
    primeira = crialde(n);
    
    if (primeira != NULL) {
        printf("\n📋 Lista Original:\n");
        escrevelista(primeira);
        
        ordenalista(primeira);
        
        printf("\n✅ Lista Ordenada em ordem crescente:\n");
        escrevelista(primeira);
    } else {
        printf("\n⚠️ Lista Vazia\n");
    }
    
    printf("\nFim da execução!\n");
    return 0;
}
