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
    std::vector< std::vector< Node* > > data;
    

    void calculate(Node* node, int level){
        if(level == data.size()){
            data.emplace_back(std::vector<Node*>(1, node));
        }else{
            data[level].emplace_back(node);
        }
        
        if(node->left != nullptr){
            calculate(node->left, level+1);
        }
        if(node->right != nullptr){
            calculate(node->right, level+1);
        }
    }
    
    Node* connect(Node* root) {
        
        if(root == nullptr) return root;
        
        calculate(root, 0);
        for(int i=0; i < data.size(); i++){
            for(int j=0; j < (data[i].size() - 1); j++){
                data[i][j]->next = data[i][j + 1];
            }
        }
        return root;
    }
};