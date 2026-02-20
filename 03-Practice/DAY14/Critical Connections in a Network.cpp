class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<vector<int>> adj(n);
        for (auto& x : con) {
            int u = x[0], v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> bridges;
        vector<int> dis(n, -1), low(n, -1);
        int timer = 0;
        for (int i = 0; i < n; i++) {
            if (dis[i] == -1) {
                tar(i, -1, adj, dis, low, bridges, timer);
            }
        }
        return bridges;
    }
    void tar(int u, int p, vector<vector<int>>& adj,
             vector<int>& dis, vector<int>& low,
             vector<vector<int>>& bridges, int& timer) {
        dis[u] = low[u] = timer++;
        for (auto& v : adj[u]) {
            if (v == p) continue;
            if (dis[v] == -1) {
                tar(v, u, adj, dis, low, bridges, timer);
                low[u] = min(low[u], low[v]);
                if (low[v] > dis[u]) {
                    bridges.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], dis[v]);
            }
        }
    }
};