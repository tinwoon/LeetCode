class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.insert(wordList.begin(), beginWord);

        int begin_w_idx = 0, end_w_idx = -1;
        int ans = 0;
        int length = wordList.size();

        std::vector< std::vector<int> > connection(wordList.size(), std::vector<int>());;
        std::vector<bool> visited(wordList.size(), false);
        std::queue< std::pair<int, int> > q; 

        for(int i= 0; i < length; i++){
            if(wordList[i] == endWord) {
                end_w_idx = i;
            }
            if(i != 0 && (wordList[i] == beginWord)) continue;

            for(int j= i + 1; j < length; j++){
                if(wordList[j] == beginWord) continue;

                int diff_c = 0;

                for(int k=0; k < beginWord.size(); k++){
                    if(wordList[i][k] != wordList[j][k]) diff_c++;
                }

                if(diff_c == 1){
                    connection[i].emplace_back(j);
                    connection[j].emplace_back(i);
                }
            }
        }

        if(end_w_idx == -1) return 0;

        q.emplace(std::make_pair(begin_w_idx, 1));
        visited[begin_w_idx] = true;

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            int idx = front.first;
            int nums = front.second;

            if(idx == end_w_idx) return nums;

            for(int k=0; k < connection[idx].size(); k++){
                int n_idx = connection[idx][k];

                if(!visited[n_idx]){
                    visited[n_idx] = true;
                    q.emplace(std::make_pair(n_idx, nums + 1));
                }
            }
        }

        return 0;
    }
};