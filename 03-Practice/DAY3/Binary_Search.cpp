class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary_s(nums,0,(int)nums.size()-1,target);
    }
    int binary_s(vector<int>& nums,int low,int high, int target){
        if(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){return mid;}
        else if(nums[mid]>target>=nums[low]){return binary_s(nums,low,mid-1,target);}
        else{return binary_s(nums,mid+1,high,target);}
        }
        return -1;
       
    }
};
