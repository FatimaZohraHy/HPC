#include <stdio.h>    
#include <stdlib.h>    
#include <time.h>      

#define N 100000000    // Define a constant N representing the number of rectangles

// Function to calculate f(x) = x^2
double f(double x) {
    return x * x;      // Return x squared
}

int main() {
    double width = 1.0 / N;     // Calculate the width of each rectangle
    double area = 0.0;          // Initialize the total area (integral approximation) to 0
    clock_t start, end;         // Variables to store start and end times for timing

    start = clock();            // Record the start time of the calculation
    for (int i = 0; i < N; i++) {       // Loop over each rectangle
        area += f((i + 0.5) * width);   // Calculate the function value at the rectangle's midpoint
    }
    area *= width;              // Multiply the sum of heights by the width to get the integral approximation

    end = clock();              // Record the end time of the calculation

    // Display the calculated integral of f(x) over the interval [0, 1]
    printf("Intégrale de f(x) = x^2 sur [0, 1]: %f\n", area);

    // Calculate and display the execution time in seconds
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Temps d'exécution (séquentiel): %f secondes\n", time_taken);

    return 0;   // End of the program
}
