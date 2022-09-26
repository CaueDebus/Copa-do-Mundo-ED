#include <stdlib.h>

typedef struct nodo {
    int info;
    nodo *inicio;
    nodo *fim;
} Fila;

Fila *cria_fila() 
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
}

int vazia(Fila *f)
{
    return f->inicio == NULL ? 1 : 0;
}

void push(Fila *f, int x) 
{
    nodo *novo = (nodo *)malloc(sizeof(nodo));
    novo->info = x;
    novo->prox = NULL;
    if (f->fim != NULL)
        f->fim->prox = novo;
    f->fim = novo;
    if (f->inicio == NULL)
        f->inicio = novo;
}

int pop(Fila *f) 
{ 
    int x = f->inicio->info;
    nodo *aux = f->inicio->prox;
    if (f->fim == f->inicio)
        f->fim = NULL;
    free(f->inicio);
    f->inicio = aux;
    return x;
}