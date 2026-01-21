#include<iostream>
#include<vector>
#include<climits>
using namespace std;
//based on 1 indexing
void Heap_Maxify(vector<int> &a,int i,int heapsize){
    int lchild=2*i,rchild=2*i+1,largest=i;
    if(lchild<=heapsize && a[i]<a[lchild]){
        largest=lchild;
    }
    if(rchild<=heapsize && a[largest]<a[rchild]){
        largest=rchild;
    }
    if(largest!=i){
        swap(a[largest],a[i]);
        Heap_Maxify(a,largest,heapsize);
    }
}
void Build_Heap_Max(vector<int> &a,int heapsize){
    int n=heapsize;
    for(int i=n/2;i>=1;i--){
        Heap_Maxify(a,i,heapsize);
    }
}
void Heap_Sort(vector<int> &a){
    int n=a.size()-1;
    int heapsize=n;
    Build_Heap_Max(a,heapsize);
    for(int i=n;i>=2;i--){
        swap(a[i],a[1]);
        heapsize=heapsize-1;
        Heap_Maxify(a,1,heapsize);
    }

}
//when we use 1 indexing
//in this we let o index element of vector as dummy
int main(){
    vector <int> a={INT_MIN,4,35,6,5,40,10,1,7,100,50};
    Heap_Sort(a);
    for(int i=0;i<=(int)a.size()-1;i++){
        cout<<a[i]<<" ";
    }
    return 0;


}