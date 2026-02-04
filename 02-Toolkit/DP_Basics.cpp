//Description: Implement the Rod Cutting problem in three distinct ways:
//Plain Recursion: Note how it chokes on a rod of length 30.
//Memoization (Top-Down): Use an array to store results. Watch the speed jump.
//Tabulation (Bottom-Up): Build the solution iteratively from length 1 to $n$.
#include<iostream>
#include<vector>
#include<climits>
#include <chrono>
using namespace std;
//1:
int RodCut(vector<int>&p,int n){
    if(n==0)return 0;
    int q=INT_MIN;
    for(int i=1;i<=n;i++){
        q=max(q,p[i]+RodCut(p,n-i));
    }
    return q;
}
//2:
int TopDown_rodcut_aux(vector<int>&p,int n,vector<int>&r){
    if(n==0)return 0;
    if(r[n]!=-1)return r[n];
    else{
        int q=INT_MIN;
        for(int i=1;i<=n;i++){
            q=max(q,p[i]+TopDown_rodcut_aux(p,n-i,r));
        }
        r[n]=q;
        return r[n];
    }
}
int TopDown_rodcut(vector<int>&p,int n){
    vector<int>r(n+1,-1);
    return TopDown_rodcut_aux(p,n,r);
}
//3:
int BottomUp_rodcut(vector<int>&p,int n){
    vector<int>r(n+1);
    r[0]=0;
    for(int j=1;j<=n;j++){
        int q=INT_MIN;
        for(int i=1;i<=j;i++){
            q=max(q,p[i]+r[j-i]);
        }
        r[j]=q;
    }
    return r[n];
}
//when optimal solution
pair<int,vector<int>> Ex_BottomUp_rodcut(vector<int>&p,int n){
    vector<int>r(n+1),s(n+1);
    r[0]=0;
    for(int j=1;j<=n;j++){
        int q=INT_MIN;
        for(int i=1;i<=j;i++){
            if(q<p[i]+r[j-i]){
                q=p[i]+r[j-i];
                s[j]=i;
            }
        }
        r[j]=q;
    }
    return {r[n],s};
}
void print_op_solution(vector<int>&p,int n){
    pair<int,vector<int>>result;
    result=Ex_BottomUp_rodcut(p,n);
    vector<int>&S=result.second;
    cout << "OPTIMAL VALUE: " << result.first << "\nCuts: ";
    while(n>0){
        cout << S[n] << " ";
        n=n-S[n];
    }
    cout << "\n";
}
int main() {
    // Example price list: index = rod length, value = price
    vector<int> p = {
        0, 1, 5, 8, 9, 10, 17, 17, 20, 24,
        30, 33, 36, 40, 45, 50, 55, 60, 65, 70,
        76, 82, 88, 94, 100, 108, 115, 123, 130, 138,
        147
    };
    int n = 30;


    // Benchmark plain recursion
    auto start = chrono::high_resolution_clock::now();
    int rec_val = RodCut(p, n);
    auto end = chrono::high_resolution_clock::now();
    cout << "Plain Recursion: " << rec_val
         << " (Time: " << chrono::duration<double, milli>(end - start).count() << " ms)\n";

    // Benchmark top-down memoization
    start = chrono::high_resolution_clock::now();
    int memo_val = TopDown_rodcut(p, n);
    end = chrono::high_resolution_clock::now();
    cout << "Top-Down Memoization: " << memo_val
         << " (Time: " << chrono::duration<double, milli>(end - start).count() << " ms)\n";

    // Benchmark bottom-up tabulation
    start = chrono::high_resolution_clock::now();
    int tab_val = BottomUp_rodcut(p, n);
    end = chrono::high_resolution_clock::now();
    cout << "Bottom-Up Tabulation: " << tab_val
         << " (Time: " << chrono::duration<double, milli>(end - start).count() << " ms)\n";

    // Print optimal solution reconstruction
    print_op_solution(p, n);

    return 0;
}
