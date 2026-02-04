#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// Bottom-up LCS with direction matrix
pair<vector<vector<int>>, vector<vector<char>>> LCS(vector<char>& x, int m, vector<char>& y, int n) {
    vector<vector<int>> c(m+1, vector<int>(n+1, 0));
    vector<vector<char>> b(m+1, vector<char>(n+1, 0));
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(x[i-1] == y[j-1]) {
                c[i][j] = 1 + c[i-1][j-1];
                b[i][j] = 'D'; // diagonal
            } else if(c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = 'U'; // up
            } else {
                c[i][j] = c[i][j-1];
                b[i][j] = 'L'; // left
            }
        }
    }
    return {c, b};
}
// Print LCS using direction matrix
void print_lcsLCS(vector<vector<char>>& b, vector<char>& x, int i, int j) {
    if(i==0 || j==0) return;
    if(b[i][j] == 'D') {
        print_lcsLCS(b, x, i-1, j-1);
        cout << x[i-1];
    } else if(b[i][j] == 'U') {
        print_lcsLCS(b, x, i-1, j);
    } else {
        print_lcsLCS(b, x, i, j-1);
    }
}
// Optimal LCS without b matrix
vector<vector<int>> opt_LCS(vector<char>& x, int m, vector<char>& y, int n) {
    vector<vector<int>> c(m+1, vector<int>(n+1, 0));
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(x[i-1] == y[j-1]) {
                c[i][j] = 1 + c[i-1][j-1];
            } else {
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }
    return c;
}
// Print optimal LCS using c matrix
void print_opt_LCS(vector<char>& x, vector<char>& y, vector<vector<int>>& c, int i, int j) {
    if(i==0 || j==0) return;
    if(x[i-1] == y[j-1]) {
        print_opt_LCS(x, y, c, i-1, j-1);
        cout << x[i-1];
    } else if(c[i-1][j] >= c[i][j-1]) {
        print_opt_LCS(x, y, c, i-1, j);
    } else {
        print_opt_LCS(x, y, c, i, j-1);
    }
}
// Iterative reconstruction of LCS
vector<char> n_print_opt_LCS(vector<char>& x, vector<char>& y, vector<vector<int>>& c, int m, int n) {
    int i=m, j=n;
    vector<char> path;
    while(i>0 && j>0) {
        if(x[i-1] == y[j-1]) {
            path.push_back(x[i-1]);
            i--; j--;
        } else if(c[i-1][j] >= c[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(path.begin(), path.end());
    return path;
}
// Top-down LCS (memoized recursion)
int top_down_LCS_aux(vector<char>& x, vector<char>& y, vector<vector<int>>& c, int i, int j) {
    if(i==0 || j==0) return 0;
    if(c[i][j] != -1) return c[i][j];
    if(x[i-1] == y[j-1]) {
        c[i][j] = 1 + top_down_LCS_aux(x, y, c, i-1, j-1);
    } else {
        c[i][j] = max(top_down_LCS_aux(x, y, c, i-1, j),
                      top_down_LCS_aux(x, y, c, i, j-1));
    }
    return c[i][j];
}
int top_down_LCS(vector<char>& x, int m, vector<char>& y, int n) {
    vector<vector<int>> c(m+1, vector<int>(n+1, -1));
    return top_down_LCS_aux(x, y, c, m, n);
}
// Two-row bottom-up LCS
int bottom_up_twoRow(vector<char>& x, int m, vector<char>& y, int n) {
    vector<int> prev(n+1, 0), curr(n+1, 0);
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(x[i-1] == y[j-1]) {
                curr[j] = 1 + prev[j-1];
            } else {
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }
    return curr[n];
}
// Longest Increasing Subsequence (O(n^2))
pair<int, vector<int>> LIS(vector<int>& A) {
    int n = A.size();
    vector<int> L(n, 1), parent(n, -1);
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(A[i] > A[j] && L[j]+1 > L[i]) {
                L[i] = L[j]+1;
                parent[i] = j;
            }
        }
    }
    int longest=0, Li=0;
    for(int i=0; i<n; i++) {
        if(L[i] > longest) {
            longest = L[i];
            Li = i;
        }
    }
    vector<int> r;
    int idx = Li;
    while(idx != -1) {
        r.push_back(A[idx]);
        idx = parent[idx];
    }
    reverse(r.begin(), r.end());
    return {longest, r};
}
int main() {
    string sx = "ABCBDAB";
    string sy = "BDCABA";
    vector<char> x(sx.begin(), sx.end());
    vector<char> y(sy.begin(), sy.end());
    int m = x.size();
    int n = y.size();

    cout << "Strings: " << sx << " , " << sy << "\n";

    // Bottom-up with b matrix
    pair<vector<vector<int>>, vector<vector<char>>> result = LCS(x, m, y, n);
    vector<vector<int>> c = result.first;
    vector<vector<char>> b = result.second;

    cout << "Bottom-up LCS length = " << c[m][n] << "\n";
    cout << "Bottom-up LCS sequence = ";
    print_lcsLCS(b, x, m, n);
    cout << "\n";

    // Optimal LCS without b
    vector<vector<int>> c2 = opt_LCS(x, m, y, n);
    cout << "Optimal LCS length = " << c2[m][n] << "\n";
    cout << "Optimal LCS sequence = ";
    print_opt_LCS(x, y, c2, m, n);
    cout << "\n";

    // Iterative reconstruction
    vector<char> seq = n_print_opt_LCS(x, y, c2, m, n);
    cout << "Iterative reconstruction = ";
    for(char ch : seq) cout << ch;
    cout << "\n";

    // Top-down
    cout << "Top-down LCS length = " << top_down_LCS(x, m, y, n) << "\n";

    // Two-row optimization
    cout << "Two-row LCS length = " << bottom_up_twoRow(x, m, y, n) << "\n";

    // LIS demo
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    pair<int, vector<int>> lisResult = LIS(arr);
    int len = lisResult.first;
    vector<int> lisSeq = lisResult.second;

    cout << "LIS length = " << len << "\n";
    cout << "LIS sequence = ";
    for(int v : lisSeq) cout << v << " ";
    cout << "\n";

    return 0;
}