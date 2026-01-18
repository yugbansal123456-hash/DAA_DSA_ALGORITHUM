class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0=0;
        int c1=0;
        int c2=0;
        for(int i=0;i<(int)nums.size();i++){
            if(nums[i]==0){c0+=1;}
            else if(nums[i]==1){c1+=1;}
            else{c2+=1;}
        }
        int k=0;
        for(int i=0;i<c0;i++){nums[k++]=0;}
        for(int i=0;i<c1;i++){nums[k++]=1;}
        for(int i=0;i<c2;i++){nums[k++]=2;}
    }
};
class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;              // boundary for 0s
        int mid = 0;              // current element
        int high = nums.size()-1; // boundary for 2s

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
