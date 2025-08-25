#include<iostream>
using namespace std;
int main(){
    int n,m,p;
    cin>>(cout<<"enter values of n:",n),cin>>(cout<<"enter values of m:",m),cin>>(cout<<"enter values of p:",p);
    int a[n][m],b[m][p],c[n][p];
    cout<<"enter elements of matrix a:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    cout<<"\nenter elements of matrix b:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            cin>>b[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            c[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            for(int k=0;k<m;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    cout << "Resultant Matrix C (A x B):\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
