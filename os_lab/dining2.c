#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX 10

int total_phil;
int hungry[MAX];
int hungry_count;
int choice;
bool spoon[MAX]; // spoon[i] is true if spoon is in use

bool can_eat(int id) {
    int left = id;
    int right = (id + 1) % total_phil;
    return !spoon[left] && !spoon[right];
}

void mark_spoons(int id, bool status) {
    int left = id;
    int right = (id + 1) % total_phil;
    spoon[left] = status;
    spoon[right] = status;
}

int main() {
    printf("Enter the total number of philosophers: ");
    scanf("%d", &total_phil);

    printf("How many are hungry: ");
    scanf("%d", &hungry_count);

    for (int i = 0; i < hungry_count; i++) {
        printf("Enter philosopher %d position (1 to %d): ", i + 1, total_phil);
        scanf("%d", &hungry[i]);
        hungry[i]--; // 0-based indexing
    }

    printf("\n1. One can eat at a time\n2. Two can eat at a time\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int max_eat = (choice == 1) ? 1 : (choice == 2 ? 2 : 0);
    if (max_eat == 0) return 0;

    // Initially all are waiting
    printf("\n");
    for (int i = 0; i < hungry_count; i++) {
        printf("P %d is waiting\n", hungry[i] + 1);
    }

    bool done[MAX] = {false};
    int done_count = 0;

    while (done_count < hungry_count) {
        int eating_now = 0;
        for (int i = 0; i < hungry_count && eating_now < max_eat; i++) {
            int id = hungry[i];
            if (!done[i] && can_eat(id)) {
                mark_spoons(id, true);
                printf("P %d is granted to eat\n", id + 1);
                eating_now++;
                done[i] = true;
                done_count++;
            }
        }
        sleep(2);
        for (int i = 0; i < hungry_count; i++) {
            if (done[i]) {
                int id = hungry[i];
                if (spoon[id]) {
                    printf("P %d has finished eating\n", id + 1);
                    mark_spoons(id, false);
                }
            }
        }
    }
    return 0;
}
