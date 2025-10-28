#include<stdio.h>
#include<stdlib.h>
#include<time.h>



int main(){
    int n, m;
    printf("enter the number of rows in a matrix 1: ");
    scanf("%d",&n);
     printf("enter the number of columns in a matrix 1: ");
    scanf("%d",&m);

    int arr1[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %d",&arr1[i][j]);
        }
       
    }
      int n2, m2;
    printf("enter the number of rows in a matrix 2: ");
    scanf("%d",&n2);
     printf("enter the number of columns in a matrix 2: ");
    scanf("%d",&m2);

    int arr2[n2][m2];
    for(int i=0;i<n2;i++){
        for(int j=0;j<m2;j++){
            scanf(" %d",&arr2[i][j]);
        }
      
    }

 if(m!=n2){
    printf("Matrix cant be multiplied");
    return 1;
 }
    //multiplication approach

int arr_result[n][m2];

clock_t start =clock();

for(int i=0;i<1000;i++){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m2; j++) {
            arr_result[i][j] = 0;
        }
    }

   for(int i=0;i<n;i++){
        for(int j=0;j<m2;j++){
            for(int k=0;k<n2;k++){
               arr_result[i][j] +=arr1[i][k]*arr2[k][j];
            }
        }
    }
}
    
clock_t end =clock();
    printf("Resultant Matrix is :\n");
 for(int i=0;i<n;i++){
    for(int j=0;j<m2;j++){
        printf("  %d",arr_result[i][j]);
    }
    printf("\n");
 }
 double time_taken =((double)(end-start))/CLOCKS_PER_SEC/1000;
    printf("\n Time taken to multiply the matrix is: %f",time_taken);
    return 0;
}