#include <stdio.h>
#include <stdlib.h>

typedef struct head
{
    int qtd;
    struct P *primeiro;
    struct P *ultimo;
} head;

typedef struct P
{
    int id;
    int totalTime;
    struct P *next;
} P;

head *createHead()
{
    head *newHead = (head *)malloc(sizeof(head));
    newHead->qtd = 0;
    newHead->primeiro = NULL;
    newHead->ultimo = NULL;
    return newHead;
}

void insere(head *fila, int id, int totalTime)
{
    P *novo_processo = malloc(sizeof(P));
    novo_processo->id = id;
    novo_processo->totalTime = totalTime;
    novo_processo->next = NULL;
    if (fila->primeiro == NULL)
    {
        fila->primeiro = novo_processo;
        fila->ultimo = novo_processo;
    }
    else
    {
        fila->ultimo->next = novo_processo;
        fila->ultimo = novo_processo;
    }
    fila->qtd++;
}

void removeProcess(head *fila)
{
    if (fila->primeiro == NULL)
    {
        fila->ultimo = NULL;
        return;
    }
    P *aux = fila->primeiro;
    fila->primeiro = fila->primeiro->next;
    free(aux);
    fila->qtd--;
}

int main()
{
    int qtd;
    scanf("%d", &qtd);

    int gap;
    scanf("%d", &gap);

    head *fila = createHead();

    for (int i = 0; i < qtd; i++)
    {
        int id;
        int totalTime;
        scanf("%d %d", &id, &totalTime);
        insere(fila, id, (totalTime * 1000));
    }

    int nowTime = 0;

    while (fila->qtd > 0)
    {
        P *processoAtual = fila->primeiro;
        if (processoAtual->totalTime > gap) {
            nowTime += gap;
            processoAtual->totalTime -= gap;
            fila->ultimo->next = processoAtual;
            fila->ultimo = processoAtual;
            fila->primeiro = fila->primeiro->next;
        } else {
            nowTime += processoAtual->totalTime;
            printf("%d (%d)\n", processoAtual->id, nowTime);
            removeProcess(fila);
        }
    }

    return 0;
}