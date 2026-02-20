class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>>anc(n);
        vector<int>din(n);
        vector<vector<int>>adj(n);
        for(auto&x:edges){
            int u=x[0],v=x[1];
            din[v]++;
            adj[u].push_back(v);
        }
        queue<int>Q;
        for(int i=0;i<n;i++)if(din[i]==0)Q.push(i);
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            for(auto&v:adj[u]){
                anc[v].insert(u);
                anc[v].insert(anc[u].begin(),anc[u].end());
                din[v]--;
                if(din[v]==0)Q.push(v);
            }
        }
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=vector<int>(anc[i].begin(),anc[i].end());
        }
        return ans;
    }
};