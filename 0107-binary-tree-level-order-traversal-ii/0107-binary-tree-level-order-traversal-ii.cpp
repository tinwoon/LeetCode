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
    std::vector< std::vector<int> > ans;

    void search_node(TreeNode* Node, int level){
        
        if(ans.size() == level) ans.emplace_back(std::vector<int>(1, Node->val));
        else ans[level].emplace_back(Node->val);
        
        if(Node->left != nullptr) search_node(Node->left, level + 1);
        if(Node->right != nullptr) search_node(Node->right, level + 1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr) return ans;
        
        search_node(root, 0);
        std::reverse(ans.begin(), ans.end());
        
        return ans;
    }
};