#include <stdio.h>
#include <stdlib.h>

/**
 * Function: getTridiagonalElement
 * -------------------------------
 * Retrieves the value of a logical matrix element a[i][j] 
 * from the compressed 1D array 'b'.
 *
 * b: The 1D array storing non-zero elements row-by-row.
 * n: The dimension of the square matrix (n x n).
 * i: The row index.
 * j: The column index.
 *
 * returns: The value at a[i][j] (0 if outside the tridiagonal band).
 */
int getTridiagonalElement(int *b, int n, int i, int j) {
    // 1. Check boundary conditions for the matrix dimensions
    if (i < 0 || i >= n || j < 0 || j >= n) {
        printf("Error: Index out of bounds.\n");
        return -1; 
    }

    // 2. Check if the element is on the tridiagonal band.
    // The condition is |i - j| <= 1.
    // Equivalently: j == i, j == i-1, or j == i+1
    if (abs(i - j) > 1) {
        return 0; // Return 0 for all elements outside the band
    }

    // 3. Apply the mapping formula derived: Index = 2i + j
    int k = 2 * i + j;

    return b[k];
}

int main() {
    int n = 5; // Size of the matrix (5x5)
    
    // Total non-zero elements in a tridiagonal matrix = 3n - 2
    // For n=5, size = 15 - 2 = 13 elements.
    // Let's create a sample 1D array with dummy data.
    // Represents: [a00, a01, a10, a11, a12, a21, a22, a23, a32, a33, a34, a43, a44]
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    
    printf("Logical 5x5 Matrix Reconstructed from 1D Array:\n");
    printf("-----------------------------------------------\n");

    // Loop through rows and columns to print the full matrix
    for (int i = 0; i < n; i++) {
        printf("| ");
        for (int j = 0; j < n; j++) {
            // Retrieve value using our algorithm
            int val = getTridiagonalElement(b, n, i, j);
            printf("%2d ", val);
        }
        printf("|\n");
    }
    int row = 2, col = 1;
    printf("\nDirect Query for a[%d][%d]: %d\n", row, col, getTridiagonalElement(b, n, row, col));
    
    row = 0; col = 4;
    printf("Direct Query for a[%d][%d] (should be 0): %d\n", row, col, getTridiagonalElement(b, n, row, col));

    return 0;
}