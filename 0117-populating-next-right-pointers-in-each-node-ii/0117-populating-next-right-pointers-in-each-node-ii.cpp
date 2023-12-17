/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    std::map< int, std::vector<Node*> > data;
    int m_l = INT_MIN;
    
    void search(Node* node, int level){
        if(node == nullptr) return;
        
        m_l = std::max(level, m_l);
        data[level].emplace_back(node);
        
        search(node->left, level+1);
        search(node->right, level+1);
        
        return;
    }
    
    Node* connect(Node* root) {
        search(root, 0);
        
        for(int l = 0; l <= m_l; l++){
            for(int k = 0; k < (int)(data[l].size() - 1); k++){
                data[l][k]->next = data[l][k+1]; 
            }
        }
        return root;
    }
};