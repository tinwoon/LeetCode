class Solution {
public:
    double ret_pow(double x, int n){
        if(n == 1 || n == -1) return x;
        
        if(n % 2) return ret_pow(x * x, n / 2) * x;
        
        else return ret_pow(x * x, n / 2);
        
    }
    
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n < 0) return 1/(ret_pow(x, n));
        else return ret_pow(x , n);
    }
};