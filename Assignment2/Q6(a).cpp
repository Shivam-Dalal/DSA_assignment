#include <iostream>
using namespace std;

#define MAX 100

struct Sparse {
    int data[MAX][3]; // row, col, val
    int rows, cols, terms;
};

void readSparse(Sparse &s) {
    cout << "Enter rows, cols, non-zero terms: ";
    cin >> s.rows >> s.cols >> s.terms;

    cout << "Enter row, col, value for each non-zero element:\n";
    for (int i = 0; i < s.terms; i++) {
        cin >> s.data[i][0] >> s.data[i][1] >> s.data[i][2];
    }
}

void displaySparse(const Sparse &s) {
    cout << "Row Col Val\n";
    for (int i = 0; i < s.terms; i++) {
        cout << s.data[i][0] << "   "
             << s.data[i][1] << "   "
             << s.data[i][2] << endl;
    }
}

Sparse transpose(const Sparse &s) {
    Sparse t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.terms = s.terms;

    int k = 0;
    for (int col = 0; col < s.cols; col++) {
        for (int i = 0; i < s.terms; i++) {
            if (s.data[i][1] == col) {
                t.data[k][0] = s.data[i][1];
                t.data[k][1] = s.data[i][0];
                t.data[k][2] = s.data[i][2];
                k++;
            }
        }
    }
    return t;
}

int main() {
    Sparse a, result;

    cout << "Enter sparse matrix:\n";
    readSparse(a);

    cout << "\nOriginal matrix (triplet form):\n";
    displaySparse(a);

    result = transpose(a);

    cout << "\nTranspose (triplet form):\n";
    displaySparse(result);

    return 0;
}
