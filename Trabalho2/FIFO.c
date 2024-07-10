#include <stdio.h>
#include <stdlib.h>


int main(){
  int ram, qtdP;
  scanf("%d %d",&ram,&qtdP);
  int inicio = 0;
  int *memo = malloc(sizeof(int)*ram);
  for(int j = 0; j < ram; j++) memo[j]=-1;
  int * esta = calloc(1000,sizeof(int));
  int fault = 0;
  for(int i = 0; i < qtdP; i++){
    int p;
    scanf("%d",&p);
    if(!esta[p]){
      fault++;
      if(inicio == ram){
        inicio = 0;
      }
      if(memo[inicio]!=-1){
        esta[memo[inicio]]=0;
      }
      memo[inicio++]=p;
      esta[p]=1;
    }

  }
  printf("%d\n",fault);
}
