class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto&x:flights){
            int f=x[0],t=x[1],p=x[2];
            adj[f].push_back({t,p});
        }
        vector<vector<long long>>dis(n,vector<long long>(k+2,LLONG_MAX));
        priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<tuple<long long,int,int>>>pq;
        dis[src][0]=0;
        pq.push({0,src,0});
        while(!pq.empty()){
            auto [w,u,s]=pq.top();
            pq.pop();
            if(s==k+1)continue;
            for(auto&x:adj[u]){
                auto [v,wt]=x;
                long long nw=wt+w;
                if(nw<dis[v][s+1]){
                    dis[v][s+1]=nw;
                    pq.push({nw,v,s+1});
                }
            }
        }
        long long ans = LLONG_MAX;
        for (int i = 1; i <= k+1; i++) {
            ans = min(ans, dis[dst][i]);
        }
        return ans == LLONG_MAX ? -1 : (int)ans;
    }
};