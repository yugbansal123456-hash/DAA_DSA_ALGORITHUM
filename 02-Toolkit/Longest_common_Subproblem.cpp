#include <iostream>
#include <vector>
#include <climits>
#include<algorithm>
using namespace std;
pair<int,vector<vector<int>>>LCS(vector<char>&x,vector<char>&y,int m,int n){
    vector<vector<int>>c(m+1,vector<int>(n+1));
    for(int i=0;i<=m;i++)c[i][0]=0;
    for(int i=0;i<=n;i++)c[0][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1])c[i][j]=1+c[i-1][j-1];
            else if(c[i-1][j]>=c[i][j-1])c[i][j]=c[i-1][j];
            else c[i][j]=c[i][j-1];
        }
    }
    return {c[m][n],c};
}
void print(vector<char>&x,vector<char>&y,vector<vector<int>>&c,int i,int j){
    if(i==0||j==0)return;
    if(x[i-1]==y[j-1]){
        print(x,y,c,i-1,j-1);
        cout<<x[i-1];
    }else if(c[i-1][j]>=c[i][j-1])print(x,y,c,i-1,j);
    else print(x,y,c,i,j-1);
}
int main() {
    vector<char> X = {'A','B','C','B','D','A','B'};
    vector<char> Y = {'B','D','C','A','B','A'};
    int m = X.size();
    int n = Y.size();

    auto result = LCS(X, Y, m, n);
    cout << "Length of LCS: " << result.first << "\n";
    cout << "LCS: ";
    print(X, Y, result.second, m, n);
    cout << "\n";

    return 0;
}
