//3. Write a program in C to find the sum of rows and columns of a matrix.

#include <stdio.h>
#define SIZE 5

void main() {
int arr[SIZE][SIZE], rowSum[SIZE] = {0}, colSum[SIZE] = {0}, n;
printf("Enter the number of rows or columns (max %d): ", SIZE);
scanf("%d", &n);
printf("Enter the elements of the matrix:\n");
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
scanf("%d", &arr[i][j]);
rowSum[i] += arr[i][j];
colSum[j] += arr[i][j];
}
}
printf("\nRow sums:\n");
for (int i = 0; i < n; i++) {
printf("Sum of row %d: %d\n", i + 1, rowSum[i]);
}
printf("\nColumn sums:\n");
for (int j = 0; j < n; j++) {
printf("Sum of column %d: %d\n", j + 1, colSum[j]);
}
}
