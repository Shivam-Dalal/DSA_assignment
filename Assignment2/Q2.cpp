#include<iostream>
using namespace std;
void linearsearch(int a[],int n, int target,bool &found)
{
    for(int i=0;i<n;i++){
        if(a[i]==target){
            int pos=i;
            cout<<"element "<<target<<"found at position "<<pos+1<<"\n";
            found=true;
        }
    }
}
int countoccurences(int n,int a[],int target){
    int count=0;
    for (int i=0;i<n;i++){
        if(a[i]==target) count++;
    }
    return count;
}
int main(){
    bool found=false;
    int n;
    cout<<"enter number of elements in array:";
    cin>>n;
    cout<<"enter array elements:";
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int target;
    cout<<"enter element to search:";
    cin>>target;
    linearsearch(a,n,target,found);
    if(!found) cout<<"element not found in array";
    else {
        // cout<<"element "<<target<<" found at pos:"<<pos+1;
        cout<<"element "<<target<<" was repeated "<<countoccurences(n,a,target)<<" times";
    }
    return 0;
}
