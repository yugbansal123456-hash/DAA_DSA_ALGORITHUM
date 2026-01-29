class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>m(nums.begin(), nums.end());
        int ml=0;
        for(auto&x:m){
            if(m.find(x-1)==m.end()){
                int count=0;
                int i=0;
                while(m.find(x+i)!=m.end()){
                    count++;
                    i++;
                }
                ml=max(ml,count);
            }
        }
        return ml;
    }
};