#include <iostream>
using namespace std;

void setSymmetric(int A[], int n, int i, int j, int x) {
    if (i >= j) A[i*(i-1)/2 + (j-1)] = x;
    else A[j*(j-1)/2 + (i-1)] = x;
}

int getSymmetric(int A[], int n, int i, int j) {
    if (i >= j) return A[i*(i-1)/2 + (j-1)];
    else return A[j*(j-1)/2 + (i-1)];
}

void displaySymmetric(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << getSymmetric(A, n, i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;

    int *A = new int[n*(n+1)/2];

    cout << "Enter elements row-wise:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            setSymmetric(A, n, i, j, x);
        }
    }

    cout << "\nSymmetric Matrix:\n";
    displaySymmetric(A, n);

    delete[] A;
    return 0;
}
