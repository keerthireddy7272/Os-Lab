#include <stdio.h>
#include <stdlib.h>

int main() {
    int total, hungry, i, j, ch;
    int h[10]; // stores hungry philosopher positions

    printf("Enter the total number of philosophers: ");
    scanf("%d", &total);

    printf("How many are hungry: ");
    scanf("%d", &hungry);

    for (i = 0; i < hungry; i++) {
        printf("Enter philosopher %d position (1 to %d): ", i + 1, total);
        scanf("%d", &h[i]);
    }

    do {
        printf("\n1. One can eat at a time\n2. Two can eat at a time\n3. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            for (i = 0; i < hungry; i++) {
                // All waiting before granting eat
                for (j = 0; j < hungry; j++)
                    printf("P %d is waiting\n", h[j]);

                printf("P %d is granted to eat\n", h[i]);
                printf("P %d has finished eating\n", h[i]);
            }
            break;

        case 2:
            for (i = 0; i < hungry; i += 2) {
                // All waiting before granting
                for (j = 0; j < hungry; j++)
                    printf("P %d is waiting\n", h[j]);

                if (i + 1 < hungry) {
                    // Check adjacency
                    int diff = abs(h[i] - h[i + 1]);
                    if (diff != 1 && diff != total - 1) {
                        // Not neighbors
                        printf("P %d is granted to eat\n", h[i]);
                        printf("P %d is granted to eat\n", h[i + 1]);
                        printf("P %d has finished eating\n", h[i]);
                        printf("P %d has finished eating\n", h[i + 1]);
                    } else {
                        // Neighbors - allow one at a time
                        printf("P %d is granted to eat\n", h[i]);
                        printf("P %d has finished eating\n", h[i]);
                        printf("P %d is granted to eat\n", h[i + 1]);
                        printf("P %d has finished eating\n", h[i + 1]);
                    }
                } else {
                    // Odd number of hungry philosophers
                    printf("P %d is granted to eat\n", h[i]);
                    printf("P %d has finished eating\n", h[i]);
                }
            }
            break;

        case 3:
            exit(0);
        }
    } while (ch != 3);

    return 0;
}


