class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    std::vector< std::vector<bool> > visited;
    
    bool calculate(int x, int y, int level, vector<vector<char>>& board, string word){
        bool ret = false;
        visited[x][y] = true;
        if(level == (word.size() - 1)) return true;
        
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()){
                if(!visited[nx][ny] && (board[nx][ny] == word[level+1])){
                    ret |= calculate(nx, ny, level + 1, board, word);
                }
            }
        }
        visited[x][y] = false;
        return ret;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i < board.size(); i++){
            for(int j=0; j < board[0].size(); j++){
                if(word[0] == board[i][j]){
                    visited.assign(board.size(), std::vector<bool>(board[0].size(),false));
                    if(calculate(i, j, 0, board, word)) return true;
                } 
            }
        }
        return false;
    }
};