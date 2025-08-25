#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"input size of array: ";
    cin>>n;
    int a[n];
    cout<<"enter matrix elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"reverse of array: ";
    n--;
    for(int i=n;i>=0;i--){
        cout<<a[i]<<" ";
    }
    return 0;
}
