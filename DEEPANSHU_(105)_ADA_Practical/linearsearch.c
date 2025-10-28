#include<stdio.h>
/*
int main(){
    int arr[5]={1,47,58,47,25};
    int n= sizeof(arr)/sizeof(arr[0]);
    int key;
    printf("enter the number which you want to find: ");
    scanf("%d",&key);

    for(int i=0;i<n;i++){
        if(arr[i]==key){
            printf("key is found at index: %d",i);
            break;   
        }
        else{
            printf("key is not found");
        }
    }
   

    return 0;
}*/

int linearsearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
       
    }
    return -1;

}

int main(){
    int arr[]={1,34,67,890,34,12,44,56};

    int n= sizeof(arr)/sizeof(arr[0]);
   int key;
   printf("enter the number which you want to find: ");
    scanf("%d",&key);
    int result =linearsearch(arr,n,key);
  if(result!=-1){
    printf("KEY IS FOUND AT INDEX: %d",result);
  }
  else{
     printf("KEY IS NOT FOUND");
  }

  return 0;
}