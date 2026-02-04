class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>tab(m+1,vector<int>(n+1,1));
        for(int i=2;i<=m;i++){
            for(int j=2;j<=n;j++){
                tab[i][j]=tab[i-1][j]+tab[i][j-1];
            }
        }
        return tab[m][n];
    }
};