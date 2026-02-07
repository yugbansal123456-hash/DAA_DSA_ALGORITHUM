#include<iostream>
#include<vector>
#include<climits>
using namespace std;
pair<int,vector<int>> ROD_CUT(vector<int>&p,int n){
    vector<int>r(n+1,0),s(n+1);
    for(int i=1;i<=n;i++){
        int q=INT_MIN;
        for(int j=1;j<=i;j++){
            if(q<p[j]+r[i-j]){
                q=p[j]+r[i-j];
                s[i]=j;
            }
        }
        r[i]=q;
    }
    return {r[n],s};
}
void print(vector<int>&s,int n){
    while(n>0){
        cout<<s[n]<<" ";
        n=n-s[n];
    }
    cout<<"\n";
}
int main() {
    // Example: price array (1-indexed)
    vector<int> p = {0, 1, 5, 8, 9, 10, 17, 17, 20}; 
    int n = 8;

    auto result = ROD_CUT(p, n);
    cout << "Maximum Revenue: " << result.first << "\n";
    cout << "Cuts: ";
    print(result.second, n);

    return 0;
}
