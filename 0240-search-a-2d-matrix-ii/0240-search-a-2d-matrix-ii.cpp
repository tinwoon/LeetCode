class Solution {
public:
    int dx[2] = {0, -1};
    int dy[2] = {1, 0};

    std::pair<int, int> find_overflow_loc(vector<vector<int>>& matrix, int target){
        for(int j=0; j < matrix[0].size(); j++){
            for(int i=0; i < matrix.size(); i++){
                if(matrix[i][j] > target){
                    if(i == 0){
                        return std::make_pair(matrix.size() - 1, j - 1);
                    } else return std::make_pair(i - 1, j);
                }else if(matrix[i][j] == target) return std::make_pair(i, j);
            }
        }

        return std::make_pair(-1, -1);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        std::pair<int, int> index = find_overflow_loc(matrix, target);

        if(matrix[matrix.size() - 1][matrix[0].size() - 1] == target) return true;
        if(index.first == -1 || index.second == -1) return false;

        std::queue< std::pair<int, int> > q;
        q.emplace(index);

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            if(matrix[front.first][front.second] == target){
                return true;
            }

            int nx = front.first + dx[0];
            int ny = front.second + dy[0];

            if(ny < matrix[0].size() && matrix[nx][ny] <= target){
                q.emplace(std::make_pair(nx, ny));
            }else{
                nx = front.first + dx[1];
                ny = front.second + dy[1];

                if(nx >=0){
                    q.emplace(std::make_pair(nx, ny));
                }
            }
        }

        return false;
    }
};