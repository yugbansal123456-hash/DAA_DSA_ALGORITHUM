//For your Implementation Lab, the ultimate pivot choice isn't just 
//random—it's the Median-of-Three. Take the first, middle, and last elements, 
//and use the median of those three as your pivot. This is the secret to why std::sort is so robust in modern compilers.
#include <iostream>
#include <vector>
using namespace std;

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

int Three_way_Partition(vector<int>& nums, int p, int r) {
    int q = p + (r - p) / 2;

    // Median-of-three ordering
    if(nums[p] > nums[q]) swap(nums[p], nums[q]);
    if(nums[p] > nums[r]) swap(nums[p], nums[r]);
    if(nums[r] < nums[q]) swap(nums[r], nums[q]);

    swap(nums[q], nums[r]); // pivot moved to end
    int pivot = nums[r];

    // Check if all elements equal in [p..r]
    bool allEqual = true;
    for(int i=p; i<r; i++) {
        if(nums[i] != nums[i+1]) { allEqual=false; break; }
    }
    if(allEqual) return -1; // sentinel

    // Lomuto partition
    int i = p-1;
    for(int j=p; j<r; j++) {
        if(nums[j] <= pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i+1], nums[r]);
    return i+1;
}

void tail_quicksort(vector<int>& nums, int p, int r) {
    while(p < r) {
        // Cutoff to insertion sort for small subarrays
        if(r - p <= 16) {
            insertion_sort(nums, p, r);
            return;
        }

        int q = Three_way_Partition(nums, p, r);
        if(q == -1) return; // all equal, stop

        int nl = q - p;
        int nr = r - q;

        if(nl <= nr) {
            tail_quicksort(nums, p, q-1); // recurse smaller left
            p = q+1;                      // iterate right
        } else {
            tail_quicksort(nums, q+1, r); // recurse smaller right
            r = q-1;                      // iterate left
        }
    }
}

int main() {
    vector<int> arr = {9, 3, 7, 1, 8, 2, 5, 4, 6};
    tail_quicksort(arr, 0, arr.size()-1);

    cout << "Sorted array: ";
    for(int x : arr) cout << x << " ";
    cout << endl;
}
//- Median‑of‑Three pivoting
//- Equal‑elements guard
//- Insertion Sort cutoff
//- Tail recursion elimination
