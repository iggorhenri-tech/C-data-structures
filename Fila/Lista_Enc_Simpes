#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int dado;
    struct lista *link;
} no;

no *crialista(int n) {
    no *ini, *p, *ult;
    int valor;
    ini = ult = NULL;
    
    for (int i = 0; i < n; i++) {
        printf("Digite o valor [%d/%d]: ", i + 1, n);
        scanf("%d", &valor);
        p = (no*) malloc(sizeof(no));
        p->dado = valor;
        p->link = NULL;
        if (ult != NULL)
            ult->link = p;
        else
            ini = p;
        ult = p;
    }
    return ini;
}

void escrevelista(no *p) {
    printf("\n=====================================\n");
    printf("     📋 Lista Encadeada Criada\n");
    printf("=====================================\n");
    printf("Elementos ➝ ");
    while (p != NULL) {
        printf("%d ", p->dado);
        p = p->link;
    }
    printf("\n=====================================\n");
}

int main() {
    no *primeira;
    int n;
    
    printf("=====================================\n");
    printf("   🚀 Criando uma Lista Encadeada\n");
    printf("=====================================\n");
    
    do {
        printf("Entre com o número de nós (maior que zero): ");
        scanf("%d", &n);
    } while (n <= 0);

    primeira = crialista(n);
    if (primeira != NULL) {
        escrevelista(primeira);
    } else {
        printf("\n⚠️ Lista Vazia\n");
    }
    
    printf("\n✅ Fim da execução!\n");
    return 0;
}
