class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, (int)nums.size() - 1);
        return nums;
    }

private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int pivotIndex = partition(nums, left, right);
            quickSort(nums, left, pivotIndex - 1);
            quickSort(nums, pivotIndex + 1, right);
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        // Random pivot selection
         bool check=true;
    for(int j = left; j < right; j++){
        if(nums[j]!=nums[j+1]){
            check=false;
            break;
        }
    }
    if(check==true){
        return left+(right-left)/2;
    }
        int k = left + rand() % (right - left + 1);
        swap(nums[k], nums[right]); // move pivot to end
        int pivot = nums[right];

        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[right]);
        return i + 1;
    }
};
