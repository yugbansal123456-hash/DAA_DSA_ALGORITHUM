class Solution {
public:
    int findMin(vector<int>& nums) {
        return rotated_unit(nums, 0, (int)nums.size() - 1);
    }

    int rotated_unit(vector<int>& nums, int low, int high) {
        if (low >= high) return nums[0];
        int mid = low + (high - low) / 2;
        if (mid < high && nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        }
        if (mid > low && nums[mid] < nums[mid - 1]) {
            return nums[mid];
        }
        if (nums[mid] >= nums[low]) {
            return rotated_unit(nums, mid + 1, high);
        } else {
            return rotated_unit(nums, low, mid - 1);
        }
    }
};
