//insertion and deletion in RBtree
#include<iostream>
using namespace std;
enum COLOR{red,black};
struct node{
    int val;
    node* left,*parent,*right;
    COLOR color;
    node(int v){
        val=v;
        color=black;
        left=right=parent=nullptr;
    }
};
class RedBlack{
    public:
    node*root,*t_nil;
    node* getRoot() { return root; }
    RedBlack(){
        t_nil=new node(0);
        t_nil->color=black;
        t_nil->parent=t_nil->left=t_nil->right=t_nil;
        root=t_nil;
    }
    node* getNil() { return t_nil; }
    node* search(node* root, int val) {
        while (root != t_nil && root->val != val) {
            if (val < root->val) root = root->left;
            else root = root->right;
        }
        return root;
    }
    node*findmin(node*root){//when root is there
        node*curr=root;
        while(curr->left!=t_nil){
            curr=curr->left;
        }
        return curr;
    }
    void right_rotation(node*&root,node*&p){
        node*q=p->left;
        p->left=q->right;
        if(q->right!=t_nil) q->right->parent=p;
        q->parent=p->parent;
        if(p->parent==t_nil){
            root=q;
        }else if(p==p->parent->left){
            p->parent->left=q;
        }else{
            p->parent->right=q;
        }
        q->left=p;
        p->parent=q;
    }
    void left_rotation(node*&root,node*&q){
        node*p=q->right;
        q->right=p->left;
        if(p->left!=t_nil) p->left->parent=q;
        p->parent=q->parent;
        if(q->parent==t_nil) root=p;
        else if(q->parent->left==q) q->parent->left=p;
        else q->parent->right=p;
        p->left=q;
        q->parent=p;
    }
    void RB_insert(node*&root,int val){
        node*temp=new node(val);
        temp->left=temp->right=temp->parent=t_nil;
        temp->color=red;
        node*pre=t_nil;
        node*curr=root;
        while(curr!=t_nil){
            pre=curr;
            if(curr->val>val){
                curr=curr->left;
            }else{
                curr=curr->right;
            }
        }
        temp->parent=pre;
        if(pre==t_nil){
            root=temp;
            root->color=black;
            return;
        }
        else if(pre->val>val) pre->left=temp;
        else pre->right=temp;
        RB_insert_fixup(root,temp);        
    }
    void RB_insert_fixup(node*&root,node*&x){
        while(x->parent->color==red){
            if(x->parent==x->parent->parent->left){
                node*u=x->parent->parent->right;
                if(u->color==red){
                    u->color=black;
                    x->parent->color=black;
                    x->parent->parent->color=red;
                    x=x->parent->parent;
                }else{
                    if(x==x->parent->right){
                        x=x->parent;
                        left_rotation(root,x);
                    }
                    x->parent->color=black;
                    x->parent->parent->color=red;
                    right_rotation(root,x->parent->parent);
                }
            }else{
                node*u=x->parent->parent->left;
                if(u->color==red){
                    u->color=black;
                    x->parent->color=black;
                    x->parent->parent->color=red;
                    x=x->parent->parent;
                }else{
                    if(x==x->parent->left){
                        x=x->parent;
                        right_rotation(root,x);
                    }
                    x->parent->color=black;
                    x->parent->parent->color=red;
                    left_rotation(root,x->parent->parent);
                }
            }
        }
        root->color=black;
    }
    void transplant(node*&root,node*&s,node*&r){
        if(r!=t_nil)r->parent=s->parent;
        if(s->parent==t_nil)root=r;
        else if(s==s->parent->left)s->parent->left=r;
        else s->parent->right=r;
    }
    void RB_delete(node*&root,node*&z){
        node*y=z;
        node*x=t_nil;
        COLOR y_original_color=y->color;
        if(y->left==t_nil){
            x=y->right;
            transplant(root,z,z->right);
        }else if(y->right==t_nil){
            x=y->left;
            transplant(root,z,z->left);
        }
        else{
            y=findmin(z->right);
            y_original_color=y->color;
            x=y->right;
            if(y!=z->right){
                transplant(root,y,y->right);
                y->right=z->right;
                y->right->parent=y;
            }else{
                if(x!=t_nil) x->parent=y;
            }
            transplant(root,z,y);
            y->left=z->left;
            y->left->parent=y;
            y->color=z->color;
        }
        delete z;
        if(y_original_color==black){
            RB_delete_fixup(root,x);
        }
    }
    void RB_delete_fixup(node*&root,node*&x){
        while(x!=root &&x->color==black){
            if(x==x->parent->left){
                node*s=x->parent->right;
                if(s->color==red){
                    s->color=black;
                    x->parent->color=red;
                    left_rotation(root,x->parent);
                    s=x->parent->right;
                }else{
                    if(s->left->color==black&&s->right->color==black){
                        s->color=red;
                        x=x->parent;
                    }else{
                        if(s->right->color==black){
                            s->color=red;
                            s->left->color=black;
                            right_rotation(root,s);
                            s=x->parent->right;
                        }
                        s->color=x->parent->color;
                        x->parent->color=black;
                        s->right->color=black;
                        left_rotation(root,x->parent);
                        x=root;
                    }
                }
            }
            else{node*s=x->parent->left;
                if(s->color==red){
                    s->color=black;
                    x->parent->color=red;
                    right_rotation(root,x->parent);
                    s=x->parent->left;
                }else{
                    if(s->right->color==black&&s->left->color==black){
                        s->color=red;
                        x=x->parent;
                    }else{
                        if(s->left->color==black){
                            s->color=red;
                            s->right->color=black;
                            left_rotation(root,s);
                            s=x->parent->left;
                        }
                        s->color=x->parent->color;
                        x->parent->color=black;
                        s->left->color=black;
                        right_rotation(root,x->parent);
                        x=root;
                    }
                }
            }
        }
        x->color=black;
    }
    bool check_rr(node* root) {
        if (root == t_nil) return true;
        if (root->color == red &&(root->left->color == red || root->right->color == red)) return false;
        return check_rr(root->left) && check_rr(root->right);
    }
    int height_bal(node* root) {
        if (root == t_nil) return 1;
        int lh = height_bal(root->left);
        int rh = height_bal(root->right);
        if (lh == -1 || rh == -1 || lh != rh) return -1;
        return (root->color == black) ? lh + 1 : lh;
    }
    bool check__full(node* root) {
        if (root == t_nil) return true;  
        if (root->color != black) return false;
        return check_rr(root) && height_bal(root) != -1;
    }
    void inorder(node* root) {
        if (root == t_nil) return;
        inorder(root->left);
        cout << root->val << "(" << (root->color==red?"R":"B") << ") ";
        inorder(root->right);
    }
    void insert(int val) { RB_insert(root, val); }
    void remove(node* z) { RB_delete(root, z); }
    void cleanup(node* r) {
        if (r == t_nil) return;
        cleanup(r->left);
        cleanup(r->right);
        delete r;
}
~RedBlack() { cleanup(root); delete t_nil; }
};
int main() {
    RedBlack rb;
    rb.insert(10);
    rb.insert(20);
    rb.insert(30);
    rb.insert(15);

    cout << "Tree inorder: ";
    rb.inorder(rb.getRoot());
    cout << endl;

    node* z = rb.search(rb.getRoot(), 20);
    if (z != rb.getNil()) rb.remove(z);

    cout << "After deletion: ";
    rb.inorder(rb.getRoot());
    cout << endl;
}