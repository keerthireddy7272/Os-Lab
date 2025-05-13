//6. Write a program in C to delete an element at a desired position from an array.

#include <stdio.h>
#define SIZE 10

void delete(int arr[SIZE],int n,int pos){
for(int i=pos; i<n-1;i++) {
arr[i]=arr[i + 1];
}
n--;
}
void main(){
int arr[10], n, pos;
printf("Enter the number of elements: ");
scanf("%d", &n);
for (int i = 0; i < n; i++) {
printf("Enter the %d element: ", i + 1);
scanf("%d", &arr[i]);
}
printf("Enter the position: ");
scanf("%d",&pos);
delete(arr,n,pos);
printf("The array after deletion is: ");
for(int i=0;i<n;i++){
printf("%d ",arr[i]);
}
}

