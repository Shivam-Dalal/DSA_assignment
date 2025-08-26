#include<iostream>
using namespace std;
int missing(int n,int a[]){
    for(int i=0;i<n-1;i++){
        if(a[i]!=i+1) return i+1;
    }
    return n;
}

int main(){
    int n=7;
    int a[n-1]={1,2,3,5,6,7};
    cout<<"the missing number is :"<<missing(n,a)<<endl;
    return 0;
}
