
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //Sort the array - O(n log n)
        sort(nums.begin(), nums.end());

        //Linear scan to find neighbors that are the same - O(n)
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true; 
            }
        }

        return false;
    }
};