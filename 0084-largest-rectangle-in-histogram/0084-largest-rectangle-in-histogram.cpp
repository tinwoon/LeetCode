class Solution {
public:
    int N;
    std::vector<int> tree;
    vector<int> data;
    int ans;
    
    int init(int node, int start, int end){
        if(start == end) return tree[node] = start;
        
        int mid = (start + end)/2;
        int left_node = init(node*2, start, mid);
        int right_node = init(node*2 + 1, mid+1, end);
        return tree[node] = data[left_node] < data[right_node] ? left_node : right_node;
    }
    
    //start와 end 사이 만큼을 node가 저장하고 있고, left, right 중 최소 index를 얻고 싶음.
    int calculate(int node, int start, int end, int left, int right){
        if(left > end || right < start) return INT_MAX;
        if(left <= start && end <= right) return tree[node];
        
        int mid = (start + end) / 2;
        int left_val = calculate(node*2, start, mid, left, right);
        int right_val = calculate(node*2 + 1, mid + 1, end, left, right);
        if(left_val == INT_MAX) return right_val;
        else if(right_val == INT_MAX) return left_val;
        return  data[left_val] < data[right_val] ? left_val : right_val;
    }
    
    void solve(int left, int right){
        if(left > right) return;
        
        int idx = calculate(1, 0, N-1, left, right);
        ans = std::max(ans, data[idx] * (right - left + 1));
        solve(left, idx - 1);
        solve(idx + 1, right);
    }
    
    int largestRectangleArea(vector<int>& heights) {
        data = heights;
        N = heights.size();
        int tree_size = ceil(log2(N));
	    tree.assign(1 << (tree_size + 1), 0);
        init(1, 0, N - 1);
        solve(0, N - 1);
        return ans;
    }
};