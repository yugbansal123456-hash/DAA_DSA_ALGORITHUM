class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return divANDcoq(nums,0,(int)nums.size()-1);
    }
private:
int divANDcoq(vector<int>& nums,int low,int high){
    if(low==high){return nums[low];}
    int mid=low+(high-low)/2;
    int leftmax=divANDcoq(nums,low,mid);
    int rightmax=divANDcoq(nums,mid+1,high);
    int midmax=MidMax(nums,low,mid,high);
    return max({leftmax,rightmax,midmax});
}
int MidMax(vector<int>& nums,int low,int mid,int high){
    int sum=0;
    int lmax=INT_MIN;
    for(int i=mid;i>=low;i--){
        sum+=nums[i];
        lmax=max(lmax,sum);
    }
    sum=0;
    int rmax=INT_MIN;
    for(int i=mid;i<=high;i++){
        sum+=nums[i];
        rmax=max(rmax,sum);
    }
    return lmax+rmax-nums[mid];
}
};
//divide conqure methord
class Solution2 {
    public:
    int maxSubArray(vector<int>& nums){
int prefix=0;
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> add(n,0);
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            add[i]=prefix;
        }
        int max=add[0];
        int min=0;
        for(int i=0;i<n;i++){
            if(add[i]-min>max){
                max=add[i]-min;
            }
            if(add[i]<min){
                min=add[i];
            }
        }
        return max;
    }
};