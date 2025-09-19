#include<iostream>
using namespace std;
#define SIZE 100
class CircularQueue_Implementation{
private:
    int c_qu[SIZE];
    int front,rear;
public:
    CircularQueue_Implementation(){
        front=-1;
        rear=-1;
    }
    void enqueue(int element){
        if(isFull()){
            cout<<"queue is overflowed\n";
            return;
        }
        rear=(rear+1)%SIZE;
        c_qu[rear]=element;
        if(front==-1) front=0;
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"queue is underflowed\n";
            return;
        }
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else front=(front+1)%SIZE;
    }
    bool isEmpty(){
        return front==-1;
    }
    bool isFull(){
        return (rear+1)%SIZE==front;
    }
    int peek(){
        if(isEmpty()){
            cout<<"queue is empty\n";
            return -1;
        }
        return c_qu[front];
    }
    void display(){
        if(isEmpty()){
            cout<<"queue is empty\n";
            return;
        }
        cout<<"queue elements: ";
        int i=front;
        while(true){
            cout<<c_qu[i]<<" ";
            if(i==rear) break;
            i=(i+1)%SIZE;
        }
        cout<<endl;
    }
};
int main(){
    CircularQueue_Implementation q1;
    int choice=0;
    while(choice!=7){
        cout<<"Enter\n";
        cout<<"1. enqueue\n";
        cout<<"2. dequeue\n";
        cout<<"3. is Empty\n";
        cout<<"4. is Full\n";
        cout<<"5. display\n";
        cout<<"6. peek\n";
        cout<<"7. to exit\n";
        cin>>choice;
        switch(choice){
            case 1:{
                int element;
                cout<<"Enter the element you want for enqueue:";
                cin>>element;
                q1.enqueue(element);
                break;
            }
            case 2:
                q1.dequeue();
                break;
            case 3:
                cout<<(q1.isEmpty()?"queue is EMPTY":"queue is NOT empty")<<endl;
                break;
            case 4:
                cout<<(q1.isFull()?"queue is FULL":"queue is NOT full")<<endl;
                break;
            case 5:
                q1.display();
                break;
            case 6:
                cout<<"front element: "<<q1.peek()<<endl;
                break;
        }
    }
    return 0;
}
