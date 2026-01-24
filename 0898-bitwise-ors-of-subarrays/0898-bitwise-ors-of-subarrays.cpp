class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        std::set<int> all;
        std::set<int> cur;

        cur.emplace(arr[0]);
        all.emplace(arr[0]);

        for (int i = 1; i < arr.size(); i++) {
            std::set<int> next_cur;
            next_cur.emplace(arr[i]);
            for (auto itr = cur.begin(); itr != cur.end(); ++itr) {
                next_cur.emplace(*itr | arr[i]);  
            }
            cur = next_cur;
            for (auto x : cur) {
                all.emplace(x);
            }
        }

        return (int)all.size();
    }
};