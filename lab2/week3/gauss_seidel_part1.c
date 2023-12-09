/*
 * C program to implement Gauss Seidel Method
 * based on:
 * https://www.sanfoundry.com/c-program-implement-gauss-seidel-method/
 * 
 * author: Alicja Wagner
 * 
 * It's a prototype of the code, it still needs a lot of changes and cleaning.
 * For now the program can solve one system of linear equations using Gauss-Seidel model.
 */
#include <stdio.h>
#include <math.h>

#define MAX_ITER 500
#define MAT_SIZE 10
#define EPP 0.000001

int if_converges(double a[MAT_SIZE][MAT_SIZE], double b[MAT_SIZE]) {

    double  x[MAT_SIZE] = {0}, y[MAT_SIZE] = {0};
    int iter = MAX_ITER;
    int n = MAT_SIZE, i = 0, j = 0;
    int flag = 1;

 
    //Iterating a loop for no of iterations
    while (flag == 1 && iter > 0)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            y[i] = (b[i] / a[i][i]);
            for (j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);

                if (fabs((y[i] - x[i]) > EPP))
                    flag = 1;

                x[i] = y[i];
            }
            printf("x%d = %f    ", i + 1, y[i]);
        }
        printf("\n");
        iter--;
    }

    printf("\nIterations done: %d\n", MAX_ITER - iter);

    return 0;
}
 
int main()
{
    double  x[MAT_SIZE], y[MAT_SIZE], epp = 0.00001;
    int n = 0, m = 0, i = 0, j = 0;
    int flag = 1;
 
    n = MAT_SIZE; // size of the matrix


    // double a[MAT_SIZE][MAT_SIZE] = {
    //     {14, -1, 2, -1, 3, -1, 2, -1, 3, -1},
    //     {-1, 5, -1, 2, -3, -1, 2, -1, 3, -1},
    //     {2, -1, 10, -1, 2, -1, 2, -1, 2, -1},
    //     {-1, 2, -1, 8, -1, -1, 3, -1, 2, -1},
    //     {3, -3, 2, -1, 19, -1, 7, -1, 9, -1},
    //     {-1, -3, -1, 7, -1, 8, -1, 2, 4, -1},
    //     {2, -1, 2, -1, 8, -1, 10, -1, 3, -1},
    //     {-1, 2, -1, 3, -6, -1, 5, -11, 6, -1},
    //     {3, -2, 2, -1, 7, -1, 4, -1, 20, -1},
    //     {-1, 2, -1, 5, -1, -1, 3, -1, 2, 10}
    // };

    // double b[MAT_SIZE] = {10, -8, 20, 0, 15, -7, 8, 5, 9, 6};

    double a[MAT_SIZE][MAT_SIZE] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
        {3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
        {4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
        {5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
        {6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
        {7, 8, 9, 10, 11, 12, 13, 14, 15, 16},
        {8, 9, 10, 11, 12, 13, 14, 15, 16, 17},
        {9, 10, 11, 12, 13, 14, 15, 16, 17, 18},
        {10, 11, 12, 13, 14, 15, 16, 17, 18, 19}
    };

    double b[MAT_SIZE] = {100,110,120,130,140,150,160,170,180,190};



    if_converges(a, b);

    return 0;
}