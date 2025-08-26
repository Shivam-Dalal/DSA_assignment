#include <iostream>
using namespace std;

void setTridiagonal(int A[], int n, int i, int j, int x) {
    if (i - j == 1) A[i-2] = x;              
    else if (i == j) A[n-1 + i-1] = x;           
    else if (i - j == -1) A[2*n -1 + i-1] = x;   
}

int getTridiagonal(int A[], int n, int i, int j) {
    if (i - j == 1) return A[i-2];
    else if (i == j) return A[n-1 + i-1];
    else if (i - j == -1) return A[2*n -1 + i-1];
    else return 0;
}

void displayTridiagonal(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << getTridiagonal(A, n, i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;

    int *A = new int[3*n - 2];

    cout << "Enter elements row-wise:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            setTridiagonal(A, n, i, j, x);
        }
    }

    cout << "\nTri-diagonal Matrix:\n";
    displayTridiagonal(A, n);

    delete[] A;
    return 0;
}
