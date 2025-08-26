#include <iostream>
using namespace std;

void setDiagonal(int A[], int n, int i, int j, int x) {
    if (i == j) A[i-1] = x;
}

int getDiagonal(int A[], int n, int i, int j) {
    if (i == j) return A[i-1];
    return 0;
}

void displayDiagonal(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << getDiagonal(A, n, i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of diagonal matrix: ";
    cin >> n;

    int *A = new int[n];

    cout << "Enter diagonal elements: ";
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        setDiagonal(A, n, i, i, x);
    }

    cout << "\nDiagonal Matrix:\n";
    displayDiagonal(A, n);

    delete[] A;
    return 0;
}
