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
Sparse add(const Sparse &a, const Sparse &b) {
    Sparse c;
    if (a.rows != b.rows || a.cols != b.cols) {
        cout << "Addition not possible!\n";
        c.terms = 0;
        return c;
    }

    c.rows = a.rows;
    c.cols = a.cols;

    int i = 0, j = 0, k = 0;
    while (i < a.terms && j < b.terms) {
        if (a.data[i][0] < b.data[j][0] ||
           (a.data[i][0] == b.data[j][0] && a.data[i][1] < b.data[j][1])) {
            c.data[k][0] = a.data[i][0];
            c.data[k][1] = a.data[i][1];
            c.data[k][2] = a.data[i][2];
            i++; k++;
        }
        else if (b.data[j][0] < a.data[i][0] ||
                (b.data[j][0] == a.data[i][0] && b.data[j][1] < a.data[i][1])) {
            c.data[k][0] = b.data[j][0];
            c.data[k][1] = b.data[j][1];
            c.data[k][2] = b.data[j][2];
            j++; k++;
        }
        else { // same row,col
            int sum = a.data[i][2] + b.data[j][2];
            if (sum != 0) {
                c.data[k][0] = a.data[i][0];
                c.data[k][1] = a.data[i][1];
                c.data[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }

    while (i < a.terms) {
        c.data[k][0] = a.data[i][0];
        c.data[k][1] = a.data[i][1];
        c.data[k][2] = a.data[i][2];
        i++; k++;
    }
    while (j < b.terms) {
        c.data[k][0] = b.data[j][0];
        c.data[k][1] = b.data[j][1];
        c.data[k][2] = b.data[j][2];
        j++; k++;
    }

    c.terms = k;
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

    result = add(a, b);

    cout << "\nSum (triplet form):\n";
    displaySparse(result);

    return 0;
}
