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
    int ans = 0;
    
    void search_node(TreeNode* node, int v){
        if(node->left == nullptr && node->right == nullptr){
            ans += v;
            return;
        }
        
        if(node -> left != nullptr){
            search_node(node->left, v*10 + (node->left->val));
        }
        if(node->right != nullptr){
            search_node(node->right, v*10 + (node->right->val));
        }
        
    }
    
    int sumNumbers(TreeNode* root) {
        search_node(root, root->val);
        return ans;
    }
};