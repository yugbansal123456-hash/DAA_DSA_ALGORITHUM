class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left_end=0,right_end=nums.size()-1,k=nums.size()-1;
        vector<int> ans((int)nums.size());
        while(left_end<=right_end){
            int left=nums[left_end]*nums[left_end];
            int right=nums[right_end]*nums[right_end];
            if(left>right){
                ans[k--]=left;left_end++;
            }else{
                ans[k--]=right;right_end--;
            }
        }
        return ans;
    }
    vector<int> sortedSquares2(vector<int>& nums) {
    vector<int> ans(nums.size());
        int n = -1, p = nums.size();
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] < 0) {
                n = i;
            } else if (nums[i] > 0) {
                p = i;
                break;
            }
        }
        for (int i = 0; i < (int)nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }
        int k = 0;
        for (int i = n + 1; i < p; i++) {
            ans[k++] = nums[i];
        }
        while (n >= 0 && p < (int)nums.size()) {
            if (nums[n] < nums[p]) {
                ans[k++] = nums[n--];
            } else {
                ans[k++] = nums[p++];
            }
        }
        while (n >= 0) {
            ans[k++] = nums[n--];
        }
        while (p < (int)nums.size()) {
            ans[k++] = nums[p++];
        }
        return ans;
    }
};