#include <iostream>
#include <set>
using namespace std;
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }
    cout << "Number of distinct elements: " <<s.size() << endl;

    return 0;
}
