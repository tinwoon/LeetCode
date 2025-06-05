class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        std::priority_queue< std::pair<int, int> > pq;
        std::vector<int> sub_arr_start_idx;
        std::map<int, int> prev_sub_arr_idx;
        int sum = std::accumulate(nums.begin() + k - 1, nums.end(), 0);
        int ret = INT_MAX;
        int max_arr_v = INT_MIN;

        for(int start_idx = 0; start_idx < k - 1; start_idx++){
            pq.emplace(std::make_pair(nums[start_idx], start_idx));
            sub_arr_start_idx.emplace_back(start_idx);
            max_arr_v = std::max(max_arr_v, nums[start_idx]);
        }
        pq.emplace(std::make_pair(sum, k - 1));
        sub_arr_start_idx.emplace_back(k - 1);
        ret = max_arr_v = std::max(max_arr_v, sum);

        //가장 큰 값이 첫번째 sub array가 아니고, 가장 큰 값의 첫번째 인덱스가 마지막 원소여서, 아래 sub array에게 줄 수 없을 때가 아니면, 그리고 해당 값을 줬을 때, 내가 값이 없어지는게 아니면
        while(pq.top().second != 0 && (pq.top().second != nums.size() - 1) && (pq.top().first - nums[pq.top().second])){
            std::sort(sub_arr_start_idx.begin(), sub_arr_start_idx.end());
            max_arr_v = INT_MIN;
            auto node = pq.top();
            pq.pop();

            std::vector< std::pair<int, int> > c_sub_arr;
            auto find_idx = std::find(sub_arr_start_idx.begin(), sub_arr_start_idx.end(), node.second);
            int prev_sub_arr_idx = std::distance(sub_arr_start_idx.begin(), find_idx) - 1;

            while(pq.top().second != sub_arr_start_idx[prev_sub_arr_idx]){
                c_sub_arr.emplace_back(pq.top());
                pq.pop();
            }

            auto child = pq.top();
            pq.pop();

            child = std::make_pair(child.first + nums[node.second], child.second);
            node = std::make_pair(node.first - nums[node.second], node.second + 1);
        
            *find_idx = node.second;

            pq.emplace(child);
            pq.emplace(node);
            
            max_arr_v = std::max({child.first, node.first, max_arr_v});

            while(!c_sub_arr.empty()){
                max_arr_v = std::max(max_arr_v, c_sub_arr.back().first);
                pq.emplace(c_sub_arr.back());
                c_sub_arr.pop_back();
            }

            ret = std::min(max_arr_v, ret);
        }
        
        return ret;
    }
};