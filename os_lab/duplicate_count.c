//4. Write a program in C to count the total number of duplicate elements in an array.
#include <stdio.h>
#define SIZE 10

int find_dup(int arr[SIZE], int n) {
int count = 0;
for (int i = 0; i < n; i++) {
for (int j = i + 1; j < n; j++) {
if (arr[i] == arr[j]) {
count++;
break;
}
}
}
return count;
}
int main() {
int arr[SIZE], n;
printf("Enter the number of elements: ");
scanf("%d", &n);
for (int i = 0; i < n; i++) {
printf("Enter element %d: ", i + 1);
scanf("%d", &arr[i]);
}
int duplicates = find_dup(arr, n);
printf("The total number of duplicate elements is: %d\n", duplicates);
return 0;
}


