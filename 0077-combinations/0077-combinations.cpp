class Solution {
public:
    int N;
    std::vector< std::vector<int> > ret;
    
    void calculate(int idx, int depth, std::vector<int> v){
        v.emplace_back(idx);

        if(depth == 0){
            ret.emplace_back(v);
            return;
        } 
        
        for(int i = idx + 1; i <= N; i++){
            calculate(i, depth - 1, v);
        }
        
        return;
    }
    
    vector<vector<int>> combine(int n, int k) {
        N = n;
        
        for(int i = 1; i <= N; i++){
            calculate(i, k - 1, std::vector<int>());
        }
        
        return ret;
    }
};