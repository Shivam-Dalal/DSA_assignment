#include<iostream>
using namespace std;
class node {
public:
    int data;
    node* next;
    
    node(int val){
        data = val;
        next=NULL;
    }
};
class circularll{
    node* head;
    public:
    circularll() {
        head=NULL;
    }

    void insertAtBeginning(int val) {
        node* newnode = new node(val);
        if (head==NULL) {
            newnode->next = newnode;
            head = newnode;
            return;
        }
        node* temp = head;
        while (temp->next!=head)
            temp = temp->next;

        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
    void insertatend(int val){
        node* newnode=new node(val);
        if(head==NULL){
            newnode->next=newnode;
            head=newnode;
            return ;
        }
        node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }
    void insertAtPosition(int val, int pos) {
        if(pos< 1) {
            cout<<"Invalid position.\n";
            return;
        }

        if (pos == 1) {
            insertAtBeginning(val);
            return;
        }

        node* newnode = new node(val);
        node* temp =head;
        int count=1;
        while(count<pos-1 && temp->next!=head) {
            temp = temp->next;
            count++;
        }
        if(count!=pos-1) {
            cout<<"Position out of range. Inserting at end.\n";
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    void delete_cll(int val){
        node* temp=head;
        while(temp->data!=val){
            temp=temp->next;
        }

    }
    void display() {
        if (head==NULL) {
            cout<<"list is empty\n";
            return;
        }
        node* temp = head;
        do {
            cout << temp->data<<"-> ";
            temp=temp->next;
        } while (temp!= head);
        cout<<"(head)\n";
    }
};
int main(){
    circularll cll;
    cll.insertAtBeginning(2);
    cll.insertAtBeginning(3);
    cll.insertAtBeginning(1);
    cll.insertatend(2);
    cll.display();
    cll.insertatend(4);
    cll.display();
    cll.insertAtPosition(7,3);
    cll.display();
    return 0;
}
