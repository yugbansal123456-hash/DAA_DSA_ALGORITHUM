//when n is multiple of 2 .similarly we can also make for 3 also using same logic.
#include<iostream>
#include<vector>
using namespace std;
void matrixmul(vector<vector<int>>&A,vector<vector<int>>&B,vector<vector<int>>&M,int ra,int ca,int rb,int cb,int rm,int cm,int n){
    if(n==1){
        M[rm][cm]=M[rm][cm]+A[ra][ca]*B[rb][cb];
        return;
    }
    //M00=A00*B00+A01*B10
    //M01=A00*B01+A01*B11
    //M10=A10*B00+A11*B10
    //M11=A10*B01+A11*B11
    int i=n/2;
    matrixmul(A,B,M,ra,ca,rb,cb,rm,cm,i);
    matrixmul(A,B,M,ra,ca,rb,cb+i,rm,cm+i,i);
    matrixmul(A,B,M,ra+i,ca,rb,cb,rm+i,cm,i);
    matrixmul(A,B,M,ra+i,ca,rb,cb+i,rm+i,cm+i,i);
    matrixmul(A,B,M,ra,ca+i,rb+i,cb,rm,cm,i);
    matrixmul(A,B,M,ra,ca+i,rb+i,cb+i,rm,cm+i,i);
    matrixmul(A,B,M,ra+i,ca+i,rb+i,cb,rm+i,cm,i);
    matrixmul(A,B,M,ra+i,ca+i,rb+i,cb+i,rm+i,cm+i,i);
}
int main() {
    int n = 4; // must be a power of 2 for this version
    vector<vector<int>> A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<vector<int>> B = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    vector<vector<int>> M(n, vector<int>(n, 0));

    // Multiply A and B into M
    matrixmul(A, B, M, 0, 0, 0, 0, 0, 0, n);

    // Print result
    cout << "Result matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
//in 3 multiple there will be 27 recursive calls