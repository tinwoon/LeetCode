#define INT_MAX_D10 INT_MAX/10

class Solution {
public:
    int reverse(int x) {
        int ans = 0, prev = 0, rest = 0;
        
        while(x != 0){\
            rest = x%10;
            if((ans > INT_MAX_D10) || ((ans == INT_MAX_D10) && (rest > 7))) return 0;
            if((ans < -1*INT_MAX_D10) || ((ans == -1*INT_MAX_D10) && (rest < -8))) return 0;
            ans = (ans * 10) + rest;
            x /= 10;
        }
        return ans;
    }
};