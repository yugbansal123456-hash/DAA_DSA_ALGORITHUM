#include<iostream>
#include<climits>
#include<vector>
using namespace std;
vector<vector<int>> OP_BST(vector<int>p,vector<int>q,int n){
    vector<vector<int>>e(n+2,vector<int>(n+2)),w(n+2,vector<int>(n+2)),root(n+2,vector<int>(n+2));
    for(int i=1;i<=n+1;i++){
        e[i][i-1]=q[i-1];
        w[i][i-1]=q[i-1];
    }
    for(int l=1;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            e[i][j]=INT_MAX;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            for(int k=i;k<=j;k++){
                int t=e[i][k-1]+e[k+1][j]+w[i][j];
                if(t<e[i][j]){
                    e[i][j]=t;
                    root[i][j]=k;
                }
            }
        }
    }
    return root;
}
void print(vector<vector<int>>root,int i,int j){
    if(j<i){
        cout<<"D"<<j<<"\n";
        return;
    }
    int r=root[i][j];
    cout<<"K"<<r<<"\n";
    cout<<"Left subtree of K"<<r<<" :\n";
    print(root,i,r-1);
    cout<<"Right subtree of K"<<r<<" :\n";
    print(root,r+1,j);
}
int main() {
    vector<int> p = {0, 3, 3, 1};   // probabilities for keys (1-indexed)
    vector<int> q = {2, 3, 1, 1};   // probabilities for dummy nodes
    int n = 3;

    vector<vector<int>> root = OP_BST(p, q, n);
    print(root, 1, n);
    return 0;
}
