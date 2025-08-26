#include <iostream>
#include <cctype>  
using namespace std;
int main() {
    char ch;
    cout << "Enter a single character: ";
    cin >> ch;
    char lower_ch = tolower(ch);
    cout << "Lowercase character: " << lower_ch << endl;
    return 0;
}
