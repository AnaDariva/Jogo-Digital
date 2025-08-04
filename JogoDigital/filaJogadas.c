#include <stdio.h>
#include <stdlib.h>
#include "filaJogadas.h"

struct jogada
{
    int jogadaUsuario;
    int jogadaComputador;
    int resultado;
};

struct celula
{
    struct jogada jogada;
    struct celula *prox;
};

struct fila
{
    struct celula *inicio;
    struct celula *fim;
    int tamanho;
};

Fila * criaFila()
{
    Fila *f = malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
    return f;
}

int obtemTamanhoFila(Fila *f)
{
    return f->tamanho;
}

void enfileira(Fila *f, int jogadaUsuario, int jogadaComputador, int resultado)
{
    struct jogada novaJogada;
    novaJogada.jogadaUsuario = jogadaUsuario;
    novaJogada.jogadaComputador = jogadaComputador;
    novaJogada.resultado = resultado;

    struct celula *nova = malloc(sizeof(struct celula));
    nova->jogada = novaJogada;
    nova->prox = NULL;

    if (f->fim == NULL)
    {
        f->inicio = nova;
    }
    else
    {
        f->fim->prox = nova;
    }
    f->fim = nova;
    f->tamanho++;
}

void desenfileira(Fila *f)
{
    if (f->inicio == NULL) return;

    struct celula *remover = f->inicio;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }

    free(remover);
    f->tamanho--;
}

void imprimeFila(Fila *f)
{
    struct celula *aux = f->inicio;
    int i = 1;
    while (aux != NULL)
    {
        printf("Jogo %d:\n", i);
        printf("  Usuario: %d | Computador: %d | Resultado: ", aux->jogada.jogadaUsuario, aux->jogada.jogadaComputador);
        if (aux->jogada.resultado == 0)
        {
            printf("Empate\n");
        }
        else if (aux->jogada.resultado == 1)
        {
            printf("Vitoria\n");
        }
        else
        {
            printf("Derrota\n");
        }
        aux = aux->prox;
        i++;
    }
}

void liberaFila(Fila *f)
{
    struct celula *aux = f->inicio;
    while (aux != NULL)
    {
        struct celula *liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(f);
}



