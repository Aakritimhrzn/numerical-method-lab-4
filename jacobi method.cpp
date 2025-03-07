#include <iostream>
#include <cmath>
using namespace std;

void JacobiMethod(float a[10][10], float b[10], float x[10], int n, int maxIterations, float tolerance) {
    float x_new[10];
    for (int i = 0; i < n; i++) {
        x_new[i] = 0;
    }

    for (int iter = 0; iter < maxIterations; iter++) {
        for (int i = 0; i < n; i++) {
            float sum = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += a[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / a[i][i];
        }

        bool isConverged = true;
        for (int i = 0; i < n; i++) {
            if (fabs(x_new[i] - x[i]) > tolerance) {
                isConverged = false;
                break;
            }
        }

        if (isConverged) {
            break;
        }

        for (int i = 0; i < n; i++) {
            x[i] = x_new[i];
        }
    }

    for (int i = 0; i < n; i++) {
        x[i] = x_new[i];
    }
}

int main() {
    int n, maxIterations;
    float tolerance;
    float a[10][10], b[10], x[10];

    cout << "Enter the number of variables: ";
    cin >> n;

    cout << "Enter the coefficients of the augmented matrix (A|B):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
        cin >> b[i];
    }

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    cout << "Enter the tolerance for convergence: ";
    cin >> tolerance;

    for (int i = 0; i < n; i++) {
        x[i] = 0;  // Initial guess
    }

    JacobiMethod(a, b, x, n, maxIterations, tolerance);

    cout << "The solution is:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}

