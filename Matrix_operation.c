#include <stdio.h>
#define MAX 10
// Function to add two matrices

void addition(int a[MAX][MAX], int b[MAX][MAX], int r, int c)
{
    int i, j;
    printf("\nMatrix Addition:\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%4d", a[i][j] + b[i][j]);
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplication(int a[MAX][MAX], int b[MAX][MAX], int r1, int c1, int c2)
{
    int i, j, k, sum;
    printf("\nMatrix Multiplication:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            sum = 0;
            for (k = 0; k < c1; k++)
                sum += a[i][k] * b[i][j];
            printf("%4d", sum);
        }
        printf("\n");
    }
}

// Function to display a transpose
void transpose(int a[MAX][MAX], int r, int c) 
{
    int i, j;
    printf("\nTranspose of First Matrix:\n");
    for (j = 0; j < c; j++)
    {
        for (i = 0; i < r; i++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
}
int main()
{
    int a[MAX][MAX], b[MAX][MAX];
    int r1, c1, r2, c2;
    int i, j;
    printf("Enter rows and columns of first matrix:");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns of second matrix:");
    scanf("%d %d", &r2, &c2);
    // check dimensions
    if (r1 < 1 || r1 > MAX || c1 < 1 || c1 > MAX)
    {
        printf("Invalid matrix size");
        return 0;
    }
    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r1; i++) 
        for (j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("Enter the elements of second matrix:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);
    // Addition requires equal dimensions
    if (r1 == r2 && c1 == c2)
        addition(a, b, r1, c1);
    else
        printf("\nAddition is not possible.\n");

    // Multiplication requires c1 == r2
    if (c1 == r2)
        multiplication(a, b, r1, c1, c2);
    else
        printf("\nMultiplication is not possible.\n");

    // Transpose of first matrix
    transpose(a, r1, c1);
    return 0;
}