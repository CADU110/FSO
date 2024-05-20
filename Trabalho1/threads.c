#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int count;

pthread_mutex_t mut;

struct thread_arg {
  int vezes;
};

int work(int id);

void *thread_func(void *arg){
   
  struct thread_arg *t_arg = (struct thread_arg *)arg;

  for(int i = 0; i < t_arg->vezes; i++){
    
    pthread_mutex_lock(&mut);
    int id = count;
    count++;
    pthread_mutex_unlock(&mut);
    work(id);
    
  }

  pthread_exit(NULL);

  return;

}
