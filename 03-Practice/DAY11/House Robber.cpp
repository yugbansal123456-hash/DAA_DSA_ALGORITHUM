class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        vector<int>r(n+2,0);
        r[1]=nums[0];r[2]=nums[1];
        for(int i=3;i<=n;i++){
            int q=max(nums[i-1]+r[i-2],nums[i-1]+r[i-3]);
            r[i]=q;
        }
        r[n+1]=r[n-1];
        return max(r[n],r[n+1]);
    }
};