class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        int m=prerequisites.size();
        vector<vector<int>>adj(n);
        vector<int>dir(n,0);
        for(int i=0;i<m;i++){
            int u=prerequisites[i][0],v=prerequisites[i][1];
            adj[u].push_back(v);
            dir[v]++;
        }
        queue<int>Q;
        for(int i=0;i<n;i++){
            if(dir[i]==0)Q.push(i);
        }
        vector<int>ts;
        while(!Q.empty()){
            int u=Q.front();
            ts.push_back(u);
            Q.pop();
            for(auto&v:adj[u]){
                dir[v]--;
                if(dir[v]==0)Q.push(v);
            }
        }
        if(ts.size()!=n)return{};
        reverse(ts.begin(),ts.end());
        return ts;
    }
};