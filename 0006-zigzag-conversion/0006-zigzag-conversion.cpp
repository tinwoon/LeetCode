class Solution {

    
public:
    
    std::vector< std::vector<char> > map;

    string convert(string s, int numRows) {
        int idx = 0, x = 0, y = 0;
        int size = s.size();
        string ans = "";
        map.assign(numRows, std::vector<char>(size, ' '));
        
        if(numRows == 1) return s;
        
        while(idx < size){
            for(int k=0; k < numRows-1; k++){
                if(idx < size) map[x++][y] = s[idx++];
            }
            
            for(int k=0; k < numRows-1; k++){
                if(idx < size) map[x--][y++] = s[idx++];
            }
        }
        
        for(int i=0; i < numRows; i++){
            for(int j=0; j < size; j++){
                if(map[i][j] != ' '){
                    ans.push_back(map[i][j]);
                }
            }
        }
        
        return ans;
    }
};