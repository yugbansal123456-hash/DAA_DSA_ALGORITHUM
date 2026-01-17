class Solution {
public:
    int search(vector<int>& nums, int target) {
        return rotated_search(nums,0,(int)nums.size()-1,target);
    }
    int rotated_search(vector<int>& nums,int low,int high, int target){
        if(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){return mid; }
            if(nums[low]<=nums[mid]){
                if(nums[mid]>target&&target>=nums[low]){return rotated_search(nums,low,mid-1,target);}
                else{return rotated_search(nums,mid+1,high,target); }
                }else{
                if(nums[mid]<target&&target<=nums[high]){return rotated_search(nums,mid+1,high,target);}
                else{return rotated_search(nums,low,mid-1,target); }
                }
        }
        return -1;
    }
};
