class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        // P[i] = nums[0] + ... + nums[i-1], P[0] = 0
        vector<long long> P(n + 1, 0);
        for (int i = 0; i < n; i++) {
            P[i + 1] = P[i] + nums[i];
        }

        deque<int> dq; // s 후보 인덱스 저장 (P값 단조증가 유지)
        int minLen = INT_MAX;

        for (int e = 0; e <= n; e++) {
            // Rule 1: P[e] - P[front] >= k → 답 발견, front 제거
            while (!dq.empty() && P[e] - P[dq.front()] >= k) {
                minLen = min(minLen, e - dq.front());
                dq.pop_front();
            }

            // Rule 2: P[e] <= P[back] → e가 더 좋은 후보, back 제거
            while (!dq.empty() && P[e] <= P[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(e);
        }

        return minLen == INT_MAX ? -1 : minLen;
    }
};