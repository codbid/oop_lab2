#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 100


int** get_array(int n)
{
    int** arr = malloc(sizeof(int*)*n);
    for(int i = 0; i < n; i++)
    {
        arr[i] = malloc(sizeof(int) * n);
    }
    return arr;
}

void set_array(int** arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            arr[i][j] = rand() % (MAX_VAL + 1);
    }
}

void print_array1(int* arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_array2(int** arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void a(int** arr, int* D)
{
    int n = D[0] - 1;
    int i = 0;
    int j = n;
    int i1 = 0;
    for(int k = 1; k < (n + 1) * 2; k++) // +2
    {
        if(k <= n + 1)
        {
            while (i <= n && j <= n)
            {
                D[i1] = arr[i][j];
                i++;
                j++;
                i1++;
            }
            j = n - k;
            i = 0;
        }
        else
        {
            j = 0;
            i = k - n - 1;
            while (i <= n && j <= n)
            {
                D[i1] = arr[i][j];
                i++;
                j++;
                i1++;
            }
        }
    }
    printf("\n a) ");
    print_array1(D, (n+1)*(n+1));
}

void b(int** arr, int* D)
{
    int n = D[0] - 1;
    int i;
    int j;
    int i1 = 0;
    for(int k = 0; k <= n * 2; k++)
    {
        if(k <= n)
        {
            j = k;
            i = 0;  
        }
        else
        {
            i = k - n;
            j = n;
        }
        while(j >= 0 && i <= n)
        {
            D[i1] = arr[i][j];
            i++;
            j--;
            i1++;
        }
    }
    printf("\n b) ");
    print_array1(D, (n+1)*(n+1));
}

void c(int** arr, int* D)
{
    int n = D[0] - 1;
    int i = n/2;
    int j = n/2;
    int i1 = 0;
    int k = 2;
    D[i1] = arr[i][j];
    i1++;
    for(int m = 0; m < (n+1)/2; m++)
    {
        j++;
        for(int y = 1; y < k; y++)
        {
            D[i1] = arr[i][j];
            i1++;
            i++;
        }
        D[i1] = arr[i][j];
        i1++;
        for(int y = 0; y < k; y++)
        {
            j--;
            D[i1] = arr[i][j];
            i1++;
        }
        for(int y = 0; y < k; y++)
        {
            i--;
            D[i1] = arr[i][j];
            i1++;
        }
        for(int y = 0; y < k; y++)
        {
            j++;
            D[i1] = arr[i][j];
            i1++;
        }
        k+=2;
    }
    printf("\n c) ");
    print_array1(D, (n+1)*(n+1));

}

void d(int** arr, int* D)
{
    int n = D[0] - 1;
    int i = 0;
    int j = 0;
    int i1 = 0;
    int k = n;
    for(int m = 0; m < (n+1)/2; m++)
    {
        for(int y = 0; y < k; y++)
        {
            D[i1] = arr[i][j];
            i1++;
            j++;
        }
        for(int y = 0; y < k; y++)
        {
            D[i1] = arr[i][j];
            i1++;
            i++;
        }
        for(int y = 0; y < k; y++)
        {
            D[i1] = arr[i][j];
            i1++;
            j--;
        }
        for(int y = 1; y < k; y++)
        {
            D[i1] = arr[i][j];
            i1++;
            i--;
        }
        D[i1] = arr[i][j];
        i1++;
        j++;
        k-=2;
    }
    D[i1] = arr[i][j];
    printf("\n d) ");
    print_array1(D, (n+1)*(n+1));


}

int main()
{
    int n = 5;
    int** arr = get_array(n);
    int* D = malloc(sizeof(int) * n * n);
    D[0] = n;
    set_array(arr, n);
    print_array2(arr, n);
    c(arr, D);
    for(int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);
    free(D);
}