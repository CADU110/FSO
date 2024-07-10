#include <stdio.h>
#include <stdlib.h>

typedef struct pr {
    int id;
    int ins;
    int temp;
} pr;

int compare(const void *a, const void *b) {
    pr *prA = (pr *)a;
    pr *prB = (pr *)b;
    return (prA->temp - prB->temp);
}

int main() {
    int qtd;
    scanf("%d", &qtd);
      int **fila = (int **)malloc(sizeof(int *) * qtd); 
    pr *proces = (pr *)malloc(sizeof(pr) * qtd); 


    int op = 0;

    for (int i = 0; i < qtd; i++) {
        proces[i].id=i;
        int it;
        scanf("%d", &it);
        proces[i].ins = it;
        op += it;

        proces[i].temp = 0;
        fila[i] = (int*)malloc(sizeof(int) * it);
    }


    for (int i = 0; i < qtd; i++) {
        int q = proces[i].ins;
        for (int j = 0; j < q; j++) {
            int b;
            scanf("%d", &b);
            fila[i][j] = b;
        }
    }

    int x = 0;
    int t = 0;
    while (x < op) {
       
        for (int i = 0; i < qtd; i++) {
            int q = proces[i].ins;
            for (int j = 0; j < q; j++) {
                if (fila[i][j] == 1) {
                    fila[i][j] = 0;
                    break;
                } else if (fila[i][j] == 0) {
                    t +=10;
                    proces[i].temp = t; 
                    x++;
                    fila[i][j] = -1;
                }
            }
        }
    }

    qsort(proces, qtd, sizeof(pr), compare);

    for (int i = 0; i < qtd; i++) {
        printf("%d (%d)\n", proces[i].id+1, proces[i].temp);
    }


    return 0;
}
