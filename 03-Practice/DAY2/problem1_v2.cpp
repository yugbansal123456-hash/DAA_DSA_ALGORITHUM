//Task: Project Euler Problem 8: Largest Product in a Series.Description: Given a 1000-digit string
//find the 13 adjacent digits with the max product.
//Architect's Challenge: You must use long long for products. 
//This problem tests your ability to handle Sliding Windows on large datasets—a core AI/Data skill.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long maxprod(const vector<int>& nums, int adj) {
    int n = nums.size();
    long long pro = 1;
    long long maxi = LLONG_MIN;

    // Initial product of first window
    for (int i = 0; i < adj; i++) {
        pro *= nums[i];
    }
    maxi = pro;

    // Sliding window
    for (int i = adj; i < n; i++) {
        if (nums[i - adj] == 0) {
            // Recompute product if zero left the window
            pro = 1;
            for (int j = i - adj + 1; j <= i; j++) {
                pro *= nums[j];
            }
        } else {
            // Divide out old digit, multiply in new digit
            pro = pro / nums[i - adj] * nums[i];
        }
        if (pro > maxi) {
            maxi = pro;
        }
    }

    return maxi;
}
int main(){
string bigNumber = "73167176531330624919225119674426574742355349194934..."; // full 1000-digit number
vector<int> digits;
for (char c : bigNumber) {
    digits.push_back(c - '0'); // convert char to int
}

cout << maxprod(digits, 13) << endl;
return 0;
}