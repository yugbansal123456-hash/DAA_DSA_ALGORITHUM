#include<iostream>
#include<vector>
#include<climits>
#include <stdexcept>
#include <algorithm> 
using namespace std;
//priority queue
struct obj{
    int value;
    int key;
    obj(int v,int k){value=v;key=k;}
    obj() { value=0; key=0; }
};
int Max_Heap_Maximum(vector <obj> &p,int &heapsize){
    if(heapsize<1){
        throw underflow_error("heap underflow");
    }
    return p[1].value;
}
void Max_Heapyfy(vector <obj> &p,int i,int &heapsize){
    int lc=2*i,rc=2*i+1,largest=i;
    if(lc<=heapsize &&p[lc].key>p[i].key){largest=lc;}
    if(rc<=heapsize &&p[largest].key<p[rc].key){largest=rc;}
    if(largest!=i){
        swap(p[largest],p[i]);
        Max_Heapyfy(p,largest,heapsize);
    }
}
int Max_Heap_Extract(vector <obj> &p,int &heapsize){
    if(heapsize<1){
        throw underflow_error("heap underflow");
    }
    int max=Max_Heap_Maximum(p,heapsize);
    swap(p[1],p[heapsize]);
    heapsize=heapsize-1;
    Max_Heapyfy(p,1,heapsize);
    return max;

}
void Max_Heap_Increase(vector <obj> &p,int index,int k,int &heapsize){
    int x=index;
    if(x<=heapsize &&p[x].key<k){
        p[x].key=k;
    }else{
        return;
    }
    while(x>1 &&p[x].key>p[(x/2)].key){
        swap(p[x],p[x/2]);
        x=x/2;
    }
}
void Max_Heap_Insert(vector <obj> &p,obj x,int &heapsize){
    if(heapsize==(int)p.size()-1){
        throw overflow_error("heap overflow");
    }
    heapsize=heapsize+1;
    int k=x.key;
    x.key=INT_MIN;
    p[heapsize]=x;
    Max_Heap_Increase(p,heapsize,k,heapsize);
}
int main() {
    int maxCapacity = 10;
    vector<obj> pq(maxCapacity + 1); // +1 for dummy at index 0
    int heapsize = 0;
    Max_Heap_Insert(pq, obj(42, 15), heapsize);
    Max_Heap_Insert(pq, obj(99, 30), heapsize);
    Max_Heap_Insert(pq, obj(17, 10), heapsize);

    cout << "Max value: " << Max_Heap_Maximum(pq, heapsize) << endl;
    cout << "Extracted: " << Max_Heap_Extract(pq, heapsize) << endl;
    cout << "New max: " << Max_Heap_Maximum(pq, heapsize) << endl;
    return 0;
}