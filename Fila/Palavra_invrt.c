#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dupla {
    char dado;
    struct dupla *elink, *dlink;
} no;

no *criaListaPalavra(char palavra[]) {
    no *ini = NULL, *p;
    int i = 0;
    while (palavra[i] != '\0') {
        p = (no*) malloc(sizeof(no));
        p->dado = palavra[i];
        p->elink = ini;
        p->dlink = NULL;
        if (ini != NULL)
            ini->dlink = p;
        ini = p;
        i++;
    }
    return ini;
}

void imprimeInversa(no *p) {
    printf("\n=====================================\n");
    printf("        🔄 Palavra invertida\n");
    printf("=====================================\n");
    printf("Resultado ➝ ");
    while (p != NULL) {
        printf("%c", p->dado);
        p = p->elink;
    }
    printf("\n=====================================\n");
}

int main() {
    char palavra[100];
    no *lista;
    
    printf("=====================================\n");
    printf("       📝 Inversor de Palavras\n");
    printf("=====================================\n");
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    
    lista = criaListaPalavra(palavra);
    
    if (lista != NULL)
        imprimeInversa(lista);
    else
        printf("\n⚠️ Lista Vazia\n");
    
    printf("\n✅ Fim da execução!\n");
    return 0;
}
