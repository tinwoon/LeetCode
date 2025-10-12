class Solution {
public:
    int dx[2] = {-1, 1};
    int dy[2] = {1, -1};
    int m, n;

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        std::queue< std::pair<int, int> > q;
        std::vector<int> ans;
        m = mat.size();
        n = mat[0].size();

        q.emplace(std::make_pair(0,0));
        //if false, direction is right of top, else left of bottom
        bool direction = false;

        while(!q.empty()){
            auto node = q.front();
            int x = node.first;
            int y = node.second;
            q.pop();
            ans.emplace_back(mat[x][y]);

            int nx = x + dx[direction];
            int ny = y + dy[direction];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n){
                if(!direction){
                    if(y + 1 < n){
                        q.emplace(std::make_pair(x, y + 1));
                    }else if(x + 1 < m){
                        q.emplace(std::make_pair(x + 1, y));
                    }
                }else{
                    if(x + 1 < m){
                        q.emplace(std::make_pair(x + 1, y));
                    }else if(y + 1 < n){
                        q.emplace(std::make_pair(x, y + 1));
                    }
                }

                direction = !direction;
            }else{
                q.emplace(std::make_pair(nx, ny));
            }
        }

        return ans;
    }
};