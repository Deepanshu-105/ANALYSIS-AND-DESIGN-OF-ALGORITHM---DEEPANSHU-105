#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int knapsackRecursive(int w, int wt[], int val[], int n){
    if(n == 0 || w == 0){
        return 0;
    }
    if(wt[n-1] > w){
        return knapsackRecursive(w, wt, val, n-1);
    }
    else{
        return max(val[n-1] + knapsackRecursive(w - wt[n-1], wt, val, n-1), knapsackRecursive(w, wt, val, n-1));
    }
}

int main(){
    int n, w;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    
    int *weights = (int *)malloc(n * sizeof(int));
    int *values = (int *)malloc(n * sizeof(int));

   
    for(int i = 0; i < n; i++){
        weights[i] = rand() % 20 + 1;
        values[i] = rand() % 20 + 1;
            if(n < 20){
 printf("Item %d: Weight = %d, Value = %d\n", i + 1, weights[i], values[i]);
      }
    }

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &w);
clock_t start = clock();
 printf("\nMaximum value that can be put in Knapsack: %d\n", knapsackRecursive(w, weights, values, n));

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %.6f seconds\n", time_taken);


    free(weights);
    free(values);

    return 0;
}