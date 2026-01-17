class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=bsearch(nums,0,(int)nums.size()-1,target,true);
        int last=bsearch(nums,0,(int)nums.size()-1,target,false);
        return{first,last};
    }
    int bsearch(vector<int>& nums,int low,int high, int target,bool first){
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                if(first==true){
                    high=mid-1;
                }else{low=mid+1;}
            }
            else if(nums[mid]>target){high=mid-1;}
            else{low=mid+1;}
        }
        return ans;
    }
};