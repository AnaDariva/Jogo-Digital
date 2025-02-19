#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "filaJogadas.h"

int main()
{
    Fila *fila;
    int escolhaUsuario, escolhaComputador, resultado;
    int capacidadeHistorico = 6;

    srand(time(NULL));
    fila = criaFila();

    while (1)
    {
        exibirMenu();
        scanf("%d", &escolhaUsuario);

        if (escolhaUsuario == 0)
        {
            printf("\n-----------------------------\n");
            printf("|    Saindo do jogo...       |\n");
            printf("|    Ate a proxima!          |\n");
            printf("-----------------------------\n");
            break;
        }

        if (escolhaUsuario == 4)
        {
            exibirRegras();
            continue;
        }

        if (escolhaUsuario < 1 || escolhaUsuario > 3)
        {
            printf("\n-----------------------------\n");
            printf("|  Opcao invalida! Tente     |\n");
            printf("|  novamente.                |\n");
            printf("-----------------------------\n");
            continue;
        }

        escolhaComputador = (rand() % 3) + 1;

        printf("\nVoce escolheu: \n");
        desenhaEscolha(escolhaUsuario);

        printf("\nComputador escolheu: \n");
        desenhaEscolha(escolhaComputador);

        resultado = determinaResultado(escolhaUsuario, escolhaComputador);
        exibeResultado(escolhaUsuario, escolhaComputador);

        enfileira(fila, escolhaUsuario, escolhaComputador, resultado);

        if (obtemTamanhoFila(fila) > capacidadeHistorico)
        {
            desenfileira(fila);
        }

        printf("\nHistorico das ultimas jogadas:\n");
        imprimeFila(fila);
    }

    liberaFila(fila);
    return 0;
}

void exibirRegras()
{
    printf("\n-------------------------------------------------------------------------------------------\n");
    printf("| !Regras e funcionamento do jogo!                                                        |\n");
    printf("------------------------------------------------------------------------------------------|\n");
    printf("1. O jogo e entre o jogador (voce) e o computador.                                        |\n");
    printf("2. As opcoes de escolha sao:                                                              |\n");
    printf("   - 1: Pedra                                                                             |\n");
    printf("   - 2: Papel                                                                             |\n");
    printf("   - 3: Tesoura                                                                           |\n");
    printf("3. As regras de confronto sao as seguintes:                                               |\n");
    printf("   - Pedra ganha de Tesoura                                                               |\n");
    printf("   - Tesoura ganha de Papel                                                               |\n");
    printf("   - Papel ganha de Pedra                                                                 |\n");
    printf("4. Se ambos escolherem a mesma opcao, e considerado um empate.                            |\n");
    printf("5. O objetivo do jogo e vencer o computador o maior numero de vezes possivel.             |\n");
    printf("6. O jogador pode escolher jogar quantas vezes quiser. Para sair, escolha a opcao '0'.    |\n");
    printf("\nBoa sorte!                                                                               |\n");
    printf("--------------------------------------------------------------------------------------------\n");
}

void exibeResultado(int escolhaUsuario, int escolhaComputador)
{
    if (escolhaUsuario == escolhaComputador)
    {
        printf("\n-----------------------------\n");
        printf("|         Empate!            |\n");
        printf("-----------------------------\n");
    }
    else if ((escolhaUsuario == 1 && escolhaComputador == 3) ||
             (escolhaUsuario == 2 && escolhaComputador == 1) ||
             (escolhaUsuario == 3 && escolhaComputador == 2))
    {
        printf("\n----------------------------\n");
        printf("|       <3 Voce venceu!      |\n");
        printf("-----------------------------\n");
    }
    else
    {
        printf("\n-----------------------------\n");
        printf("|      </3 Voce perdeu!      |\n");
        printf("-----------------------------\n");
    }
}

int determinaResultado(int escolhaUsuario, int escolhaComputador)
{
    if (escolhaUsuario == escolhaComputador)
    {
        return 0;
    }
    else if ((escolhaUsuario == 1 && escolhaComputador == 3) ||
             (escolhaUsuario == 2 && escolhaComputador == 1) ||
             (escolhaUsuario == 3 && escolhaComputador == 2))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void exibirMenu()
{
    printf("\n");
    printf(" -------------------------------\n");
    printf("|   PEDRA, PAPEL E TESOURA      |\n");
    printf("|-------------------------------|\n");
    printf("|   1. Pedra                    |\n");
    printf("|   2. Papel                    |\n");
    printf("|   3. Tesoura                  |\n");
    printf("|   4. Regras e funcionamento   |\n");
    printf("|   0. Sair                     |\n");
    printf(" -------------------------------\n");
    printf(" Escolha uma opcao: ");
}

void desenhaEscolha(int escolha)
{
    if (escolha == 1)
    {
        printf("   _______  \n");
        printf(" /       \\ \n");
        printf(" |        | \n");
        printf(" \\_______/ \n");
        printf("   PEDRA   \n");
    }
    else if (escolha == 2)
    {
        printf("  _________ \n");
        printf(" |         |\n");
        printf(" |         |\n");
        printf(" |_________|\n");
        printf("   PAPEL    \n");
    }
 else if (escolha == 3)
    {
        printf("   \\   /   \n");
        printf("    \\ /    \n");
        printf("     -     \n");
        printf("    / \\   \n");
        printf("   O   O  \n");
        printf("  TESOURA  \n");
    }
}
