class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>>visit(m,vector<bool>(n,false));
        int m_area=0;
        int area=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&!visit[i][j]){
                    area=0;
                    dfs(grid,visit,i,j,area,m,n);
                    m_area = max(m_area, area);
                }
            }
        }
        return m_area;
    }
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>&visit,int i,int j,int &area,int m,int n){
        int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        visit[i][j]=true;
        area++;
        for(auto&x:dir){
            int u=i+x[0],v=j+x[1];
            if(u<0||v<0||u>=m||v>=n||grid[u][v]==0||visit[u][v])continue;
            dfs(grid,visit,u,v,area,m,n);
        }
    }
};