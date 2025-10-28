#include<stdio.h>


int binaryiterative(int arr[],int n,int key,int left,int right){
 int mid= left +(right-left)/2;
 while(left<=right){
 if(arr[mid]==key){
    return mid;
 }
 if(key<arr[mid]){
    right=mid-1;
 }
  else{
    left=mid+1;
 }
 }
 return -1;
}


int main(){
   int arr[]={1,2,8,9,15,67,102};

    int n= sizeof(arr)/sizeof(arr[0]);
   int key;
   printf("enter the number which you want to find: ");
    scanf("%d",&key);
    int left=0;
    int right=n;
    int result =binaryiterative(arr,n,key,0,n);
  if(result!=-1){
    printf("KEY IS FOUND AT INDEX: %d",result);
  }
  else{
     printf("KEY IS NOT FOUND");
  }

  return 0;
} 
