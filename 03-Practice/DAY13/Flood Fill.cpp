class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        queue<pair<int,int>> Q;
        int origin = image[sr][sc];
        if (origin == color) return image;
        Q.push({sr, sc});
        image[sr][sc] = color;
        while (!Q.empty()) {
            auto [i, j] = Q.front();
            Q.pop();
            int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
            for (auto& d : dirs) {
                int u1 = i + d[0], u2 = j + d[1];
                if (u1 < 0 || u2 < 0 || u1 >= m || u2 >= n) continue;
                if (image[u1][u2] == origin) {
                    Q.push({u1, u2});
                    image[u1][u2] = color; 
                }
            }
        }
        return image;
    }
};
