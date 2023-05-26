#include<stdio.h>

struct Process {
    int burstTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
};

void calculateWaitingTime(struct Process processes[], int n) {
    int totalWaitingTime = 0;
    int i;

    processes[0].waitingTime = 0;

    for (i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i-1].burstTime + processes[i-1].waitingTime;
        totalWaitingTime += processes[i].waitingTime;
    }

    float averageWaitingTime = (float)totalWaitingTime / n;
    printf("Average Waiting Time: %.2f\n", averageWaitingTime);
}

void calculateTurnaroundTime(struct Process processes[], int n) {
    int totalTurnaroundTime = 0;
    int i;

    for (i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    float averageTurnaroundTime = (float)totalTurnaroundTime / n;
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);
}

void priorityScheduling(struct Process processes[], int n) {
    int i, j;
    struct Process temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (processes[i].priority > processes[j].priority) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    calculateWaitingTime(processes, n);
    calculateTurnaroundTime(processes, n);
}

int main() {
    struct Process processes[3] = {
        {30, 2, 0, 0},
        {5, 1, 0, 0},
        {12, 3, 0, 0}
    };

    int n = sizeof(processes) / sizeof(processes[0]);

    priorityScheduling(processes, n);

    return 0;
}
