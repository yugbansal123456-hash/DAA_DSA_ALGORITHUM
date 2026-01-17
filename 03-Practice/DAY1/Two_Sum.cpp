class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int a=0;a<=(int)nums.size()-2;a++){
            for(int b=a+1;b<=(int)nums.size()-1;b++){
                if(nums[a]+nums[b]==target){
                    return {a,b};
                }
            }
        }
         return {};
}
};