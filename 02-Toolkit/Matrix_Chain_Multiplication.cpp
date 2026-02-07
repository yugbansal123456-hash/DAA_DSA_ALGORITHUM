#include<iostream>
#include<vector>
#include<climits>
using namespace std;
pair<int,vector<vector<int>>>Matrix_chain_Mul(const vector<int>&p,const int n){
    vector<vector<int>>m(n+1,vector<int>(n+1)),s(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        m[i][i]=0;
    }
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<=j-1;k++){
                int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    return {m[1][n],s};
}
void print(const vector<vector<int>>&s,int i,int j){
    if(i==j)cout<<"A"<<i;
    else{
        cout<<"(";
        print(s,i,s[i][j]);
        print(s,s[i][j]+1,j);
        cout<<")";
    }
}
int main() {
    vector<int> p = {30, 35, 15, 5, 10, 20, 25}; 
    int n = p.size() - 1; // number of matrices

    auto result = Matrix_chain_Mul(p, n);
    cout << "Minimum cost: " << result.first << endl;
    cout << "Optimal Parenthesization: ";
    print(result.second, 1, n);
    cout << endl;
}
