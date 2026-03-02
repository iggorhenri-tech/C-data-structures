#include <stdio.h>
#include <stdlib.h>

typedef struct dupla {
    int dado;
    struct dupla *elink, *dlink;
} no;

no *crialde(int n) {
    no *ini = NULL, *p;
    int valor;
    
    for (int i = 1; i <= n; i++) {
        printf("\nDigite o valor %d da pilha: ", i);
        scanf("%d", &valor);
        
        p = (no*) malloc(sizeof(no));
        p->dado = valor;
        
        p->elink = ini;
        p->dlink = NULL;
        
        if (ini != NULL)
            ini->dlink = p;
            
        ini = p;
    }
    return ini;
}

void escrevelista(no *p) {
    printf("\nPilha: ");
    while (p != NULL) {
        printf("%d\t", p->dado);
        p = p->elink;
    }
}

int main() {
    no *primeira;
    int n;

    printf("========================================\n");
    printf(" Criando uma pilha duplamente encadeada\n");
    printf("========================================\n");    

    do {
        printf("\nEntre com o número de nós: ");
        scanf("%d", &n);
    } while (n < 0);
    
    primeira = crialde(n);
    
    if (primeira != NULL) {
        printf("========================================\n");
        printf("              Pilha Criada\n");
        printf("========================================\n");   
        escrevelista(primeira);
    } else {
        printf("\nPilha Vazia");
    }
    
    return 0;
}
