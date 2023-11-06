/*
 * C program to implement Gauss Seidel Method based on:
 * https://www.sanfoundry.com/c-program-implement-gauss-seidel-method/
 * 
 * author: Alicja Wagner
 * 
 * Compile with -lm flag.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ITER 1000
#define MAT_SIZE 100
#define MAT_NUMBER 10
#define EPS 0.000000001     // 10e-9 -> epsilon (precision)


int if_converges(double a[MAT_SIZE][MAT_SIZE], double b[MAT_SIZE]);
void randomize_mat(double a[MAT_SIZE][MAT_SIZE]);
void randomize_vec(double b[MAT_SIZE]);

 
int main() {

    double a[MAT_NUMBER][MAT_SIZE][MAT_SIZE] = {{{0}}};
    double b[MAT_NUMBER][MAT_SIZE] = {{0}};
    int i = 0;
    int result[MAT_NUMBER] = {0};
    int converged = 0;
    time_t t;

    srand((unsigned) time(&t));

    // randomizing matrices and vectors
    for (i = 0; i < MAT_NUMBER; i++){
        randomize_mat(a[i]);
        randomize_vec(b[i]);
    }

    // solving the systems of linear equations 
    for (i = 0; i < MAT_NUMBER; i++){
        result[i] = if_converges(a[i], b[i]);
    }

    for (i = 0; i < MAT_NUMBER; i++) {
        printf("\nConverges?: %d", result[i]);
    }
    
    // checking how many have converged
    for (i = 0; i < MAT_NUMBER; i++) {
        converged += result[i];
    }
    printf("\n\nConverged: %d\n", converged);

    return 0;
}


int if_converges(double a[MAT_SIZE][MAT_SIZE], double b[MAT_SIZE]) {

    double x[MAT_SIZE] = {0};   // current solution vector (from previous iteration)
    double y[MAT_SIZE] = {0};   // solution vector
    double y_prev = 0;
    int iter = MAX_ITER;
    int n = MAT_SIZE, i = 0, j = 0;
    int flag = 1;   // 1 -> values changing (keep iterating), 0 -> values not changing anymore
    int is_nan = 0;

 
    // iterating a loop for no of iterations or to the stop condition
    while (flag == 1 && iter > 0 && !is_nan)
    {
        flag = 0;

        // calculating each row of the matrix a
        // this loop is parallelizable in Jacobi method
        for (i = 0; i < n; i++)
        {
            y_prev = y[i];
            y[i] = (b[i] / a[i][i]);

            // calculating each coefficient of the solution vector y
            for (j = 0; j < n; j++)
            {
                if (j == i) {
                    continue;
                }
                y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
            }

            // checking if the solution goes to infinity
            if (y[i] != y[i]) {
                is_nan = 1;
            }

            // checking the precision of the solution
            if (fabs((y[i] - y_prev) > EPS)) {
                    flag = 1;
            }

            x[i] = y[i]; // move it outside both for loops to make it the Jacobi algorithm
        }
        iter--;
    }

    // printing the solution
    for (i = 0; i < n; i++) {
        printf("x%d = %f    ", i + 1, y[i]);
    }
    printf("\n");

    printf("\nIterations done: %d\n\n", MAX_ITER - iter);

    if (iter == 0 || is_nan) {
        return 0;
    }
    else {
        return 1;
    }
}


void randomize_mat(double a[MAT_SIZE][MAT_SIZE]) {

    for (int i = 0; i < MAT_SIZE; i++) {
        for (int j = 0; j < MAT_SIZE; j++) {
            a[i][j] = (double)rand() / (double)RAND_MAX;
            if (i == j) {
                if (a[i][j] > 0)
                    a[i][j] += 4;
                else
                    a[i][j] -= 4;
            }
            else if (i == j + 1 || i == j - 1 || i == j + 2 || i == j - 2) {
                if (a[i][j] > 0)
                    a[i][j] += 1;
                else
                    a[i][j] -= 1;
            }
        }
    }
}


void randomize_vec(double b[MAT_SIZE]) {

    for (int i = 0; i < MAT_SIZE; i++) {
        b[i] = (double)rand() / (double)RAND_MAX;
    }
}