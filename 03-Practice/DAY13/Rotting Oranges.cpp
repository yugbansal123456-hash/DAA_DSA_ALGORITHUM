class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>>Q;
        int fresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)Q.push({i,j});
                if(grid[i][j]==1)fresh++;
            }
        }
        if(Q.empty()&&fresh==0){return 0;}
        int time=-1;
        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        while(!Q.empty()){
            int sz=Q.size();
            time++;
            for(int k=0;k<sz;k++){
                int i=Q.front().first,j=Q.front().second;
                Q.pop();
                for(auto&x:dir){
                    int u=i+x[0],v=j+x[1];
                    if(u<0||v<0||u>=m||v>=n||grid[u][v]==0)continue;
                    if(grid[u][v]==1){
                        grid[u][v]=2;
                        fresh--;
                        Q.push({u,v});
                    }
                }
            }
        }
        return fresh==0?time:-1;
    }
};