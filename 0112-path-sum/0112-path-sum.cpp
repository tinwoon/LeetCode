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
    
    bool calculate(TreeNode* Node, const int targetSum, int sum){
        if(Node -> left == nullptr && Node -> right == nullptr){
            return targetSum == sum;   
        }
        
        bool ret = false;
        
        if(Node->left != nullptr){
            ret |= calculate(Node -> left, targetSum, sum + Node->left->val);
        }
        if(Node->right != nullptr){
             ret |= calculate(Node -> right, targetSum, sum + Node->right->val);
        }
        
        return ret;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        return calculate(root, targetSum, root->val);
    }
};