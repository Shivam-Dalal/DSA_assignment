#include <iostream>
using namespace std;

int main() {
    int arr[100];
    int n = 0;
    int num;

    while (true) {
        cout << "\nEnter a number (1-6):" << endl;
        cout << "1. Create array" << endl;
        cout << "2. Display array" << endl;
        cout << "3. Insert element" << endl;
        cout << "4. Delete element" << endl;
        cout << "5. Linear search" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> num;

        switch (num) {
            case 1: {
                cout << "Enter the size of the array: ";
                cin >> n;
                cout << "Enter " << n << " elements:" << endl;
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                break;
            }
            case 2: {
                if (n == 0) {
                    cout << "Array not created yet." << endl;
                } else {
                    cout << "Array elements are: ";
                    for (int i = 0; i < n; i++) {
                        cout << arr[i] << " ";
                    }
                    cout << endl;
                }
                break;
            }
            case 3: {
                if (n == 0) {
                    cout << "Array not created yet. Please create it first." << endl;
                    break;
                }
                int pos, element;
                cout << "Enter the index to insert (0 to " << n << "): ";
                cin >> pos;
                if (pos < 0 || pos > n) {
                    cout << "Invalid index!" << endl;
                    break;
                }
                cout << "Enter the element to insert: ";
                cin >> element;
                for (int i = n; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = element;
                n++;
                cout << "Updated array is: ";
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }
            case 4: {
                if (n == 0) {
                    cout << "Array not created yet." << endl;
                    break;
                }
                int pos;
                cout << "Enter the index to remove (0 to " << n - 1 << "): ";
                cin >> pos;
                if (pos < 0 || pos >= n) {
                    cout << "Invalid index!" << endl;
                    break;
                }
                for (int i = pos; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                cout << "Updated array is: ";
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }
            case 5: {
                if (n == 0) {
                    cout << "Array not created yet." << endl;
                    break;
                }
                int element;
                cout << "Enter the element to search: ";
                cin >> element;
                int pos1 = -1;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == element) {
                        pos1 = i;
                        break;
                    }
                }
                if (pos1 == -1) {
                    cout << "Element not found" << endl;
                } else{
                    cout << "Element found at index: " << pos1 << endl;
                }
                break;
            }
            case 6: {
                cout << "Exiting program." << endl;
                return 0;
            }
            default:
                cout << "Invalid choice! Please enter between 1 and 6." << endl;
        }
    }
    return 0;
}
