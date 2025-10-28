#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int max(int a, int b) {
    return (a > b) ? a : b;
}


int knapsackTab(int W, int weight[], int value[], int n) {
  
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    if (dp == NULL) return -1;
    for (int i = 0; i <= n; i++) {
        dp[i] = (int*)malloc((W + 1) * sizeof(int));
        if (dp[i] == NULL) return -1; 
    }

   
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weight[i - 1] <= w) {
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int result = dp[n][W];

    
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int* weight = (int*)malloc(n * sizeof(int));
    int* value = (int*)malloc(n * sizeof(int));
    if (weight == NULL || value == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

  
    for (int i = 0; i < n; i++) {
      weight[i] = rand() % 20 + 1;
      value [i]= rand() % 20 + 1;

      if(n < 20){
 printf("Item %d: Weight = %d, Value = %d\n", i + 1, weight[i], value[i]);
      }
         
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);
    
    clock_t start = clock();
    for(int i=0;i<1000;i++);
    int result = knapsackTab(W, weight, value, n);
    clock_t end = clock();

    printf("Maximum value (Tabulation) = %d\n", result);
    printf("Time taken: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC/1000);

    free(weight);
    free(value);

    return 0;
}