#include <iostream>
#include <vector>
using namespace std;

int binary_search(const vector<int>& nums, int target) {
    int low = 0, high = (int)nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // safe midpoint calculation

        if (nums[mid] == target) {
            return mid;  // found target
        } else if (nums[mid] > target) {
            high = mid - 1;  // search left half
        } else {
            low = mid + 1;   // search right half
        }
    }
    return -1;  // not found
}
int binary_s(vector<int>& nums,int low,int high, int target){
        if(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){return mid;}
        else if(nums[mid]>target>=nums[low]){return binary_s(nums,low,mid-1,target);}
        else{return binary_s(nums,mid+1,high,target);}
        }
        return -1;
       
    }