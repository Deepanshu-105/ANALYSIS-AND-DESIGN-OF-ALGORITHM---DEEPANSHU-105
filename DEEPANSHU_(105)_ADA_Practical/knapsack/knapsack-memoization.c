#include<stdio.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 100


int dp[MAX_ITEMS][MAX_CAPACITY];

int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}


int knapsack_memo(int w,int wt[],int val[],int n){
    if(n==0 || w==0){
        return 0;
    }
    if(dp[n][w]!= -1){
        return dp[n][w];

    }
    if(wt[n-1]>w){
        return dp[n][w]=knapsack_memo(w,wt,val,n-1);
    }
    else {
        return dp[n][w]=max(val[n-1] + knapsack_memo(w-wt[n-1],wt,val,n-1), knapsack_memo(w,wt,val,n-1));
    }
}


int main(){
    int values[]={3,4,5,6};
    int weights[]={2,3,4,5};
    int w=8;
    int n=sizeof(values)/sizeof(values[0]);

    for(int i=0;i<=n;++i){
        for(int j=0;j<=w;++j){
            dp[i][j]= -1;
        }
    }

    printf("Maximum values that can be put in knapsack :%d\n", knapsack_memo(w,weights,values,n));

    return 0;
}