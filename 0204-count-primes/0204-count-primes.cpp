class Solution {
public:
    int calculate(int n){
        std::vector<bool> visited(n + 1, false);
        int ret = ((n <= 1) ? (0) : (n - 2));
        
        for(int k = 2; k*k < n; k++){
            if(!visited[k]){
                for(int s = k*2; s < n; s+=k){
                    if(!visited[s]){
                        visited[s] = true;
                        ret--;
                    }
                }
            }
        }
        
        return ret;
    }
    
    int countPrimes(int n) {
        return calculate(n);
    }
};