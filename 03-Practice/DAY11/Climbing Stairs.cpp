class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)return n;
        vector<int>r(n+1,0);
        r[1]=1;
        r[2]=2;
        for(int i=3;i<=n;i++){
            r[i]=r[i-1]+r[i-2];
        }
        return r[n];
    }
};