#include<iostream>
using namespace std;
int missing(int n,int a[]){
    int left= 0,right=n-2;
    while(left <= right){
        int mid = (left + right)/2;
        if (a[mid]== mid + 1) left = mid + 1;
        else
            right = mid - 1;
    return left + 1;
    }
}

int main(){
    int n=7;
    int a[n-1]={1,2,3,5,6,7};
    cout<<"the missing number is :"<<missing(n,a)<<endl;
    return 0;
}
