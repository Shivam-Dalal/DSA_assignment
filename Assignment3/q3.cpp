#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool chk(string s) {
    stack<char> st;
    for (char c : s) {
        if (c=='('||c=='['||c=='{') st.push(c);
        else if (c==')'||c==']'||c=='}') {
            if (st.empty()) return false;
            char t = st.top(); st.pop();
            if ((c==')'&&t!='(')||(c==']'&&t!='[')||(c=='}'&&t!='{')) return false;
        }
    }
    return st.empty();
}

int main() {
    string x;
    cout<<"Enter the expression: ";
    getline(cin,x);
    if (chk(x)) cout <<"expression was ok\n";
    else cout<<"wrong use of parenthisiss\n";
}
