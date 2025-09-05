#include<bits/stdc++.h>
using namespace std;
int len=100;
int a[len];
int front=0,rear=-1;
void enqueue(int x){
    if (rear==len-1){
        cout<<"queue is full"<<endl;
        return;
    }
    else{
        rear++;
        a[rear]=x;
    }
}
void dequeue(){
    if (rear<0 || front>=rear){
        cout<<"queue underflow "<<endl;
        return ;
    }
    front++;
}
bool isEmpty(){
    return front>rear;
}
bool isfull(){
    return rear==len-1;
}
void display(){
    if(isEmpty()) cout<<"queue is empty"<<endl;
    return ;
    cout<<"elements ff queue are:";
    else{
        for(int i=front;i<rear;i++){
            cout<<a[i]<<" ";
        }
        
    }
}
int main(){
    enqueue(10);
    enqueue(23);
    enqueue(11);
    enqueue(18);
    enqueue(13);
    enqueue(19);
    enqueue(1);
    enqueue(10);
    display();
    return 0;
}
