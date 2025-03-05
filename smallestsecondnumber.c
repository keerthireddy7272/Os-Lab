//1. Write a program in C to find the second-smallest element in an array.

#include <stdio.h>
void sorting(int arr[], int n){
for(int i=0;i<n-1;i++){
for(int j=i+1;j<n;j++){
if(arr[i]>arr[j]){
int temp= arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}
}
}
int main() {
int arr[10], n;
printf("Enter the number of elements: ");
scanf("%d", &n);
for (int i = 0; i < n; i++) {
printf("Enter the %d element: ", i + 1);
scanf("%d", &arr[i]);
}
sorting(arr, n);
if (n >= 2) {
printf("The second smallest number is: %d\n", arr[1]);
}else{
printf("Array must contain at least two elements to find the second smallest.\n");
}
return 0;
}
