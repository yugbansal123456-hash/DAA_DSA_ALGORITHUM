struct node{
    int k;
    node*next=nullptr;
};
class MinStack {
public:
node*head=nullptr;
vector<int>ml;
    MinStack() {
        
    }
    
    void push(int val) {
        if(!head){
            head=new node({val});
            ml.push_back(val);
            return;
        }
        node*temp=new node({val});
        temp->next=head;
        head=temp;
        if(ml.back()>=val){
            ml.push_back(val);
        }
    }
    
    void pop() {
        if(head->k==ml.back()){ml.pop_back();}
        node*temp=head;
        head=head->next;
        delete temp;
    }
    
    int top() {
        return head->k;
    }
    
    int getMin() {
        return ml.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MinStack {
public:
vector<pair<int,int>>v;
    MinStack() {
        
    }
    
    void push(int val) {
        if(v.empty()){
            v.push_back({val,val});
            return;
        }
        v.push_back({val,min(v.back().second,val)});
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MinStack {
public:
stack<int>s;
stack<int>ms;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(ms.empty()||val<=ms.top()){
            ms.push(val);
        }
    }
    
    void pop() {
        if(ms.top()==s.top()){
            ms.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */