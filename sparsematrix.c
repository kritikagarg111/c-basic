#include <stdio.h>
#include <stdlib.h>

// Define the structure for non-zero elements
struct Element {
    int row;
    int col;
    int value;
};

typedef struct Element Element;
// Function to create the sparse matrix representation
Element* createSparseMatrix(int **matrix, int rows, int cols, int *size) {
    // Count the number of non-zero elements
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }

    // Allocate memory for the array of non-zero elements
    Element *sparseMatrix = (Element*)malloc(count * sizeof(Element));
    *size = count;

    // Store the non-zero elements along with their row and column indices
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[index].row = i;
                sparseMatrix[index].col = j;
                sparseMatrix[index].value = matrix[i][j];
                index++;
            }
        }
    }

    return sparseMatrix;
}
// Function to display the sparse matrix representation
void displaySparseMatrix(Element *sparseMatrix, int size) {
    printf("Row  Column  Value\n");
    for (int i = 0; i < size; i++) {
        printf("%d    %d      %d\n", sparseMatrix[i].row, sparseMatrix[i].col, sparseMatrix[i].value);
    }
}
// Function to add two sparse matrices
Element* addSparseMatrices(Element *mat1, int size1, Element *mat2, int size2, int *resultSize) {
    Element *result = (Element*)malloc((size1 + size2) * sizeof(Element));
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (mat1[i].row < mat2[j].row || (mat1[i].row == mat2[j].row && mat1[i].col < mat2[j].col)) {
            result[k++] = mat1[i++];
        } else if (mat2[j].row < mat1[i].row || (mat2[j].row == mat1[i].row && mat2[j].col < mat1[i].col)) {
            result[k++] = mat2[j++];
        } else {
            result[k].row = mat1[i].row;
            result[k].col = mat1[i].col;
            result[k].value = mat1[i].value + mat2[j].value;
            k++;
            i++;
            j++;
        }
    }

    while (i < size1) {
        result[k++] = mat1[i++];
    }

    while (j < size2) {
        result[k++] = mat2[j++];
    }

    *resultSize = k;
    return result;
}
int main() {
    int rows = 4;
    int cols = 5;

    int matrix1[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    int matrix2[4][5] = {
        {0, 0, 0, 0, 4},
        {0, 0, 5, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0}
    };

    // Allocate memory for the dynamic 2D arrays
    int **dynamicMatrix1 = (int **)malloc(rows * sizeof(int *));
    int **dynamicMatrix2 = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        dynamicMatrix1[i] = (int *)malloc(cols * sizeof(int));
        dynamicMatrix2[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            dynamicMatrix1[i][j] = matrix1[i][j];
            dynamicMatrix2[i][j] = matrix2[i][j];
        }
    }

    int size1, size2;
    Element *sparseMatrix1 = createSparseMatrix(dynamicMatrix1, rows, cols, &size1);
    Element *sparseMatrix2 = createSparseMatrix(dynamicMatrix2, rows, cols, &size2);

    printf("Sparse Matrix 1 Representation:\n");
    displaySparseMatrix(sparseMatrix1, size1);
    printf("Sparse Matrix 2 Representation:\n");
    displaySparseMatrix(sparseMatrix2, size2);

    int resultSize;
    Element *result = addSparseMatrices(sparseMatrix1, size1, sparseMatrix2, size2, &resultSize);

    printf("Resultant Sparse Matrix Representation:\n");
    displaySparseMatrix(result, resultSize);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(dynamicMatrix1[i]);
        free(dynamicMatrix2[i]);
    }
    free(dynamicMatrix1);
    free(dynamicMatrix2);
    free(sparseMatrix1);
    free(sparseMatrix2);
    free(result);

    return 0;
}
