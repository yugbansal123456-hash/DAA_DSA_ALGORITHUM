class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> store; 
        for(int i=0; i<nums.size(); i++){
            int v = target - nums[i];
            if(store.find(v) != store.end()){
                return {i, store[v]};
            }
            store[nums[i]]=i;
        }
        return {};
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> store; 
        for(int i=0; i<nums.size(); i++){
            store[nums[i]] = i;
        }
        for(int i=0; i<nums.size(); i++){
            int v = target - nums[i];
            if(store.find(v) != store.end() && store[v] != i){
                return {i, store[v]};
            }
        }
        return {};
    }
};
