#include <vector>
#include <utility>
#include <algorithm>

class Solution {
public:
    int maximumProfit(std::vector<int>& present, std::vector<int>& future, int budget) {
        // 아이템의 {이득, 비용}을 저장할 벡터
        std::vector<std::pair<int, int>> items;
        for (int k = 0; k < present.size(); ++k) {
            int profit = future[k] - present[k];
            int cost = present[k];
            // 이득이 있는 아이템만 고려합니다.
            if (profit > 0) {
                items.push_back({profit, cost});
            }
        }

        // dp[j] = 예산 j를 써서 얻을 수 있는 최대 이익
        std::vector<int> dp(budget + 1, 0);

        // 각 아이템에 대하여
        for (const auto& item : items) {
            int profit = item.first;
            int cost = item.second;
            
            // 예산을 거꾸로 순회하며 DP 테이블을 갱신합니다.
            // (같은 아이템을 여러 번 선택하는 것을 방지하기 위함)
            for (int j = budget; j >= cost; --j) {
                // 현재 아이템을 사는 경우(dp[j - cost] + profit)와 
                // 사지 않는 경우(dp[j]) 중 더 큰 이익을 선택
                dp[j] = std::max(dp[j], dp[j - cost] + profit);
            }
        }

        // dp 배열의 모든 값은 각 예산 한도 내에서의 최대 이익을 의미하므로,
        // 그 중 최댓값이 정답이 됩니다.
        return *std::max_element(dp.begin(), dp.end());
    }
};