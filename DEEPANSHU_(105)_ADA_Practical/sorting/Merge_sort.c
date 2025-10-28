#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void merge(int arr[],int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int *l = (int*)malloc(n1*sizeof(int));
    int* r= (int*)malloc(n2*sizeof(int));
    if(l==NULL){
        printf("Memory is not allocated");
     
    }
    if(r==NULL){
        printf("Memory is not allocated");
    
    }
    for(int i=0;i<n1;i++){
        l[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++){
        r[j]=arr[mid+j+1];
    }

    int i=0,j=0,k=left;
    while(i<n1&& j<n2){
        if(l[i]<=r[j]){
            arr[k]=l[i];
            i++;
        }
        else{
            arr[k]=r[j];
            j++;
        }
        k++;
    }

while(i<n1){
    arr[k]=l[i];
    k++;
    i++;
}
while(j<n2){
    arr[k]=r[j];
    k++;
    j++;
}

free(r);
free(l);

}




void Merge_sort(int* arr,int left,int right){
    if(left<right){
        int mid = left +(right-left)/2;
        Merge_sort(arr,left,mid);
        Merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
    
}

void generate_RandomArray(int* arr,int n){
    for(int i=0;i<n;i++){
        arr[i]=rand()%100;
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
  /* printf("ARRAY BEFORE THE SORTING:");
    Print_Array(arr,n);
*/
    clock_t start =clock();
    for(int i=0;i<1000;i++){
        Merge_sort(arr,0,n);
    }
    clock_t end =clock();

   /*printf("\n\n \n\n ARRAY AFTER SORTING :");
    Print_Array(arr,n);*/
double time_taken =((double)(end-start))/CLOCKS_PER_SEC/1000.0;
printf("\nTIME TAKEN TO SORT THE ARRAY IS : %f",time_taken);

return 0;

}