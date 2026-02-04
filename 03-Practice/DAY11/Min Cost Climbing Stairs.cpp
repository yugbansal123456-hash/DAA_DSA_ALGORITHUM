class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==0)return 0;
        if(n==1)return cost[0];
        vector<int>r(n+2,0);
        r[1]=cost[0];
        for(int i=2;i<=n;i++){
            int q=min(r[i-1]+cost[i-1],r[i-2]+cost[i-1]);
            r[i]=q;
        }
        r[n+1]=r[n-1];
        return min(r[n+1],r[n]);
    }
};