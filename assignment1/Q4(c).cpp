#include<iostream>
using namespace std;
int main(){
    int a[3][3]={
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int rows=3;int cols=3;
    for(int j=0;j<cols;j++){
        for (int i=0;i<rows;i++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
