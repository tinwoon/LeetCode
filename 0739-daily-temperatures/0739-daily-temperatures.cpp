class Solution {
public:
    std::vector<bool> visited;
    std::vector<int> ans;
    int N;

    void dfs(int node, vector<int>& temperatures){
        visited[node] = true;

        for(int n_node = node + 1; n_node < N; n_node++){
            if(temperatures[node] < temperatures[n_node]){
                ans[node] = n_node - node;
                dfs(n_node, temperatures);
                break;
            }
        }
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        N = temperatures.size();
        visited.assign(N, false);
        ans.assign(N, false);

        for(int k=0; k < N; k++){
            if(!visited[k]){
                dfs(k, temperatures);
            }
        }

        return ans;
    }
};