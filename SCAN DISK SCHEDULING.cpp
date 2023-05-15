#include <stdio.h>
#include <stdlib.h>

// Function to sort the array in ascending order
void sort(int *arr, int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to calculate the average head movement using SCAN algorithm
int calculateHeadMovement(int *arr, int size, int headPosition, int direction) {
    int totalHeadMovement = 0;
    int i, j, index;

    // Sort the array in ascending order
    sort(arr, size);

    // Find the index where the head position is greater than the track position
    for (i = 0; i < size; i++) {
        if (headPosition < arr[i]) {
            index = i;
            break;
        }
    }

    // Calculate head movement while scanning towards the end
    for (i = index; i < size; i++) {
        totalHeadMovement += abs(headPosition - arr[i]);
        headPosition = arr[i];
    }

    // Calculate head movement while scanning towards the beginning
    if (direction == -1) {
        totalHeadMovement += abs(headPosition - 0);
        headPosition = 0;

        for (i = index - 1; i >= 0; i--) {
            totalHeadMovement += abs(headPosition - arr[i]);
            headPosition = arr[i];
        }
    }

    return totalHeadMovement;
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int numOfTracks = sizeof(tracks) / sizeof(tracks[0]);
    int headPosition;
    int direction;
    int averageHeadMovement;

    printf("Enter the head position: ");
    scanf("%d", &headPosition);

    printf("Enter the direction (1 for right, -1 for left): ");
    scanf("%d", &direction);

    averageHeadMovement = calculateHeadMovement(tracks, numOfTracks, headPosition, direction) / numOfTracks;

    printf("Average head movement: %d\n", averageHeadMovement);

    return 0;
}
