#include <stdio.h>

// RAW METHOD - Matrix multiplication
void matrix_multiply_raw(int A[][3], int B[][3], int C[][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// BUILT-IN METHOD - Using optimized loops
void matrix_multiply_builtin(int A[][3], int B[][3], int C[][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void print_matrix(int matrix[][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int C[3][3];
    int n = 3;
    
    matrix_multiply_raw(A, B, C, n);
    printf("Raw Matrix Multiplication:\n");
    print_matrix(C, n);
    
    matrix_multiply_builtin(A, B, C, n);
    printf("Built-in Matrix Multiplication:\n");
    print_matrix(C, n);
    return 0;
}
