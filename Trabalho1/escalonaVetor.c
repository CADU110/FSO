#include <stdio.h>
#include <stdlib.h>

typedef struct Processo
{
    int id;
    int tempoTotal;
} Processo;

typedef struct Fila
{
    Processo *itens;
    int frente, fundo;
    int capacidade;
} Fila;

Fila *criarFila(unsigned capacidade)
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->capacidade = capacidade;
    fila->frente = fila->fundo = 0;
    fila->itens = (Processo *)malloc(fila->capacidade * sizeof(Processo));
    return fila;
}

int filaCheia(Fila *fila)
{
    return (fila->fundo == fila->capacidade);
}

void enfileirar(Fila *fila, Processo item)
{
    if (filaCheia(fila))
        return;
    fila->itens[fila->fundo] = item;
    fila->fundo = (fila->fundo + 1) % fila->capacidade;
}

int main()
{
    int qtdeProcessos, quantum;
    scanf("%d %d", &qtdeProcessos, &quantum);
    Processo processos;
    Fila *fila = criarFila(qtdeProcessos);

    for (int i = 0; i < qtdeProcessos; i++)
    {
        int id, tempoTotal;
        scanf("%d %d", &id, &tempoTotal);
        processos.id = id;
        processos.tempoTotal = tempoTotal * 1000;
        enfileirar(fila, processos);
    }

    int tempoAtual = 0;
    int j = fila->frente;
    while (fila->capacidade > 0)
    {

        if (fila->itens[j].tempoTotal > quantum)
        {
            tempoAtual += quantum;
            fila->itens[j].tempoTotal -= quantum;
            if (j == fila->capacidade - 1)
            {
                j = 0;
            }
            else
            {
                j++;
            }
        }
        else
        {
            tempoAtual += fila->itens[j].tempoTotal;
            printf("%d (%d)\n", fila->itens[j].id, tempoAtual);
            for (int i = j; i < fila->capacidade-1; i++)
            {
                fila->itens[i] = fila->itens[i + 1];
            }
            if(j == fila->capacidade-1)j = 0;
            fila->capacidade--;
        }
    }

    free(fila->itens);
    free(fila);
    return 0;
}
