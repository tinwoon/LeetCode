class Trie {
public:
    std::vector<std::string> data; 
    
    Trie() {
        data.clear();
    }
    
    void insert(string word) {
        data.emplace_back(word);
    }
    
    bool search(string word) {
        return std::count(data.begin(), data.end(), word);
    }
    
    bool startsWith(string prefix) {
        for(int k=0; k < data.size(); k++){
            if(data[k].find(prefix) == 0) return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */