class Solution {
public:
    std::vector< std::vector<int> > calculate(int numRows){
        std::vector< std::vector<int> > ret(numRows, std::vector<int>());
        
        for(int row = 0; row < numRows; row++){
            ret[row].assign(row + 1, 1);
            
            for(int col = 0; col < row; col++){
                ret[row][col] = (col >= 1 ? (ret[row - 1][col - 1]) : 0) + ret[row - 1][col];
            }
        }
        
        return ret;
    }
    
    vector<vector<int>> generate(int numRows) {
        return calculate(numRows);
    }
};