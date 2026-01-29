class Solution {
public:
    void sortColors(vector<int>& nums) {
        countSort(nums,nums.size(),2);
    }
    void countSort(vector<int>& nums,int n,int k){
        vector<int>B(n);
        vector<int>C(k+1,0);
        for(int i=0;i<n;i++){
            C[nums[i]]++;
        }
        for(int i=1;i<=k;i++){
            C[i]+=C[i-1];
        }
        for(int i=n-1;i>=0;i--){
            B[C[nums[i]]-1]=nums[i];
            C[nums[i]]--;
        }
        nums=B;
    }
};