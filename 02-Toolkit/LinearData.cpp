//Description: You are building three structures from scratch using raw pointers.
//Doubly Linked List: Implement insertAtHead, deleteNode, and find.
//Circular Queue: Implement using a fixed-size array. You must handle the "Wrap-Around" logic using the modulo operator.
//Stack via Linked List: Implement push and pop.
//Rule: Do not use std::list, std::stack, or std::queue. 
//You must manage new and delete manually. 
//Use the VS Code debugger to verify there are zero memory leaks.
#include <iostream>
using namespace std;

struct node {
    int key;
    node* prev = nullptr;
    node* next = nullptr;
};
void insertAtHead(node*& head, int val) {
    node* temp = new node({val});
    if (head) {
        temp->next = head;
        head->prev = temp;
    }
    head = temp;
}
void deleteNode(node*& head, int val) {
    if (!head) {
        cout << "list empty\n";
        return;
    }
    node* curr = head;
    while (curr) {
        if (curr->key == val) {
            if (curr->prev) curr->prev->next = curr->next;
            else head = curr->next;  
            if (curr->next) curr->next->prev = curr->prev;
            delete curr;
            cout << "value deleted from list\n";
            return;
        }
        curr = curr->next;
    }
    cout << "value not found in list\n";
}
void find(node* head, int val) {
    node* curr = head;
    while (curr) {
        if (curr->key == val) {
            cout << "found\n";
            return;
        }
        curr = curr->next;
    }
    cout << "not found\n";
}
void display(node* head) {
    node* curr = head;
    while (curr) {
        cout << curr->key << " ";
        curr = curr->next;
    }
    cout << "\n";
}
void reverse_display(node* head) {
    if (!head) {
        cout << "list empty\n";
        return;
    }
    node* curr = head;
    while (curr->next) {
        curr = curr->next;  // move to tail
    }
    while (curr) {
        cout << curr->key << " ";
        curr = curr->prev;
    }
    cout << "\n";
}
void clearData(node*& head) {
    while (head) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr; 
}
int main() {
    node* head = nullptr;

    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);

    cout << "Forward: ";
    display(head);        // 30 20 10

    cout << "Reverse: ";
    reverse_display(head); // 10 20 30

    find(head, 20);       // found
    deleteNode(head, 20); // value deleted from list
    find(head, 20);       // not found
    deleteNode(head, 40); // value not found in list

    cout << "Forward after deletions: ";
    display(head);        // 30 10

    clearData(head);
    if (!head) cout << "List cleared successfully\n";

    return 0;
}