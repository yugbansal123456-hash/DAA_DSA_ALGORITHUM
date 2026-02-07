class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>m(n+1,vector<int>(n+1)),p(n+1,vector<int>(n+1));
        for(int i=1;i<=n;i++){
            m[i][i]=arr[i-1];
            p[i][i]=0;
        }
        for(int l=2;l<=n;l++){
            for(int i=1;i<=n-l+1;i++){
                int j=i+l-1;
                p[i][j]=INT_MAX;
                for(int k=i;k<=j-1;k++){
                    int pro=m[i][k]*m[k+1][j]+p[i][k]+p[k+1][j];
                    if(pro<p[i][j]){
                        p[i][j]=pro;
                        m[i][j]=max(m[i][k],m[k+1][j]);
                    }
                }
            }
        }
        return p[1][n];
    }
};