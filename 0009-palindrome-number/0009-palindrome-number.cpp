class Solution {
public:
    bool isPalindrome(int x) {
        string X = to_string(x);
        int size = X.size();
        for(int k=0; k < (size/2); k++){
            if(X[k] != X[size - 1 - k]) return false;
        }
        
        return true;
    }
};