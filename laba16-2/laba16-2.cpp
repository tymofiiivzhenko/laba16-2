#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, positive, N;

    do {
        printf("Enter the value for N, N <= 10: ");
        scanf("%d", &N);

        if (N <= 0 || N > 10) {
            printf("Invalid value for N. Enter the value in the range from 1 to 10.\n");
        }

    } while (N <= 0 || N > 10);

    double** A = (double**)malloc(N * sizeof(double*));
    for (i = 0; i < N; ++i) {
        A[i] = (double*)malloc(N * sizeof(double));
    }

    printf("Enter elements for A[%d x %d]:\n", N, N);
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &A[i][j]);
        }
    }

    printf("\nA[%d x %d]:\n", N, N);
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            printf("%g\t", A[i][j]);
        }
        printf("\n");
    }

    printf("\nThe number of positive values:\n");
    for (i = 0; i < N; ++i) {
        positive = 0;
        for (j = 0; j < N; ++j) {
            if (A[i][j] > 0) {
                positive++;
            }
        }
        printf("Row %d: %d positive values\n", i + 1, positive);
    }

    for (i = 0; i < N; ++i) {
        free(A[i]);
    }
    free(A);

    return 420;
}
