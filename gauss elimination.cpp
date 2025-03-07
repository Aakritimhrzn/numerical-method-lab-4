#include <iostream>
using namespace std;

void GaussElimination(float a[10][10], float b[10], float x[10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            float ratio = a[j][i] / a[i][i];
            for (int k = 0; k < n; k++) {
                a[j][k] -= ratio * a[i][k];
            }
            b[j] -= ratio * b[i];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
}

int main() {
    int n;
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
    GaussElimination(a, b, x, n);
    cout << "The solution is:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
    return 0;
}

