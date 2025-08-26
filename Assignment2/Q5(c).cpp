#include <iostream>
using namespace std;

void setLower(int A[], int n, int i, int j, int x) {
    if (i >= j) A[i*(i-1)/2 + (j-1)] = x;
}

int getLower(int A[], int n, int i, int j) {
    if (i >= j) return A[i*(i-1)/2 + (j-1)];
    return 0;
}

void displayLower(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << getLower(A, n, i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of lower triangular matrix: ";
    cin >> n;

    int *A = new int[n*(n+1)/2];

    cout << "Enter elements row-wise:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            setLower(A, n, i, j, x);
        }
    }

    cout << "\nLower Triangular Matrix:\n";
    displayLower(A, n);

    delete[] A;
    return 0;
}
