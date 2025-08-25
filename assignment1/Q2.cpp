#include<iostream>
using namespace std;
int main(){
    int a[]={2,3,5,2,4};
    int n =sizeof(a)/sizeof(a[0]);
    bool visited[n]={false};
    for(int i=0;i<n;i++){
        bool duplicate=false;
        if(visited[i]==true)
            continue;
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                visited[j]=true;
                duplicate=true;
            }
        }
        if(duplicate)
            cout<<a[i]<<" is duplicate in the array\n";
    }
    cout << "Unique elements:\n";
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << a[i] << " ";
        }
    }
    return 0;
}
