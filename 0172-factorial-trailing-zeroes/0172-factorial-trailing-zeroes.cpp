class Solution {
public:
    long long two_count = 0, five_count = 0;

    void prime_factorization(int num){
        while(1){
            if(num % 2 == 0){
                two_count++;
                num /= 2;
            }else if(num % 5 == 0){
                five_count++;
                num /= 5;
            }else{
                break;
            }
        }
    } 

    int trailingZeroes(int n) {
        for(int k=1; k <= n; k++){
            prime_factorization(k);
        }

        return std::min(two_count, five_count);
    }
};