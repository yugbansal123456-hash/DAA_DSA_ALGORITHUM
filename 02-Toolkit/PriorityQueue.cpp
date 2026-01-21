#include<iostream>
#include<vector>
#include<climits>
#include <stdexcept>
#include <algorithm> 
using namespace std;
#pragma warning(disable:XXXX)   // MSVC
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


//Carefull observe major issues and advantages
#include <iostream>
#include <vector>
#include <climits>
#include <stdexcept>
using namespace std;

struct obj {
    int value;
    int key;
    obj(int v,int k){ value=v; key=k; }
    obj() { value=0; key=0; }
};

// Max at root
int Max_Heap_Maximum(vector<obj> &p) {
    if (p.size() <= 1) { // index 0 is dummy
        throw underflow_error("heap underflow");
    }
    return p[1].value;
}

void Max_Heapyfy(vector<obj> &p,int i) {
    int heapsize = (int)p.size() - 1;
    int lc = 2*i, rc = 2*i+1, largest = i;
    if (lc <= heapsize && p[lc].key > p[i].key) largest = lc;
    if (rc <= heapsize && p[rc].key > p[largest].key) largest = rc;
    if (largest != i) {
        swap(p[largest], p[i]);
        Max_Heapyfy(p, largest);
    }
}

int Max_Heap_Extract(vector<obj> &p) {
    if (p.size() <= 1) {
        throw underflow_error("heap underflow");
    }
    int max = Max_Heap_Maximum(p);
    swap(p[1], p.back());
    p.pop_back();
    if (p.size() > 1) Max_Heapyfy(p, 1);
    return max;
}

void Max_Heap_Increase(vector<obj> &p,int index,int k) {
    if (index < (int)p.size() && p[index].key < k) {
        p[index].key = k;
    } else {
        return;
    }
    while (index > 1 && p[index].key > p[index/2].key) {
        swap(p[index], p[index/2]);
        index /= 2;
    }
}

void Max_Heap_Insert(vector<obj> &p,obj x) {
    // push dummy with -inf key, then increase
    x.key = INT_MIN;
    p.push_back(x);
    Max_Heap_Increase(p, (int)p.size()-1, x.value); // or use x.key if key != value
}

int main() {
    vector<obj> pq(1); // index 0 dummy
    Max_Heap_Insert(pq, obj(42, 15));
    Max_Heap_Insert(pq, obj(99, 30));
    Max_Heap_Insert(pq, obj(17, 10));

    cout << "Max value: " << Max_Heap_Maximum(pq) << endl;
    cout << "Extracted: " << Max_Heap_Extract(pq) << endl;
    cout << "New max: " << Max_Heap_Maximum(pq) << endl;
    return 0;
}