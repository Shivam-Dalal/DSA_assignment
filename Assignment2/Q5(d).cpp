#include <iostream>
using namespace std;

void setUpper(int A[], int n, int i, int j, int x) {
    if (i <= j) A[n*(i-1) - (i-2)*(i-1)/2 + (j-i)] = x;
}

int getUpper(int A[], int n, int i, int j) {
    if (i <= j) return A[n*(i-1) - (i-2)*(i-1)/2 + (j-i)];
    return 0;
}

void displayUpper(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << getUpper(A, n, i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;

    int *A = new int[n*(n+1)/2];

    cout << "Enter elements row-wise:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            setUpper(A, n, i, j, x);
        }
    }

    cout << "\nUpper Triangular Matrix:\n";
    displayUpper(A, n);

    delete[] A;
    return 0;
}
