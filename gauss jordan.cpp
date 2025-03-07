#include <iostream>
using namespace std;

void GaussJordan(float a[10][10], float b[10], float x[10], int n) {
    for (int i = 0; i < n; i++) {
        float pivot = a[i][i];
        for (int j = 0; j < n; j++) {
            a[i][j] /= pivot;
        }
        b[i] /= pivot;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                float ratio = a[j][i];
                for (int k = 0; k < n; k++) {
                    a[j][k] -= ratio * a[i][k];
                }
                b[j] -= ratio * b[i];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        x[i] = b[i];
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
    GaussJordan(a, b, x, n);
    cout << "The solution is:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
    return 0;
}

