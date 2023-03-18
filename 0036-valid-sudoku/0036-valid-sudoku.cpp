class Solution {
public:
    bool row(int i, int j, const vector<vector<char>>& board){
        //i는 그대로 j만 확인
        for(int col = 0; col < 9; col++){
            if(board[i][col] == '.') continue;
            if(board[i][j] == board[i][col]){
                if(j != col) return false;
            }
        }
        return true;
    }
    
    bool col(int i, int j, const vector<vector<char>>& board){
        //j는 그대로 i만 확인
        for(int row = 0; row < 9; row++){
            if(board[row][j] == '.') continue;
            if(board[i][j] == board[row][j]){
                if(i != row) return false;
            }
        }
        return true;
    }
    
    bool block(int i, int j, const vector<vector<char>>& board){
        int row = (i/3)*3;
        int col = (j/3)*3;
        
        for(int r = row; r < row + 3; r++){
            for(int c = col; c < col + 3; c++){
                if(board[r][c] == '.') continue;
                if(board[i][j] == board[r][c]){
                    if(i != r || j != c) return false;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i < 9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;
                if(!row(i,j,board) || !col(i,j,board) || !block(i,j,board)) return false;
            }
        }
        return true;
    }
};