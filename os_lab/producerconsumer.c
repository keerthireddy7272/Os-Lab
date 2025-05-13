#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

int mutex = 1;
int empty = BUFFER_SIZE;
int full = 0;
int item = 1;

void wait(int *S) {
    (*S)--;
    if (*S < 0) {
        printf("Semaphore blocked. Waiting...\n");
    }
}

void signal(int *S) {
    (*S)++;
    if (*S <= 0) {
        printf("Semaphore unblocked. Proceeding...\n");
    }
}

void producer() {
    if (empty == 0) {
        printf("Buffer is FULL. Producer cannot add more items.\n");
        return;
    }
    wait(&empty);
    wait(&mutex);

    printf("Produced: Item %d\n", item++);

    signal(&mutex);
    signal(&full);
}

void consumer() {
    if (full == 0) {
        printf("Buffer is EMPTY. Consumer cannot consume more items.\n");
        return;
    }
    wait(&full);
    wait(&mutex);

    printf("Consumed: Item %d\n", --item);

    signal(&mutex);
    signal(&empty);
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Produce 2. Consume 3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    }
}


