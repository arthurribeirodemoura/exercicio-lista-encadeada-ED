#include<stdio.h>
#include<stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} TLista;

TLista* push(TLista* topo, int valor) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    
    novo->info = valor;
    novo->prox = topo;
    
    return novo;
}

TLista* pop(TLista* topo, int* valor_removido) {

    if (topo == NULL) {
        printf("Erro: A pilha esta vazia!\n");
        return NULL;
    }

    TLista* p = topo;

    if (valor_removido != NULL) {
        *valor_removido = p->info;
    }

    topo = p->prox;

    free(p);
    
    return topo;
}

void imprime_pilha(TLista *topo) {
    TLista* p;
    printf("Pilha (Topo -> Base): ");
    for (p = topo; p != NULL; p = p->prox) {
        printf("%d ", p->info);
    }
    printf("\n");
}

int main(void) {
    TLista* pilha = NULL;
    int valor_recuperado;

    printf("--- Testando o PUSH ---\n");
    pilha = push(pilha, 10);
    pilha = push(pilha, 20);
    pilha = push(pilha, 30);
    imprime_pilha(pilha);

    printf("\n--- Testando o POP ---\n");
    pilha = pop(pilha, &valor_recuperado);
    printf("Valor removido: %d\n", valor_recuperado);
    imprime_pilha(pilha);
    
    pilha = pop(pilha, &valor_recuperado);
    printf("Valor removido: %d\n", valor_recuperado);
    imprime_pilha(pilha);

    return 0;
}
