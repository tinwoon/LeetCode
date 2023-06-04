class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        std::queue< std::pair<int, int> > zero;
    
        for(int i=0; i < matrix.size(); i++){
            for(int j=0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0) zero.emplace(std::make_pair(i, j));
            }
        }
        
        while(!zero.empty()){
            auto front = zero.front();
            zero.pop();
            
            int i = front.first;
            int j = front.second;
            
            for(int J=0; J < matrix[i].size(); J++){
                matrix[i][J] = 0;
            }
            
            for(int I=0; I < matrix.size(); I++){
                matrix[I][j] = 0;
            }
        }
    }
};