/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void research(std::map<int, std::vector<int> > &data, TreeNode* node, bool l_first, int level){
        if(node->left != nullptr) data[level].emplace_back(node->left->val);
        if(node->right != nullptr) data[level].emplace_back(node->right->val);
        if(node->left != nullptr) research(data, node->left, false, level + 1);
        if(node->right != nullptr) research(data, node->right, false, level + 1);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root == nullptr) return std::vector<std::vector<int>>();
        
        std::map<int, std::vector<int> > data;
        std::vector< std::vector<int> > ret;
        bool revert = true;
        
        research(data, root, false, 1);
        
        if(data.size() != 0) ret.assign(data.size() + 1, std::vector<int>());
        else ret.assign(1, std::vector<int>());
        ret[0] = std::vector<int>{root->val};
        
        for(auto itr = data.begin(); itr != data.end(); itr++){
            printf("%d\n", (itr->second)[0]);
            if(revert){
                std::reverse(itr->second.begin(), itr->second.end());
            } 
            ret[itr->first] = itr->second;
            revert = !revert;
        }
        
        return ret;
    }
};