class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prefix;
        prefix[0]=1;
        int pre=0,count=0;
        for(auto&x:nums){
            pre+=x;
            if(prefix.find(pre-k)!=prefix.end()){
                count+=prefix.find(pre-k)->second;
            }
            prefix[pre]++;
        }
        return count;
    }
};