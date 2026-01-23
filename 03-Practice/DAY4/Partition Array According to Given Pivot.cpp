class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int p=0,r=nums.size()-1;
        vector<int> l,e,g;
        for(int k=0;k<=r;k++){
            if(nums[k]==pivot){e.push_back(nums[k]);}
            else if(nums[k]<pivot){l.push_back(nums[k]);}
            else{g.push_back(nums[k]);}
        }
        int il=0,ie=0,ig=0;
        for(int i=0 ;i<nums.size();i++){
            if(il<l.size()){nums[i]=l[il++];}
            else if(ie<e.size()){nums[i]=e[ie++];}
            else{nums[i]=g[ig++];}
        }
        return nums;
    }
};
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result;
        result.reserve(n);  // preallocate to avoid reallocation

        // First pass: collect < pivot
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                result.push_back(nums[i]);
            }
        }

        // Second pass: collect == pivot
        for (int i = 0; i < n; i++) {
            if (nums[i] == pivot) {
                result.push_back(nums[i]);
            }
        }

        // Third pass: collect > pivot
        for (int i = 0; i < n; i++) {
            if (nums[i] > pivot) {
                result.push_back(nums[i]);
            }
        }

        return result;
    }
};
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int countLess = 0, countEqual = 0;
        for (int x : nums) {
            if (x < pivot) countLess++;
            else if (x == pivot) countEqual++;
        }
        vector<int> ans(n);
        int iLess = 0, iEqual = countLess, iGreater =  countLess + countEqual;
        for (int x : nums) {
            if (x < pivot) {
                ans[iLess++] = x;
            } else if (x == pivot) {
                ans[iEqual++] = x;
            } else {
                ans[iGreater++] = x;
            }
        }
        return ans;
    }
};