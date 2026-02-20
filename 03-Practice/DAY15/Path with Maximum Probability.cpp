class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int sn, int en) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];double p=succProb[i];
            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }
        vector<double>d(n,0);
        d[sn]=1;
        priority_queue<pair<double,int>>pq;
        pq.push({1,sn});
        while(!pq.empty()){
            auto [pro,u]=pq.top();
            pq.pop();
            if(d[u]>pro)continue;
            if(u==en)return pro;
            for(auto&x:adj[u]){
                auto [v,p]=x;
                double np=pro*p;
                if(np>d[v]){
                    d[v]=np;
                    pq.push({np,v});
                }
            }
        }
        return 0;
    }
};