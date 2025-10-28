#include <stdio.h>
#include <stdlib.h>
#include<time.h>

// Add matrices A and B into C
void add(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Recursive Divide and Conquer Matrix Multiplication
void multiply(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if(n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int newSize = n/2;

    // Temporary submatrices
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];

    // Split A and B into 4 submatrices
    for(int i=0; i<newSize; i++) {
        for(int j=0; j<newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Compute C11 = A11*B11 + A12*B21
    multiply(newSize, A11, B11, temp1);
    multiply(newSize, A12, B21, temp2);
    add(newSize, temp1, temp2, C11);

    // Compute C12 = A11*B12 + A12*B22
    multiply(newSize, A11, B12, temp1);
    multiply(newSize, A12, B22, temp2);
    add(newSize, temp1, temp2, C12);

    // Compute C21 = A21*B11 + A22*B21
    multiply(newSize, A21, B11, temp1);
    multiply(newSize, A22, B21, temp2);
    add(newSize, temp1, temp2, C21);

    // Compute C22 = A21*B12 + A22*B22
    multiply(newSize, A21, B12, temp1);
    multiply(newSize, A22, B22, temp2);
    add(newSize, temp1, temp2, C22);

    // Combine submatrices 
    for(int i=0; i<newSize; i++) {
        for(int j=0; j<newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

void printMatrix(int n, int matrix[n][n]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}




int main() {
    int n;
    printf("Enter size of square matrices (power of 2): ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter matrix A:\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf(" %d", &A[i][j]);

    printf("Enter matrix B:\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf(" %d", &B[i][j]);
    clock_t start =clock();
    for(int i=0;i<1000;i++)
     multiply(n, A, B, C);
   clock_t end =clock();
    printf("Result matrix C:\n");
    printMatrix(n, C);
    double time_taken =(double)(end-start)/CLOCKS_PER_SEC/1000;
    printf("\n Time taken to multiply is: %f",time_taken);

    return 0;
}
