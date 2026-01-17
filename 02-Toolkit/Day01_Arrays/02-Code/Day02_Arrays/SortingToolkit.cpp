//merge sort
#include <iostream>
#include <vector>
using namespace std;
int max_depth = 0;
// Insertion Sort for small subarrays
void insertion_sort(vector<int> &arr, int p, int r) {
    for (int i = p + 1; i <= r; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= p && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(vector<int> &arr,int p,int q,int r){//---O(n)
    //here n will be r-p+1
    int nl=q-p+1;
    int nr=r-q;
    vector<int> l(nl);
    vector<int> R(nr);
    for(int i=0;i<nl;i++){
        l[i]=arr[p+i];
    }
    for(int j=0;j<nr;j++){
        R[j]=arr[q+1+j];
    }
    //total iterations of both loops is n as copy all elements in arr[p:r] ---O(n)
    int i=0;//index or pointer type indication for l
    int j=0;//index indication for r
    int k=p;//index indication for arr
    while(i<nl&&j<nr){
        if(l[i]<=R[j]){
            arr[k]=l[i];
            i++;
        }else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    //it is making b/w n/2 to n-1 comparisions while filling into arr
    while(i<nl){
        arr[k]=l[i];
        i++;
        k++;
    }
    while(j<nr){
        arr[k]=R[j];
        j++;
        k++;
    }
    //---O(n)
    //all three while loops iterate for totaly n times as there are n spaces to fill in array
}
void merge_sort(vector<int> &arr,int p,int r,int depth){
    if(depth>max_depth){//depth is logn base 2
        max_depth=depth;// update global max depth
    }
    if(p>=r){
        return;
    }
    if ((r - p + 1) <= 15) {
        insertion_sort(arr, p, r);
        return;
    }
    int q=(p+r)/2;
    merge_sort(arr,p,q,depth+1);
    merge_sort(arr,q+1,r,depth+1);
    merge(arr,p,q,r);
}//T(n)=2T(n/2)+O(n) ,T(n)=aT(n/b)+f(n) using master theorem case 2 
//---O(nlogn) time complexity
//---O(n) space complexity
int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();

    merge_sort(arr, 0, n - 1, 1);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    cout << "Maximum recursion depth: " << max_depth << "\n";
    return 0;
}
