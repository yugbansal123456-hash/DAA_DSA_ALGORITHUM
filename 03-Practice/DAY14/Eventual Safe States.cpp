class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>ans;
        vector<int>dout(n,0);
        queue<int>Q;
        for(int i=0;i<n;i++){
            dout[i]=graph[i].size();
            if(dout[i]==0){
                Q.push(i);
                ans.push_back(i);
            }
            for(auto&x:graph[i]){
                adj[x].push_back(i);
            }
        }
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            for(auto&v:adj[u]){
                dout[v]--;
                if(dout[v]==0){
                    Q.push(v);
                    ans.push_back(v);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
enum color{w,g,b};
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<color>visit(n,w);
        vector<int>safe;
        for(int i=0;i<n;i++){
            if(dfs(graph,visit,i))safe.push_back(i);
        }
        return safe;
    }
    bool dfs(vector<vector<int>>& graph,vector<color>&visit,int u){
        if(visit[u]!=w)return visit[u]==b;//cycle detect
        visit[u]=g;
        for(auto&v:graph[u]){
            if(!dfs(graph,visit,v))return false;
        }
        visit[u]=b;
        return true;
    }
};