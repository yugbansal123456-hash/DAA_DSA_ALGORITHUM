class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD=1e9+7;
        vector<vector<pair<int,int>>>adj(n);
        for(auto&x:roads){
            int u=x[0],v=x[1],t=x[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        vector<long long>dis(n,LLONG_MAX);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        vector<int>way(n,0);
        way[0]=1;
        dis[0]=0;
        while(!pq.empty()){
            auto [w,u]=pq.top();
            pq.pop();
            if(w!=dis[u])continue;
            for(auto&x:adj[u]){
                auto[v,wt]=x;
                long long nw=w+wt;
                if(dis[v]>nw){
                    dis[v]=nw;
                    way[v]=way[u];
                    pq.push({nw,v});
                }else if(dis[v]==nw){
                    way[v]=(way[v]+way[u])%MOD;
                }
            }
        }
        return way[n-1];
    }
};