class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        int s=0,des=m*n-1;
        vector<int>d(m*n,INT_MAX/2);
        vector<vector<pair<int,int>>>adj(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int u=i*n+j;
                if(i>=1)adj[u].push_back({(i-1)*n+j,abs(heights[i][j]-heights[i-1][j])});
                if(i<m-1)adj[u].push_back({(i+1)*n+j,abs(heights[i][j]-heights[i+1][j])});
                if(j>=1)adj[u].push_back({(i)*n+j-1,abs(heights[i][j]-heights[i][j-1])});
                if(j<n-1)adj[u].push_back({(i)*n+j+1,abs(heights[i][j]-heights[i][j+1])});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        d[s]=0;
        pq.push({d[s],s});
        while(!pq.empty()){
            auto [w,u]=pq.top();
            pq.pop();
            if(w!=d[u])continue;
            for(auto&x:adj[u]){
                auto [v,wt]=x;
                int e=max(wt,d[u]);
                if(d[v]>e){
                    d[v]=e;
                    pq.push({d[v],v});
                }
            }
        }
        return d[des];
    }
};