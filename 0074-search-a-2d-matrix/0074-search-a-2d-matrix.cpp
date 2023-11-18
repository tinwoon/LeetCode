class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int N = matrix.size();
        
        for(int k=0; (k<N)&&(matrix[k][0] <= target); k++){
            auto itr = std::lower_bound(matrix[k].begin(), matrix[k].end(), target);
            if(itr != matrix[k].end() && *itr == target){
                return true;
            }
        }
        return false;
    }
};