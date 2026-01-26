class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i = 0; i < n; i++) {
            unordered_set<char> check;
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '.') continue;
                if(check.find(board[i][j]) != check.end()) return false;
                check.insert(board[i][j]);
            }
        }
        for(int j = 0; j < n; j++) {
            unordered_set<char> check;
            for(int i = 0; i < n; i++) {
                if(board[i][j] == '.') continue;
                if(check.find(board[i][j]) != check.end()) return false;
                check.insert(board[i][j]);
            }
        }
        for(int blockRow = 0; blockRow < 3; blockRow++) {
            for(int blockCol = 0; blockCol < 3; blockCol++) {
                unordered_set<char> check;
                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        char c = board[blockRow*3 + i][blockCol*3 + j];
                        if(c == '.') continue;
                        if(check.find(c) != check.end()) return false;
                        check.insert(c);
                    }
                }
            }
        }

        return true;
    }
};