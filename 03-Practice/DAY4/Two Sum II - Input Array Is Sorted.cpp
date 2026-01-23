class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int j=numbers.size()-1,k=0;
        while(k<=j){
            if(numbers[k]+numbers[j]>target){
                j--;
            }
            else if(numbers[k]+numbers[j]==target){
                return {k+1,j+1};
            }else{
                k++;
            }
        }
        return {};
    }
};