#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& nums, int left, int mid, int right, vector<int>& temp) {
    int i = left, j = mid+1, k = left;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) temp[k++] = nums[i++];
        else temp[k++] = nums[j++];
    }
    while (i <= mid) temp[k++] = nums[i++];
    while (j <= right) temp[k++] = nums[j++];
    for (int p = left; p <= right; p++) nums[p] = temp[p];
}

void mergeSort(vector<int>& nums, int left, int right, vector<int>& temp) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(nums, left, mid, temp);
    mergeSort(nums, mid+1, right, temp);
    merge(nums, left, mid, right, temp);
}

void sortArray(vector<int>& nums) {
    vector<int> temp(nums.size()); // allocate once
    mergeSort(nums, 0, nums.size()-1, temp);
}