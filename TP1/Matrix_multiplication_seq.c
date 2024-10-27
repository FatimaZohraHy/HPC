#include <stdio.h>       
#define SIZE 2           

int main() {
    int A[SIZE][SIZE] = {{1, 2}, {3, 4}};   // Initialize 2x2 matrix A
    int B[SIZE][SIZE] = {{5, 6}, {7, 8}};   // Initialize 2x2 matrix B
    int C[SIZE][SIZE] = {0};                // Initialize 2x2 matrix C with all elements set to 0

    // Compute the product of matrices A and B, store the result in C
    for (int i = 0; i < SIZE; i++) {        // Loop over rows of matrix A
        for (int j = 0; j < SIZE; j++) {    // Loop over columns of matrix B
            for (int k = 0; k < SIZE; k++) {// Loop for matrix multiplication
                C[i][j] += A[i][k] * B[k][j]; // Multiply and accumulate values for element C[i][j]
            }
        }
    }

    // Display the resulting matrix C
    printf("Produit de matrices A et B:\n");
    for (int i = 0; i < SIZE; i++) {        // Loop over rows of matrix C
        for (int j = 0; j < SIZE; j++) {    // Loop over columns of matrix C
            printf("%d ", C[i][j]);         // Print the element at C[i][j]
        }
        printf("\n");                       // Newline after each row
    }

    return 0;                               // End of the program
}
