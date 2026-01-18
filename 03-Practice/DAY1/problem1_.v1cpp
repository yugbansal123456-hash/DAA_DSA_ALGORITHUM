//Largest Product in a Series.Description: You are given a massive 1000-digit number.
// You must find the thirteen adjacent digits that have the greatest product.
//Architect's Challenge: You must treat this number as a vector<int>. Because the product of 13 digits can exceed 2^{31}-1,
// you must use long long for your product calculations to prevent overflow. This is a lesson in Numerical Stability.
#include <iostream>
#include <climits>
#include<vector>
using namespace std;
long long maxprod(const vector<int>&nums,int adj){
    int n=nums.size();
    long long maxi=LLONG_MIN;
    for(int i=0;i<=n-adj;i++){
        long long pro=1;
        for(int j=0;j<adj;j++){
            pro*=nums[i+j];
        }
        if(pro>maxi){
            maxi=pro;
        }
    }
    return maxi;
}int main() {
    // Example shortened number (replace with the full 1000-digit number)
    vector<int> digits = {7,3,1,6,7,1,7,6,5,3,1,3,3,0,6,2,4,9,1,9};
    int adj = 13;

    cout << "Max product of " << adj << " adjacent digits = "
         << maxprod(digits, adj) << endl;

    return 0;
}
