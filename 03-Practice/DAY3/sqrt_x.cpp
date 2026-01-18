class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int l = 1, h = x / 2, ans = 0;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (m <= x / m) {   // safe check
                ans = m;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return ans;
    }
};