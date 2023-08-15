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
    std::vector< std::vector<int> > ans = std::vector< std::vector<int> >(2000, std::vector<int>());
    
    void calculate(int level, TreeNode* root){
        if(root -> left != nullptr){
            calculate(level + 1, root -> left);
        }
        if(root -> right != nullptr){
            calculate(level + 1, root -> right);
        }
        ans[level].emplace_back(root->val);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector< std::vector<int> > ret = {};
        
        if(root == nullptr) return ret;
        
        calculate(0, root);
        
        for(auto itr = ans.begin(); (itr != ans.end()) && (!(*itr).empty()); itr++){
            ret.emplace_back(*itr);
        }
        
        return ret;
    }
};