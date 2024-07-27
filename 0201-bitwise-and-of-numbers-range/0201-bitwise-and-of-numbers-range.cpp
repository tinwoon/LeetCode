class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ret = 0;
        
        for(int k = 30; k >=0; k--){
            int l_b = (left & (1<<k));
            int r_b = (right & (1<<k));
            if(l_b != r_b) break;
            
            ret += (l_b);
        }
        
        return ret;
    }
};