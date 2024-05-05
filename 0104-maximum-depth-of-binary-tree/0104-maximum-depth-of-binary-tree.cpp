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
    int depth(TreeNode* node, int level){
        if((node->left == nullptr) && (node -> right == nullptr)) return level;
        
        int ret = level;
        if(node->left != nullptr) ret = std::max(ret, depth(node->left, level+1));
        if(node->right != nullptr) ret = std::max(ret, depth(node->right, level+1));
        
        return ret;
    }
    
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return depth(root, 1);
    }
};