#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Insertion_sort(int* arr,int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
           arr[j+1]=arr[j];
           j--;
            }
            arr[j+1]=key;
        }
    }


void generate_RandomArray(int* arr,int n){
    for(int i=0;i<n;i++){
        arr[i]=rand()%1000;
    }
}

void Print_Array(int* arr,int n){
for(int i=0;i<n;i++){
    printf("  %d",arr[i]);
}
}

int main(){
    int n;
    printf(" ENTER THE NUMBER OF ELEMENTS YOU WANT IN AN ARRAY: ");
    scanf("%d",&n);
    if(n<10){
         printf("ENTER VALUE GREATER THAN 10");
        return -1;
    }
    int *arr= (int*)malloc(sizeof(int)*n);
    if(arr==NULL){
        printf("NO SPACE IS ALLOCATED.");
        return -2;
    }
    generate_RandomArray(arr,n);
/*  printf("ARRAY BEFORE THE SORTING:");
    Print_Array(arr,n);
*/
    clock_t start =clock();
    for(int i=0;i<1000;i++){
        Insertion_sort(arr,n);
    }
    clock_t end =clock();
/*
    printf("\n\n \n\n ARRAY AFTER SORTING :");
 Print_Array(arr,n);
 */
double time_taken =((double)(end-start))/CLOCKS_PER_SEC/1000.0;
printf("\nTIME TAKEN TO SORT THE ARRAY IS : %f",time_taken);
free(arr);
return 0;

}