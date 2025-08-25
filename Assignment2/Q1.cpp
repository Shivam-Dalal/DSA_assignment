#include<iostream>
using namespace std;
int binarysearch(int a[],int low, int high,int target){
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(a[mid]==target) return mid;
    else if(a[mid]>target) return binarysearch(a,low,mid-1,target);
    else return binarysearch(a,mid+1,high,target);
    // int low=0, high=n-1;
    // while(low<=high){
    //     int mid=low+high/2;
    //     if(a[mid]==target){
    //         int pos=mid;
    //         return pos;
    //     }
    //     else if(a[mid]<target){
    //         low=mid+1;
    //     }
    //     else high=mid-1;
    // }
    // return -1;
}
int main(){
    int n;
    cout<<"enter number of elements in array:";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int target;
    int low=0,high=n-1;
    cout<<"enter target element:";
    cin>>target;
    int index=binarysearch(a,low,high,target);
    if(index==-1)cout<<"element not found in array";
    else{ cout<<"element "<< target<<" found at index:"<<index;}
}
