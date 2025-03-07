#include <iostream>
#include <cmath>

using namespace std;

#define N 3
#define EPSILON 1e-6
#define MAX_ITER 100

void gaussSeidel(double A[N][N], double B[N], double X[N]) {
    double X_old[N];
    int iter = 0;
    
    while (iter < MAX_ITER) {
        for (int i = 0; i < N; i++) X_old[i] = X[i];
        
        for (int i = 0; i < N; i++) {
            double sum = B[i];
            for (int j = 0; j < N; j++) {
                if (i != j) sum -= A[i][j] * X[j];
            }
            X[i] = sum / A[i][i];
        }
        
        double error = 0;
        for (int i = 0; i < N; i++) error += fabs(X[i] - X_old[i]);
        if (error < EPSILON) break;
        
        iter++;
    }
}

int main() {
    double A[N][N] = {{4, -1, 0}, {-1, 4, -1}, {0, -1, 4}};
    double B[N] = {2, 6, 2};
    double X[N] = {0, 0, 0};

    gaussSeidel(A, B, X);

    for (int i = 0; i < N; i++) cout << "X[" << i << "] = " << X[i] << endl;

    return 0;
}

