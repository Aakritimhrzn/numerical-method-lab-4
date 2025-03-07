#include <iostream>
#include <cmath>

using namespace std;

#define N 3
#define EPSILON 1e-6
#define MAX_ITER 100

void powerMethod(double A[N][N], double eigenVector[N], double &eigenValue) {
    double prevEigenValue = 0, norm;
    int iter = 0;

    for (int i = 0; i < N; i++) eigenVector[i] = 1;

    while (iter < MAX_ITER) {
        double tempVector[N] = {0};

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                tempVector[i] += A[i][j] * eigenVector[j];

        norm = fabs(tempVector[0]);
        for (int i = 1; i < N; i++)
            if (fabs(tempVector[i]) > norm)
                norm = fabs(tempVector[i]);

        for (int i = 0; i < N; i++)
            eigenVector[i] = tempVector[i] / norm;

        eigenValue = norm;

        if (fabs(eigenValue - prevEigenValue) < EPSILON) break;

        prevEigenValue = eigenValue;
        iter++;
    }
}

int main() {
    double A[N][N] = {{4, 1, 2}, {1, 3, 0}, {2, 0, 5}};
    double eigenVector[N];
    double eigenValue = 0;

    powerMethod(A, eigenVector, eigenValue);

    cout << "Dominant Eigenvalue: " << eigenValue << endl;
    cout << "Eigenvector: ";
    for (int i = 0; i < N; i++) cout << eigenVector[i] << " ";
    cout << endl;

    return 0;
}

