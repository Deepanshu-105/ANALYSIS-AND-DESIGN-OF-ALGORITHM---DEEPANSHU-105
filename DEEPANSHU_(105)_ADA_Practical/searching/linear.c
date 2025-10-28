/*Write a C program to implement linear search algorithm.
 Repeat the experiment for different values of n where n is the number of elements in the list to be searched and
 plot a graph of the time taken versus n. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearsearch(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

void random_array(int *arr,int n){
    for(int i=0;i<n;i++){
        arr[i]=rand()%100;
    }

}
int main()
{
    int n, key, pos;
    printf("Enter the number of elements you want in an array: ");
    scanf("%d", &n);
    if(n<10){
        return -1;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    if(arr==NULL){
        printf("Memory is not allocated to array: ");
        return -1;
    }
     random_array(arr,n);
    printf("Enter the element you want to search: ");
    scanf("%d", &key);

    clock_t start = clock();

    for(int i=0;i<10000;i++){
         pos = linearsearch(arr, n, key);
    }
  
    clock_t end = clock();

    if (pos != -1)
    {
        printf("Element is found at %d th index\n", pos);
    }
    else
    {
        printf("Element not found.\n");
    }
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC/1000.0;


    printf("TIME TAKEN IS : %f", time_taken);
    free(arr);

    return 0;
}