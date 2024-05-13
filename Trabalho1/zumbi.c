#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

pid_t zombie_pid;
int signal_count = 0;

void sig_handler(int sig) {
    if (zombie_pid == 0) {
        zombie_pid = fork();
        if (zombie_pid == 0) {
            exit(0); 
        }
    } else {
        waitpid(zombie_pid, NULL, 0);
        zombie_pid = 0;
    }

    signal_count++;

    if (signal_count >= 3) {
        exit(0);
    }
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sig_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    zombie_pid = 0;

    while (1) {
        sleep(1); 
    }

    return 0;
}
