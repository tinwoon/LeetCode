class Solution {
public:
    std::vector< std::vector<bool> > visited;
    int N, M;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    void calculate(int i, int j, vector<vector<char>>& board){
        
        std::queue< std::pair<int, int> > visited_node;
        std::queue< std::pair<int, int> > q;
        visited[i][j] = true;
        q.emplace(std::make_pair(i,j));
        bool is_included = true;
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            visited_node.emplace(front);
            int x = front.first, y = front.second;
            
            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if(nx < 0 || nx >= N || ny < 0 || ny >= M){
                    is_included = false;
                }else if(board[nx][ny] == 'O' && !visited[nx][ny]){        
                    visited[nx][ny] =  true;
                    q.emplace(std::make_pair(nx, ny));
                }
            }
        }
        
        if(is_included){
            while(!visited_node.empty()){
                auto front = visited_node.front();
                visited_node.pop();
                
                board[front.first][front.second] = 'X';
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        N = board.size();
        M = board[0].size();
        visited.assign(N, std::vector<bool>(M, false));
        
        for(int i=0; i < board.size(); i++){
            for(int j=0; j < board[i].size(); j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    calculate(i, j, board);
                }
            }
        }
        
    }
};