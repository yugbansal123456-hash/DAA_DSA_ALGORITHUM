//Description: Implement the following without using comparison operators (<, >) in the core logic:
//Counting Sort: Specifically for an array of integers within a known range [0, k].
//Radix Sort: Build this on top of your Counting Sort. Make it work for 32-bit integers by sorting 8 bits (one byte) at a time.
//The "Stability Check": Create a struct Node {int value; int originalIndex;}. 
//Sort an array of these nodes by value and verify that for nodes with the same value, the originalIndex remains in ascending order.
#include <iostream>
#include <vector>
using namespace std;

struct node {
    int value;
    int originalIndex;
    node(int v=0, int o=0) {
        value = v;
        originalIndex = o;
    }
};
bool Stability(vector<int> A, int n, int k) {
    vector<node> nums(n);
    vector<node> B(n);
    vector<int> C(k+1, 0);
    for (int i = 0; i < n; i++) {
        nums[i] = node(A[i], i);
        C[A[i]]++;
    }
    for (int i = 1; i <= k; i++) {
        C[i] += C[i-1];
    }
    for (int i = n-1; i >= 0; i--) {
        int val = nums[i].value;
        B[C[val] - 1] = nums[i];
        C[val]--;
    }
    for (int i = 0; i < n-1; i++) {
        if (B[i].value == B[i+1].value) {
            int diff = B[i].originalIndex - B[i+1].originalIndex;
            if (diff > 0) return false;
        }
    }

    return true;
}
vector<int> CountSort(vector<int> A, int n, int k) {
    vector<int> B(n);
    vector<int> C(k+1, 0);
    for (int i = 0; i < n; i++) {
        C[A[i]]++;
    }
    for (int i = 1; i <= k; i++) {
        C[i] += C[i-1];
    }
    for (int i = n-1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
    return B;
}
void RadixSort(vector<int32_t>& nums, int b = 32, int r = 8) {
    int n = nums.size();
    int k = 1 << r; // base = 2^r
    vector<int32_t> B(n);
    for (int s = 0; s < b / r; s++) {
        vector<int> C(k, 0);
        int mask = (1 << r) - 1;
        for (int i = 0; i < n; i++) {
            int byteval = (nums[i] >> (s * r)) & mask;
            C[byteval]++;
        }
        for (int i = 1; i < k; i++) {
            C[i] += C[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            int byteval = (nums[i] >> (s * r)) & mask;
            B[C[byteval] - 1] = nums[i];
            C[byteval]--;
        }
        nums = B; // Copy back
    }
}
int main() {
    vector<int> A = {4, 2, 2, 8, 3, 3, 1};
    cout << (Stability(A, A.size(), 8) ? "Stable" : "Not Stable") << endl;
    vector<int32_t> nums = {170, 45, 75, 90, 802, 24, 2, 66};
    RadixSort(nums);
    for (auto x : nums) cout << x << " ";
    cout << endl;
    return 0;
}