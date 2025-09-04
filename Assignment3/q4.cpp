#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    return 0;
}
string infixToPostfix(string expr) {
    string result;
    stack<char> ops;
    for(char ch:expr){
        if(isalnum(ch)) result+=ch;
        else if(ch=='(') ops.push(ch);
        else if(ch==')'){
            while(!ops.empty() && ops.top()!='('){ result+=ops.top(); ops.pop(); }
            if(!ops.empty()) ops.pop();
        }
        else{
            while(!ops.empty() && precedence(ops.top())>=precedence(ch)){ result+=ops.top(); ops.pop(); }
            ops.push(ch);
        }
    }
    while(!ops.empty()){ result+=ops.top(); ops.pop(); }
    return result;
}
int main(){
    string expression;
    cout<<"Enter expression: ";
    getline(cin,expression);
    string postfix=infixToPostfix(expression);
    cout<<"Postfix: "<<postfix<<"\n";
}
