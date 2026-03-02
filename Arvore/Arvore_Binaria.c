#include <stdio.h>
#include <stdlib.h>

typedef struct arvoreBinaria {
    int elem;
    struct arvoreBinaria *dir, *esq;
} arvoreBinaria;

arvoreBinaria* insere(arvoreBinaria *a, int el);
arvoreBinaria* remover(arvoreBinaria *a, int el);

void preOrdem(arvoreBinaria *a);
void emOrdem(arvoreBinaria *a);
void posOrdem(arvoreBinaria *a);

int main() {
    arvoreBinaria *raiz = NULL;
    int x; 
    char op;
    
    printf("=====================================\n");
    printf("   🌳 Árvore Binária de Busca (ABB)\n");
    printf("=====================================\n");
    
    do {
        printf("\n📌 MENU DE OPÇÕES\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Percurso Pré-Ordem\n");
        printf("4 - Percurso Em-Ordem\n");
        printf("5 - Percurso Pós-Ordem\n");
        printf("6 - Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &op);
        
        switch(op) {
            case '1':
                printf("\nDigite o valor a inserir: ");
                scanf("%d", &x);
                raiz = insere(raiz, x);
                break;
            case '2':
                if (raiz != NULL) {
                    printf("\nDigite o valor a remover: ");
                    scanf("%d", &x);
                    raiz = remover(raiz, x);
                } else {
                    printf("\n⚠️ Árvore vazia.\n");
                }
                break;
            case '3':
                printf("\n📖 Percurso Pré-Ordem: ");
                preOrdem(raiz);
                printf("\n");
                break;
            case '4':
                printf("\n📖 Percurso Em-Ordem: ");
                emOrdem(raiz);
                printf("\n");
                break;
            case '5':
                printf("\n📖 Percurso Pós-Ordem: ");
                posOrdem(raiz);
                printf("\n");
                break;
        }
    } while (op != '6');
    
    printf("\n✅ Fim da execução!\n");
    return 0;
}

arvoreBinaria* insere(arvoreBinaria *a, int el) {
    if (a == NULL) {
        a = (arvoreBinaria*) malloc(sizeof(arvoreBinaria));
        a->elem = el;
        a->esq = a->dir = NULL;
        printf("\n✔️ Elemento %d inserido.\n", el);
    } else if (el <= a->elem) {
        a->esq = insere(a->esq, el);
    } else {
        a->dir = insere(a->dir, el);
    }
    return a;
}

arvoreBinaria *remover(arvoreBinaria *a, int el) {
    if (a == NULL) {
        printf("\n⚠️ Elemento não encontrado.\n");
        return NULL;
    }
    if (el < a->elem) {
        a->esq = remover(a->esq, el);
    } else if (el > a->elem) {
        a->dir = remover(a->dir, el);
    } else {
        if (a->esq == NULL && a->dir == NULL) {
            free(a);
            return NULL;
        } else if (a->esq == NULL) {
            arvoreBinaria *temp = a->dir;
            free(a);
            return temp;
        } else if (a->dir == NULL) {
            arvoreBinaria *temp = a->esq;
            free(a);
            return temp;
        } else {
            arvoreBinaria *aux = a->dir;
            while(aux->esq != NULL)
                aux = aux->esq;
            a->elem = aux->elem;
            a->dir = remover(a->dir, aux->elem);
        }
    }
    return a;
}

void preOrdem(arvoreBinaria *a) {
    if (a != NULL) {
        printf("%d ", a->elem);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}

void emOrdem(arvoreBinaria *a) {
    if (a != NULL) {
        emOrdem(a->esq);
        printf("%d ", a->elem);
        emOrdem(a->dir);
    }
}

void posOrdem(arvoreBinaria *a) {
    if (a != NULL) {
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%d ", a->elem);
    }
}
