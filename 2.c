#include <stdio.h>
#include <stdlib.h>

int** genRandMatrix(int size, int maxValue)
{
    int** matrix = malloc((size+1)*sizeof(int*));
    matrix[0] = malloc(sizeof(int));
    matrix[0][0] = size;
    for(int i = 1; i <= size; i++)
    {
        int sizeRow = rand() % 10;
        matrix[i] = malloc((sizeRow+1) * sizeof(int));
        matrix[i][0] = sizeRow;
        for(int j = 1; j <= sizeRow; j++)
        {
            matrix[i][j] = rand() % (maxValue + 1);
        }
    }
    return matrix;
}

void printMatrix(int** matrix)
{
    printf("%d", matrix[0][0]);
    for(int i = 1; i <= matrix[0][0]; i++)
    {
        printf("\n%d:", matrix[i][0]);
        for(int j = 1; j <= matrix[i][0]; j++)
        {
            printf(" %d", matrix[i][j]);
        }
    }
    return;
}

int main()
{
    int size = 4;
    int maxValue = 100;
    int** matrix = genRandMatrix(size, maxValue);
    printMatrix(matrix);
    for(int i = 0; i < size; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}