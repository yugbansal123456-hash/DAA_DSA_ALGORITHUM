class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>c(n,-1);
        for(int i=0;i<n;i++){
            if(c[i]==-1){
                queue<int>Q;
                Q.push(i);
                c[i]=0;
                while(!Q.empty()){
                    int u=Q.front();Q.pop();
                    for(auto&v:graph[u]){
                        if(c[v]==-1){
                            c[v]=1-c[u];
                            Q.push(v);
                        }
                        else if(c[v]==c[u])return false;
                    }
                }
            }
        }
        return true;

    }    
};