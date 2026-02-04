class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<char>x(text1.begin(),text1.end());
        vector<char>y(text2.begin(),text2.end());
        vector<int>c1(n+1,0),c2(n+1,0);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(x[i-1]==y[j-1])c2[j]=1+c1[j-1];
                else c2[j]=max(c1[j],c2[j-1]);
            }
            c1=c2;
        }
        return c2[n];
    }
};
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        if(m==0||n==0)return 0;
        vector<char>x(text1.begin(),text1.end());
        vector<char>y(text2.begin(),text2.end());
        return LCS(x,y,m,n);
    }
    int LCS(vector<char>&x,vector<char>&y,int m,int n){
        vector<int>c1(n+1,0),c2(n+1,0);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(x[i-1]==y[j-1])c2[j]=1+c1[j-1];
                else if(c1[j]>=c2[j-1]) c2[j]=c1[j];
                else c2[j]=c2[j-1];
            }
            c1=c2;
        }
        return c2[n];
    }
};