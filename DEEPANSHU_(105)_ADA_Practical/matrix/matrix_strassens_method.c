#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int** allocateMatrix(int size) {
    int** matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++){
        matrix[i] = (int*)malloc(size * sizeof(int));
    }
        
    return matrix;
}


void freeMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++){
     free(matrix[i]);
    }
       
    free(matrix);
}

// Matrix addition
void addMatrix(int** A, int** B, int** result, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = A[i][j] + B[i][j];
}

// Matrix subtraction
void subMatrix(int** A, int** B, int** result, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = A[i][j] - B[i][j];
}

// Strassen's multiplication algorithm
void strassen(int** A, int** B, int** C, int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;

    // Allocate submatrices
    int** A11 = allocateMatrix(newSize);
    int** A12 = allocateMatrix(newSize);
    int** A21 = allocateMatrix(newSize);
    int** A22 = allocateMatrix(newSize);
    int** B11 = allocateMatrix(newSize);
    int** B12 = allocateMatrix(newSize);
    int** B21 = allocateMatrix(newSize);
    int** B22 = allocateMatrix(newSize);

    // Split matrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
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

    // Allocate temporary matrices
    int** P = allocateMatrix(newSize);
    int** Q = allocateMatrix(newSize);
    int** R = allocateMatrix(newSize);
    int** S = allocateMatrix(newSize);
    int** T = allocateMatrix(newSize);
    int** U = allocateMatrix(newSize);
    int** V = allocateMatrix(newSize);
    int** temp1 = allocateMatrix(newSize);
    int** temp2 = allocateMatrix(newSize);

    // P = (A11 + A22) * (B11 + B22)
    addMatrix(A11, A22, temp1, newSize);
    addMatrix(B11, B22, temp2, newSize);
    strassen(temp1, temp2, P, newSize);

    // Q = (A21 + A22) * B11
    addMatrix(A21, A22, temp1, newSize);
    strassen(temp1, B11, Q, newSize);

    // R = A11 * (B12 - B22)
    subMatrix(B12, B22, temp1, newSize);
    strassen(A11, temp1, R, newSize);

    // S = A22 * (B21 - B11)
    subMatrix(B21, B11, temp1, newSize);
    strassen(A22, temp1, S, newSize);

    // T = (A11 + A12) * B22
    addMatrix(A11, A12, temp1, newSize);
    strassen(temp1, B22, T, newSize);

    // U = (A21 - A11) * (B11 + B12)
    subMatrix(A21, A11, temp1, newSize);
    addMatrix(B11, B12, temp2, newSize);
    strassen(temp1, temp2, U, newSize);

    // V = (A12 - A22) * (B21 + B22)
    subMatrix(A12, A22, temp1, newSize);
    addMatrix(B21, B22, temp2, newSize);
    strassen(temp1, temp2, V, newSize);

    // Compute C11 to C22
    int** C11 = allocateMatrix(newSize);
    int** C12 = allocateMatrix(newSize);
    int** C21 = allocateMatrix(newSize);
    int** C22 = allocateMatrix(newSize);

    addMatrix(P, S, temp1, newSize); // M1 + M4
    subMatrix(temp1, T, temp2, newSize); // M1 + M4 - M5
    addMatrix(temp2, V, C11, newSize); // C11

    addMatrix(R, T, C12, newSize);
    addMatrix(Q, S, C21, newSize);

    addMatrix(P, R, temp1, newSize); // M1 + M3
    subMatrix(temp1, Q, temp2, newSize); // M1 + M3 - M2
    addMatrix(temp2, U, C22, newSize); // C22

    // Combine results into final matrix C
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    // Free all allocated memory
    freeMatrix(A11, newSize);
     freeMatrix(A12, newSize);
      freeMatrix(A21, newSize); 
      freeMatrix(A22, newSize);
    freeMatrix(B11, newSize);
     freeMatrix(B12, newSize);
      freeMatrix(B21, newSize);
       freeMatrix(B22, newSize);
    freeMatrix(C11, newSize);
     freeMatrix(C12, newSize);
      freeMatrix(C21, newSize);
       freeMatrix(C22, newSize);
    freeMatrix(P, newSize);
     freeMatrix(Q, newSize);
      freeMatrix(R, newSize);
       freeMatrix(S, newSize);
    freeMatrix(T, newSize); 
    freeMatrix(U, newSize); 
    freeMatrix(V, newSize);
    freeMatrix(temp1, newSize); 
    freeMatrix(temp2, newSize);
}

// Print matrix
void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int size;

    printf("Enter size of the matrix (power of 2): ");
    scanf("%d", &size);

    int** A = allocateMatrix(size);
    int** B = allocateMatrix(size);
    int** C = allocateMatrix(size);

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &B[i][j]);
    clock_t start=clock();
    for(int i=0;i<1000;i++){
        strassen(A, B, C, size);
    }
    strassen(A, B, C, size);
    clock_t end =clock();
    printf("Resultant matrix C (A x B):\n");
    printMatrix(C, size);
    double time_taken =((double)(end-start))/CLOCKS_PER_SEC/1000;
    printf("\n Time taken to multiply the matrix is: %f",time_taken);
    freeMatrix(A, size);
    freeMatrix(B, size);
    freeMatrix(C, size);

    return 0;
}
