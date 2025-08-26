#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    vector<string> strings(n);
    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }
    sort(strings.begin(), strings.end());
    cout << "\nStrings in alphabetical order:" << endl;
    for (int i = 0; i < n; i++) {
        cout << strings[i] << endl;
    }

    return 0;
}
