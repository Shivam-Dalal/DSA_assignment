#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evalPostfix(string expr) {
    stack<int> st;
    for(char ch : expr) {
        if(isdigit(ch)) st.push(ch - '0'); 
        else {
            int b=st.top(); st.pop();
            int a=st.top(); st.pop();
            if(ch=='+') st.push(a + b);
            else if(ch=='-') st.push(a-b);
            else if(ch=='*') st.push(a*b);
            else if(ch =='/') st.push(a/b);
        }
    }
    return st.top();
}
int main(){
    string expr;
    cout<<"Enter postfix expression:";
    getline(cin, expr);
    int result = evalPostfix(expr);
    cout<<"Result: "<<result<<"\n";
}
