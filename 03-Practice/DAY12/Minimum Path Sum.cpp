class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int>c1(n);
        c1[0]=grid[0][0];
        for(int i=1;i<=n-1;i++)c1[i]=grid[0][i]+c1[i-1];
        for(int i=1;i<=m-1;i++){
            c1[0]=grid[i][0]+c1[0];
            for(int j=1;j<=n-1;j++){
                c1[j]=grid[i][j]+min(c1[j],c1[j-1]);
                
            }
        }
        return c1[n-1];
    }
};
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>c(m,vector<int>(n));
        c[0][0]=grid[0][0];
        for(int i=1;i<=m-1;i++)c[i][0]=grid[i][0]+c[i-1][0];
        for(int i=1;i<=n-1;i++)c[0][i]=grid[0][i]+c[0][i-1];
        for(int i=1;i<=m-1;i++){
            for(int j=1;j<=n-1;j++){
                if(c[i-1][j]>=c[i][j-1])c[i][j]=grid[i][j]+c[i][j-1];
                else c[i][j]=grid[i][j]+c[i-1][j];
            }
        }
        return c[m-1][n-1];
    }
};