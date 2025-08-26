#include <iostream>
using namespace std;

#define MAX 100

struct Sparse {
    int data[MAX][3];
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

Sparse multiply(const Sparse &a, const Sparse &b) {
    Sparse c;
    if (a.cols != b.rows) {
        cout << "Multiplication not possible!\n";
        c.terms = 0;
        return c;
    }

    c.rows = a.rows;
    c.cols = b.cols;
    c.terms = 0;

    Sparse bt = transpose(b);

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            int sum = 0;
            for (int p = 0; p < a.terms; p++) {
                if (a.data[p][0] == i) {
                    for (int q = 0; q < bt.terms; q++) {
                        if (bt.data[q][0] == j && bt.data[q][1] == a.data[p][1]) {
                            sum += a.data[p][2] * bt.data[q][2];
                        }
                    }
                }
            }
            if (sum != 0) {
                c.data[c.terms][0] = i;
                c.data[c.terms][1] = j;
                c.data[c.terms][2] = sum;
                c.terms++;
            }
        }
    }
    return c;
}

int main() {
    Sparse a, b, result;

    cout << "Enter first sparse matrix:\n";
    readSparse(a);
    cout << "Enter second sparse matrix:\n";
    readSparse(b);

    cout << "\nFirst matrix:\n";
    displaySparse(a);
    cout << "\nSecond matrix:\n";
    displaySparse(b);

    result = multiply(a, b);

    cout << "\nProduct (triplet form):\n";
    displaySparse(result);

    return 0;
}
