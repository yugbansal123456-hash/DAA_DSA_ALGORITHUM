class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& x : times) {
            int u = x[0]-1, v = x[1]-1, w = x[2]; 
            adj[u].push_back({v,w});
        }
        vector<int> dist(n, INT_MAX/2);
        dist[k-1] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k-1});
        while (!pq.empty()) {
            auto [d,u] = pq.top();
            pq.pop();
            if (d != dist[u]) continue;
            for (auto& [v,wt] : adj[u]) {
                if (dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = *max_element(dist.begin(), dist.end());
        return ans >= INT_MAX/2 ? -1 : ans;
    }
};
