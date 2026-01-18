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

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    int target = 7;

    int index = binary_search(nums, target);
    if (index != -1) {
        cout << "Found at index: " << index << endl;
    } else {
        cout << "Not found" << endl;
    }
    return 0;
}