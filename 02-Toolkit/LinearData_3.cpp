//Stack via Linked List: Implement push and pop.
#include<iostream>
#include<climits>
using namespace std;
struct node{
    int key;
    node *next=nullptr;
};
void push(node*&head,int val){
    node*temp=new node({val});
    if(!head){
        head=temp;
        return;
    }
    temp->next=head;
    head=temp;
}
int pop(node*&head){
    if(!head){
        cout<<"not possible or underflow\n";
        return INT_MIN;
    }
    node *temp=head;
    head=head->next;
    int val=temp->key;
    delete temp;
    return val;
}
void display_stack(node *head){
    if(!head){
        cout<<"EMPTY STACK\n";
        return;
    }
    while(head){
        cout<<head->key<<" ";
        head=head->next;
    }
    cout<<"\n";
}
void clearStack(node*&head){
    while(head){
        node*temp=head;
        head=head->next;
        delete temp;
    }
}
int main() {
    node* head = nullptr;

    push(head, 10);
    push(head, 20);
    push(head, 30);

    display_stack(head); // 30 20 10

    cout << pop(head) << "\n"; // 30
    cout << pop(head) << "\n"; // 20
    cout << pop(head) << "\n"; // 10
    cout << pop(head) << "\n"; // underflow, returns INT_MIN

    display_stack(head); // EMPTY STACK

    clearStack(head); // optional cleanup
    return 0;
}