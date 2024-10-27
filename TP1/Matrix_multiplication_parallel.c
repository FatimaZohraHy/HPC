#include <mpi.h>    // Include the MPI library for parallel processing
#include <stdio.h>  
#define SIZE 2      
int main(int argc, char** argv) {
    int rank, size;                       // Variables to hold the rank of each process and total number of processes
    int A[SIZE][SIZE] = {{1, 2}, {3, 4}}; // Initialize 2x2 matrix A
    int B[SIZE][SIZE] = {{5, 6}, {7, 8}}; // Initialize 2x2 matrix B
    int C[SIZE][SIZE] = {0};              // Initialize 2x2 matrix C with all elements set to 0 (for storing result)
    int local_C[SIZE][SIZE] = {0};        // Initialize local result matrix for each process

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Get the rank (ID) of the current process
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Get the total number of processes

    // Each process calculates part of the resulting matrix C
    for (int i = rank; i < SIZE; i += size) {     // Loop over rows assigned to this process
        for (int j = 0; j < SIZE; j++) {          // Loop over columns of B
            for (int k = 0; k < SIZE; k++) {      // Perform the multiplication for each element
                local_C[i][j] += A[i][k] * B[k][j]; // Multiply and accumulate values for local_C[i][j]
            }
        }
    }

    // Combine the results of each process into matrix C on the root process (rank 0)
    MPI_Reduce(local_C, C, SIZE * SIZE, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // The master process (rank 0) prints the resulting matrix
    if (rank == 0) {
        printf("Produit de matrices A et B (parallèle):\n");
        for (int i = 0; i < SIZE; i++) {      // Loop over rows of matrix C
            for (int j = 0; j < SIZE; j++) {  // Loop over columns of matrix C
                printf("%d ", C[i][j]);       // Print the element at C[i][j]
            }
            printf("\n");                     // Newline after each row
        }
    }

    // Finalize the MPI environment
    MPI_Finalize();

    return 0;   // End of the program
}
