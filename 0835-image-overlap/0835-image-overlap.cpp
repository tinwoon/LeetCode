class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;

        for (int nx = -(n - 1); nx <= n - 1; nx++) {
            for (int ny = -(n - 1); ny <= n - 1; ny++) {
                int count = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        int ni = i + nx;
                        int nj = j + ny;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            if (img1[ni][nj] == 1 && img2[i][j] == 1) {
                                count++;
                            }
                        }
                    }
                }
                ans = std::max(ans, count);
            }
        }

        return ans;
    }
};