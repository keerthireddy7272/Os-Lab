//2. Write a program in C to find the sum of the left diagonals of a matrix.

#include <stdio.h>
#define size 5

void main(){
int arr[size][size],n,sum;
printf("Enter the number of rows or columms: ");
scanf("%d",&n);
printf("Enter the elements \n");
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
scanf("%d", &arr[i][j]);
}
}
for(int i=0;i<n;i++){
sum+=arr[i][i];
}
printf("The sum of diagonal elements : %d", sum);
return 0;
}
