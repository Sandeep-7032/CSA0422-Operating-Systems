#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void print_odds() {
    pid_t pid = getpid();
    printf("Process %d: ", pid);
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void print_evens() {
    pid_t pid = getpid();
    printf("Process %d: ", pid);
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void print_multiples_of_3() {
    pid_t pid = getpid();
    printf("Process %d: ", pid);
    for (int i = 1; i <= 10; i++) {
        if (i % 3 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void print_multiples_of_5() {
    pid_t pid = getpid();
    printf("Process %d: ", pid);
    for (int i = 1; i <= 10; i++) {
        if (i % 5 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    pid_t pid1, pid2, pid3, pid4;

    // create first child process
    pid1 = fork();
    if (pid1 == 0) {
        print_odds();
        return 0;
    }

    // create second child process
    pid2 = fork();
    if (pid2 == 0) {
        print_evens();
        return 0;
    }

    // create third child process
    pid3 = fork();
    if (pid3 == 0) {
        print_multiples_of_3();
        return 0;
    }

    // create fourth child process
    pid4 = fork();
    if (pid4 == 0) {
        print_multiples_of_5();
        return 0;
    }

    // wait for all child processes to complete
    int status;
    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);
    waitpid(pid3, &status, 0);
    waitpid(pid4, &status, 0);

    return 0;
}
