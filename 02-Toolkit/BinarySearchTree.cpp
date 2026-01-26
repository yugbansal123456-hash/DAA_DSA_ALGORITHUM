//You are building a manual BST class using raw pointers (no std::vector for the internal structure).
//Structural Logic: Implement Node struct and insert(key).
//Navigation: Implement find(key), findMin(), findMax(), successor(node), and predecessor(node).
//The Hard Part: Implement remove(key). Handle the "Successor Swap" logic perfectly.
//Traversals: Implement Inorder, Preorder, and Postorder recursively.
//Rule: Manage new and delete manually. Every insert must have a corresponding delete in your clear() 
//or destructor to avoid memory leaks.
#include<iostream>
#include<stack>
using namespace std;
struct node{
    int val;
    node*left=nullptr;
    node*right=nullptr;
    node*parent=nullptr;
};
void insert(node*&root,int key){
    node*temp=new node({key});
    node*curr=root;
    node*pre=nullptr;
    while(curr!=nullptr){
        pre=curr;
        if(curr->val>key) curr=curr->left;
        else curr=curr->right;
    }
    temp->parent=pre;
    if(pre==nullptr){
        root=temp;
    }
    else if(pre->val>key){
        pre->left=temp;
    }else {
        pre->right=temp;
    }
}
node* find(node*root,int key){
    node* curr=root;
    if(curr==nullptr || curr->val==key){
        return curr;
    }
    while(curr!=nullptr &&curr->val!=key){
        if(key < curr->val){
            curr=curr->left;
        }else{
            curr=curr->right;
        }
    }
    return curr;
}
node* findMin(node*root){
    if(root==nullptr){
        return root;
    }
    while(root->left!=nullptr){
        root=root->left;
    }
    return root;
}
node* findMax(node*root){
    if(root==nullptr){
        return root;
    }
    while(root->right!=nullptr){
        root=root->right;
    }
    return root;
}
node* successor(node*root){
    if(root->right!=nullptr ){
        return findMin(root->right);
    }else{
        node*p=root->parent;
        while(p!=nullptr && p->right==root){
            root=p;
            p=p->parent;
        }
        return p;
    }
}
node* predecessor(node*root){
    if(root->left!=nullptr ){
        return findMax(root->left);
    }else{
        node*p=root->parent;
        while(p!=nullptr&&p->left==root){
            root=p;
            p=p->parent;
        }
        return p;
    }
}
void InorderWalk(node*root){
    if(root==nullptr) return;
    InorderWalk(root->left);
    cout<<root->val<<" ";
    InorderWalk(root->right);
}
void PostorderWalk(node*root){
    if(root==nullptr) return;
    PostorderWalk(root->left);
    PostorderWalk(root->right);
    cout<<root->val<<" ";
}
void PreorderWalk(node*root){
    if(root==nullptr) return;
    cout<<root->val<<" ";
    PreorderWalk(root->left);
    PreorderWalk(root->right);
}
void Transplant(node*&root,node*&s,node*&t){
    if(s->parent==nullptr) root=t;
    else if(s->parent->left==s) s->parent->left=t;
    else s->parent->right=t;
    if(t!=nullptr) t->parent=s->parent;
}
void remove(node*&root,int key){
    node*curr=find(root,key);
    if(curr==nullptr){return;}
    if(curr->left==nullptr) Transplant(root,curr,curr->right);//0 child as well as single right child case
    else if(curr->right==nullptr) Transplant(root,curr,curr->left);//single right child case
    else{
        node* exp=findMin(curr->right);
        if(curr->right!=exp){
            Transplant(root,exp,exp->right);
            exp->right=curr->right;
            exp->right->parent=exp;
        }
        Transplant(root,curr,exp);
        exp->left=curr->left;
        exp->left->parent=exp;
    }
    delete curr;
}
void cleanup(node*&root){
    if(root==nullptr) return ;//postorder requied as when deleted it has no child
    cleanup(root->left);
    cleanup(root->right);
    delete root;
    root=nullptr;
}
void cleanup_stack(node*&root){
    if(root==nullptr) return;
    stack<node*>st1,st2;
    st1.push(root);
    node*curr=root;
    while(!st1.empty()){
        curr=st1.top();
        st2.push(st1.top());
        st1.pop();
        if(curr->left) st1.push(curr->left);
        if(curr->right) st1.push(curr->right);
    }
    while(!st2.empty()){
        curr=st2.top();
        st2.pop();
        delete curr;
    }
    root=nullptr;
}
int main() {
    node* root = nullptr;

    // Insert nodes
    insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder: ";
    InorderWalk(root);
    cout << "\nPreorder: ";
    PreorderWalk(root);
    cout << "\nPostorder: ";
    PostorderWalk(root);
    cout << "\n";

    // Find and navigation
    node* n40 = find(root, 40);
    if (n40) {
        cout << "Successor of 40: " << successor(n40)->val << "\n";
        cout << "Predecessor of 40: " << predecessor(n40)->val << "\n";
    }

    // Remove a node
    cout << "Removing 30...\n";
    remove(root, 30);
    cout << "Inorder after removal: ";
    InorderWalk(root);
    cout << "\n";

    // Cleanup
    cleanup(root);
    cout << "Tree cleaned up.\n";

    return 0;
}