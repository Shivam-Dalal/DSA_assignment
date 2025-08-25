#include <iostream>
using namespace std;
int main() {
    int rows, cols;
    cout << "enter number of rows: ";
    cin >> rows;
    cout << "enter number of columns: ";
    cin >> cols;
    int matrix[100][100]; 
    cout << "enter elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "\nrow sums:" << endl;
    for (int i = 0; i < rows; i++) {
        int rowsum = 0;
        for (int j = 0; j < cols; j++) {
            rowsum += matrix[i][j];
        }
        cout << "Row"<< i + 1<<" sum = " << rowSum << endl;
    }
    cout << "\nColumn sums:" << endl;
    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += matrix[i][j];
        }
        cout << "Column " << j + 1 << " sum = " << colSum << endl;
    }
    return 0;
}
