#include<iostream>
#include<stack>
using namespace std;

#define len 100
char stack[len];
int top=-1;
void push(char ch){
    if(top<len-1){
        stack[++top]=ch;
        return;
    }
    cout<<"stack overflow"<<endl;
}
void pop(){
    if(top<0) cout<<"stack underflow\n";
    return stack[top--];
}
void reverse_string(char str[]){
    int n=strlen(str);
    for(int i=0;i<n;i++){
        push(str[i]);
    }
    for(int i=0;i<n;i++){
        str[i]=pop();
    }
}
int main(){
    char str[len];
    cout<<"enter a string:";
    cin.getline(str,len);
    return 0;
}
