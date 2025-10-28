#include<stdio.h>
#include<stdlib.h>
#include<time.h>



void swap(int *a,int *b){
    int t=*a;
    *a =*b;
    *b=t;
}


int partition(int *arr,int low, int high){
 int p =arr[high];
 int i= low-1;
 for(int j=low;j<high;j++){
    if(arr[j]<=p){
        i++;
        swap(&arr[i],&arr[j]);

    }
 }
 swap(&arr[i+1],&arr[high]);
 return i+1;
}


void quick_sort(int *arr,int low, int high){
    if(low<high){
        int pi =partition(arr,low,high);
        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);
    }
}


void Random_Generated_array(int *arr,int n){
    for(int i=0;i<n; i++){
        arr[i]=rand()%100;
    }
}
void print_array(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
     }
}

int main(){
    int n;
    printf("Enter the number of elements you want in an array: ");
    scanf(" %d",&n);

    if(n<10){
        return -2;
    }
     int *arr =(int* )malloc(sizeof(int)*n);
     if(arr==NULL){
        printf("Memory allocation is failed");
        return -1;
     }

     Random_Generated_array(arr,n);

   /*  printf(" Array before sorting:\n");
     print_array(arr,n);
*/
     clock_t start =clock();
     for(int i =0 ;i<1000;i++){
        quick_sort(arr,0,n-1);
     }
     clock_t end =clock();
  /*   printf("\n Array after sorting is:\n");
     print_array(arr,n);
*/
     double avg_time =((double)(end-start)) /CLOCKS_PER_SEC/1000.0;
     printf(" \nThe average time for sorting is: %f",avg_time);

         free(arr);
    return 0;
}