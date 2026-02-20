#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include <utility>
using namespace std;
struct edge{
    int to;
    int weight;
    edge(int t,int w){to=t;weight=w;}
};
const int INF = INT_MAX / 2;
void addedge(vector<vector<edge>>&adj,int u,int v,int w){
    adj[u].push_back(edge(v,w));
}
void dijkstra(int source, int n,vector<vector<edge>>&adj, vector<int>&d,vector<int>&p){
    for(int i=0;i<n;i++){
        d[i]=INF;
        p[i]=-1;
    }
    d[source]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;//{dis,node}
    Q.push({d[source],source});
    while(!Q.empty()){
        int du=Q.top().first;
        int u=Q.top().second;
        Q.pop();
        if(du!=d[u])continue;
        for(auto&x:adj[u]){
            int v=x.to;
            int w=x.weight;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                p[v]=u;
                Q.push({d[v],v});
            }
        }
    }
}
vector<int>TS(vector<vector<edge>>&adj, int n){
    vector<int>din(n,0);
    for(int i=0;i<n;i++){
        for(auto&x:adj[i]){
            int v=x.to;
            din[v]++;
        }
    }
    queue<int>Q;
    vector<int>ts;
    for(int i=0;i<n;i++){
        if(din[i]==0)Q.push(i);
    }
    while(!Q.empty()){
        int u=Q.front();
        ts.push_back(u);
        Q.pop();
        for(auto&x:adj[u]){
            int v=x.to;
            din[v]--;
            if(din[v]==0)Q.push(v);
        }
    }
    return ts;
}
void DAG_SP(int source, int n,vector<vector<edge>>&adj, vector<int>&d,vector<int>&p){
    vector<int>ts=TS(adj,n);
    for(int i=0;i<n;i++){
        d[i]=INF;
        p[i]=-1;
    }
    d[source]=0;
    for(auto&u:ts){
        if(d[u]==INF)continue;
        for(auto&x:adj[u]){
            int v=x.to;
            int w=x.weight;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                p[v]=u;
            }
        }
    }
}
bool bellmanFord(int source, int n, vector<vector<edge>>&adj, vector<int>&d,vector<int>&p){
    for(int i=0;i<n;i++){
        d[i]=INF;
        p[i]=-1;
    }
    d[source]=0;
    for(int c=1;c<n;c++){
        for(int i=0;i<n;i++){
            for(auto&x:adj[i]){
                int v=x.to;
                int w=x.weight;
                if(d[i]==INF)continue;
                if(d[v]>d[i]+w){
                    d[v]=d[i]+w;
                    p[v]=i;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(auto&x:adj[i]){
            int v=x.to;
            int w=x.weight;
            if(d[i]!=INF&&d[v]>d[i]+w)return false;
        }
    }
    return true;
}
void path(vector<int>&p,int s,int v){
    if(s==v){
        cout<<v;
        return;
    }else if(p[v]==-1){
        cout<<"no path";
    }else{
        path(p,s,p[v]);
        cout<<" "<<v;
    }
}
vector<int> PATH(vector<int>&p,int s,int v){
    vector<int>path;
    for(int i=v;i!=-1;i=p[i]){
        path.push_back(i);
    }
    reverse(path.begin(),path.end());
    if(path[0]==s)return path;
    return {};
}
int main() {
    int n = 5;  // number of nodes
    vector<vector<edge>> adj(n);

    // Build a sample graph
    addedge(adj, 0, 1, 2);
    addedge(adj, 0, 2, 4);
    addedge(adj, 1, 2, 1);
    addedge(adj, 1, 3, 7);
    addedge(adj, 2, 4, 3);
    addedge(adj, 3, 4, 1);

    vector<int> d(n), p(n);

    cout << "=== Dijkstra ===\n";
    dijkstra(0, n, adj, d, p);
    for (int i = 0; i < n; i++) {
        cout << "dist[0 -> " << i << "] = " << d[i] << "\n";
    }
    cout << "Path to node 4: ";
    vector<int> pathVec = PATH(p, 0, 4);
    if (pathVec.empty()) cout << "No path\n";
    else {
        for (int node : pathVec) cout << node << " ";
        cout << "\n";
    }

    cout << "\n=== DAG Shortest Path ===\n";
    DAG_SP(0, n, adj, d, p);
    for (int i = 0; i < n; i++) {
        cout << "dist[0 -> " << i << "] = " << d[i] << "\n";
    }

    cout << "\n=== Bellman-Ford ===\n";
    bool ok = bellmanFord(0, n, adj, d, p);
    if (!ok) cout << "Negative cycle detected!\n";
    else {
        for (int i = 0; i < n; i++) {
            cout << "dist[0 -> " << i << "] = " << d[i] << "\n";
        }
    }

    return 0;
}