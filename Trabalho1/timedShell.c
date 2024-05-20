#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>


int main() {
    char bin[255];
    char funcao[255];
    int status;
    double total_time = 0;
    while (scanf("%s %s", bin, funcao) != EOF) {
        fflush(stdout);
        struct timeval start, end;
        long seconds, microseconds = 0.0;
        int erro = 0;
        pid_t pid = fork();
        gettimeofday(&start, NULL);
        if (pid == 0) {
          execl(bin, bin, funcao, (char *) NULL);
          printf("> Erro: %s\n", strerror(errno));
          status = errno;
          fclose(stdin);
          exit(errno);
            
        } else if (pid > 0) {
          wait(&status);
          gettimeofday(&end, NULL);
          double exec_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.000000;
          printf("> Demorou %.1f segundos, retornou %d\n", exec_time, WEXITSTATUS(status));
          total_time += exec_time;
        } 
    }

    printf(">> O tempo total foi de %.1f segundos\n", total_time);

    return 0;
}
