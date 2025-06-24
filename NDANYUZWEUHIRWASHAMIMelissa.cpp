#include <stdio.h>

//This is the function to find and print the median
void mediansPrint(int arr[][100], int n)
{
    printf("\nPattern B:The median Pattern\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == n / 2 || j == n / 2)
            {
                printf("%d ", arr[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

//This is the function to print the upper triangle pattern

void upperTriangle(int arr[][100], int n)
{
    printf("\nPattern C:The upper triagle pattern:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j >= i)
            {
                printf("%d ", arr[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}
//This is the function to print the diogonal pattern
void diagonPrint(int arr[][100], int n)
{
    printf("\nPattern A:Diogonal Pattern:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || i + j == n - 1)
            {
                printf("%d ", arr[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

//this is the function to print the lower triangle pattern
void lowerTriangle(int arr[][100], int n)
{
    printf("\nPattern D:Lower triangle pattern\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j >= n - 1)
            {
                printf("%d ", arr[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}
//This is the function to print the array with sum rows
void sumOfRows(int arr[][100], int n)
{
    printf("\nPattern E:All numbers with row sums\n");
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
            sum += arr[i][j];
        }
        printf("| %d\n", sum);
    }
}
//this is the function to print the column products
void columnProducts(int arr[][100], int n)
{
    printf("\nPattern G: All numbers with column products\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int j = 0; j < n; j++)
    {
        int columnProduct = 1;
        for (int i = 0; i < n; i++)
        {
            columnProduct *= arr[i][j];
        }
        printf("%d ", columnProduct);
    }
    printf("<---------Column Products\n");
}
//this is the function to find the determinant
int determinant(int arr[][100], int n)
{
    if (n == 1)
        return arr[0][0];
    if (n == 2)
        return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];

    int det = 0;
    int temp[100][100];
    int sign = 1;

    for (int i = 0; i < n; i++)
    {
        int subi = 0;
        for (int j = 1; j < n; j++)
        {
            int subj = 0;
            for (int k = 0; k < n; k++)
            {
                if (k == i)
                    continue;
                temp[subi][subj] = arr[j][k];
                subj++;
            }
            subi++;
        }
        det += sign * arr[0][i] * determinant(temp, n - 1);
        sign = -sign;
    }
    return det;
}

int main()
{
    int n;
    printf("Enter the size of your the matrix (n): ");
    scanf("%d", &n);

    int arr[100][100];
    printf("Enter %d numbers:", n * n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    diagonPrint(arr, n);
    mediansPrint(arr, n);
    upperTriangle(arr, n);
    lowerTriangle(arr, n);
    sumOfRows(arr, n);
    columnProducts(arr, n);

    printf("\n Pattern G: Determinant of the matrix= %d\n", determinant(arr, n));

    return 0;
}
