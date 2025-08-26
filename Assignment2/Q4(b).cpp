#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="cricket";
    for(auto it=s.end();it>s.begin();it--){
        cout<<*(it);
    }
    return 0;
}
