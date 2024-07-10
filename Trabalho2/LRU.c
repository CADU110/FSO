#include <stdio.h>
#include <stdlib.h>

typedef struct page {
    int pg;  
    int ref; 
} page;

int main() {
    int ram, qtdP;
    scanf("%d %d", &ram, &qtdP);
    int inicio = 0;
    page *memo = malloc(sizeof(page) * ram);

    int fault = 0;
    for (int i = 0; i < qtdP; i++) {
        int p;
        scanf("%d", &p);

        int esta = 0;
        for (int j = 0; j < ram; j++) {
            if (memo[j].pg == p) {
                memo[j].ref = i; 
                esta = 1;
                break;
            }
        }

        if (!esta) {
            fault++;
            if (inicio < ram) {
                memo[inicio].pg = p;
                memo[inicio].ref = i;
                inicio++;
            } else {
                int menos = 0;
                for (int j = 1; j < ram; j++) {
                    if (memo[j].ref < memo[menos].ref) {
                        menos = j;
                    }
                }
                memo[menos].pg = p;
                memo[menos].ref = i;
            }
        }
    }

    printf("%d\n", fault);

    return 0;
}
