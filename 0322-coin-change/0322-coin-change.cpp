class Solution {
public:
    int calculate(int coin_v, std::vector<int>& coins, std::vector<int>& dp){
        if(coin_v < 0) return (INT_MAX - 1);
        if(dp[coin_v] != INT_MAX - 1) return dp[coin_v];

        for(int k=0; k < coins.size(); k++){
            dp[coin_v] = std::min(calculate(coin_v - coins[k], coins, dp) + 1, dp[coin_v]);
        }

        return dp[coin_v];
    }

    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, INT_MAX - 1);
        int ans = 0;
        dp[0] = 0;

        for(int k=0; k < coins.size(); k++){
            if(coins[k] <= amount) dp[coins[k]] = 1;
        }

        //ans = calculate(amount, coins, dp);

        for(int i = 1; i <= amount; i++){
            for(int j =0 ; j < coins.size(); j++){
                if(i - coins[j] >= 0) dp[i] = std::min(dp[i], dp[i-coins[j]] + 1);
            }
        }

        ans = dp[amount];

        return ans != (INT_MAX - 1) ? ans : -1;
    }
};