//Lomuto Partition: The standard single-direction scan.
//Hoare Partition: The dual-direction scan. It uses fewer swaps on average.
//Randomized Quicksort: A wrapper that swaps a random element to the pivot position before calling your partition.
//Tail Recursion Optimization: Modify your QuickSort to only recurse on the smaller partition and use a while loop for the larger one. This guarantees O(log n) stack space even in the worst case.
#include <iostream>
#include<vector>
#include<random>
using namespace std;
int rand_gen(int a,int b){
    static mt19937 gen(random_device{}());
    uniform_int_distribution <> dist(a,b);
    return dist(gen);
}
int Partition(vector<int> &nums,int p,int r){
    int x=nums[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++){
        if(nums[j]<=x){
            i++;
            swap(nums[j],nums[i]);
        }
    }
    swap(nums[i+1],nums[r]);//x value is copy of nums[r] not position or reference
    return i+1;

}
int Random_Partition(vector<int> &nums,int p,int r){
    int k=rand_gen(p,r);
    swap(nums[k],nums[r]);
    int x=nums[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++){
        if(nums[j]<=x){
            i++;
            swap(nums[j],nums[i]);
        }
    }
    swap(nums[i+1],nums[r]);//x value is copy of nums[r] not position or reference
    return i+1;

    
}
int Hoare_Partition(vector<int> &nums,int p,int r){
   int i=p-1,j=r+1;
   int x=nums[p];
   while (true){//don't use i<j as somethings will be missed
    do{j--;}while(nums[j]>x);//don't use nums[j]>=x to avoid infinite loop in case when all elements are equal
    do{i++;}while(nums[i]<x);
    if(i<j){swap(nums[i],nums[j]);}
    else{return j;}
   }
}
void Quicksort(vector<int> &nums,int p,int r){
if(p<r){
    int q=Partition(nums,p,r);
    Quicksort(nums,p,q-1);
    Quicksort(nums,q+1,r);

}
}
void Random_Quicksort(vector<int> &nums,int p,int r){
if(p<r){
    int q=Random_Partition(nums,p,r);
    Random_Quicksort(nums,p,q-1);
    Random_Quicksort(nums,q+1,r);

}
}

void Hoare_Quicksort(vector<int> &nums,int p,int r){
if(p<r){
    int q=Hoare_Partition(nums,p,r);
    Hoare_Quicksort(nums,p,q);
    Hoare_Quicksort(nums,q+1,r);
}
}
void Tail_Quicksort(vector<int>& nums, int p, int r) {
    while (p < r) {
        int q = Partition(nums, p, r);
        int nl = q - p;
        int nr = r - q;

        if (nl <= nr) {
            Tail_Quicksort(nums, p, q - 1);  // recurse on smaller left
            p = q + 1;                       // iterate on right
        } else {
            Tail_Quicksort(nums, q + 1, r);  // recurse on smaller right
            r = q - 1;                       // iterate on left
        }
    }
}


int main() {
    vector<int> arr = {9, 3, 7, 1, 8, 2};

    vector<int> a1 = arr, a2 = arr, a3 = arr, a4 = arr;

    Quicksort(a1, 0, a1.size()-1);
    Random_Quicksort(a2, 0, a2.size()-1);
    Hoare_Quicksort(a3, 0, a3.size()-1);
    Tail_Quicksort(a4, 0, a4.size()-1);

    cout << "Lomuto Quicksort: ";
    for (int x : a1) cout << x << " ";
    cout << "\nRandom Quicksort: ";
    for (int x : a2) cout << x << " ";
    cout << "\nHoare Quicksort: ";
    for (int x : a3) cout << x << " ";
    cout << "\nTail Quicksort: ";
    for (int x : a4) cout << x << " ";
    cout << endl;
}