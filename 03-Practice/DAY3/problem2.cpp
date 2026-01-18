//Sqrt(x): Implement sqrt using Binary Search.Architect's Challenge: Handle the case where x is the maximum integer.
// This tests your boundary condition skills and data type awareness. If you square mid, will it overflow?
// Use long long or division logic (mid > x/mid) to check.
#include <iostream>
    long long mySqrt(long long x) {
        if (x < 2) return x;
        long long l = 1, h = x / 2, ans = 0;
        while (l <= h) {
            long long m = l + (h - l) / 2;
            if (m <= x / m) {   // safe check
                ans = m;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return ans;
    }
    int main(){
        std::cout<<mySqrt(51);
        return 0;
    }