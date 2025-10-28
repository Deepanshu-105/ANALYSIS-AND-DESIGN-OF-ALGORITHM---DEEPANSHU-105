#include<stdio.h>

int binaryrecurssive(int arr[],int n,int key, int l,int r){
    int mid=l+(r-l)/2;
while(l<=r){
if(key==arr[mid]){
        return mid;
    }
if(key<arr[mid]){
    return binaryrecurssive(arr,n,key,l,mid-1);
}
else{
    return binaryrecurssive(arr,n,key,mid+1,r);
}

}
}

int main(){
    int arr[]={1,2,8,9,15,67,102};

    int n= sizeof(arr)/sizeof(arr[0]);
   int key;
   printf("enter the number which you want to find: ");
    scanf("%d",&key);
    int left=0;
    int right=n;
    int result =binaryrecurssive(arr,n,key,0,n);
  if(result!=-1){
    printf("KEY IS FOUND AT INDEX: %d",result);
  }
  else{
     printf("KEY IS NOT FOUND");
  }

  return 0;
}