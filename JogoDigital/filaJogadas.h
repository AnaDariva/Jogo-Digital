#ifndef FILA_JOGADAS_H_INCLUDED
#define FILA_JOGADAS_H_INCLUDED

typedef struct fila Fila;

Fila * criaFila();
int obtemTamanhoFila(Fila *f);
void enfileira(Fila *f, int jogadaUsuario, int jogadaComputador, int resultado);
void desenfileira(Fila *f);
void imprimeFila(Fila *f);
void liberaFila(Fila *f);

#endif



