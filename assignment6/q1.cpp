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
        while(temp->next!=temp){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }
    void delete_cll(int val){
        node* temp=head;
        while(temp->next!=val){
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
    return 0;
}
