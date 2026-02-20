class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto&x:edges){
            int u=x[0],v=x[1],w=x[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>td(n);
        for(int i=0;i<n;i++){
            int s=i;
            vector<int>d(n,INT_MAX/2);
            d[s]=0;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
            Q.push({0,s});
            while(!Q.empty()){
                auto [w,u]=Q.top();
                Q.pop();
                if(d[u]!=w)continue;
                for(auto&x:adj[u]){
                    auto [v,wt]=x;
                    if(d[v]>d[u]+wt){
                        d[v]=d[u]+wt;
                        Q.push({d[v],v});
                    }
                }
            }
        int count = 0;
        for (int v = 0; v < n; v++) {
            if (v != s && d[v] <= k) count++;
        }

        td[s]=count;
        }
        int m=0;
        for(int i=1;i<n;i++){
            if(td[i]<=td[m])m=i;
        }
        return m;
    }
};