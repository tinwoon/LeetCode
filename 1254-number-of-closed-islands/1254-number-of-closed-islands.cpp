class Solution {
public:
    std::vector< std::vector<bool> > visited;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    bool dfs(int x, int y, vector<vector<int>>& grid){
        bool ret = true;
        std::queue< std::pair<int, int> > q;
        q.emplace(std::make_pair(x,y));
        visited[x][y] = true;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            for(int k=0; k < 4; k++){
                int nx = node.first + dx[k];
                int ny = node.second + dy[k];
                
                if(nx >= 0 && nx < grid.size() && ny >=0 && ny < grid[0].size()){
                    if(!visited[nx][ny] && !grid[nx][ny]){
                        visited[nx][ny] = true;
                        q.emplace(std::make_pair(nx, ny));
                    }
                }else{
                    ret = false;
                }
            }
        }
        
        return ret;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int ret = 0;
        visited.assign(grid.size(), std::vector<bool>(grid[0].size(), false));
        
        for(int i=0; i< grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(!visited[i][j] && !grid[i][j]){
                    ret += dfs(i,j, grid);
                }
            }
        }
        
        return ret;
    }
};