class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)return 0;
        vector<int>am(amount+1,amount+1);
        am[0]=0;
        for(int i=1;i<=amount;i++){
            for(int&k:coins){
                if(k>i)continue;
                if(i-k>=0)am[i]=min(am[i],am[i-k]+1);
            }
        }
        return am[amount]>=amount+1?-1:am[amount];
    }
};