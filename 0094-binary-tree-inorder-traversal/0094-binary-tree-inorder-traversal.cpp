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
    std::vector<int> tree;
    
    void calculate(TreeNode* node){
        if(node == nullptr) return;
        if(node -> left != nullptr) calculate(node -> left);
        tree.emplace_back(node->val);
        if(node -> right != nullptr) calculate(node -> right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        calculate(root);
        return tree;
    }
};