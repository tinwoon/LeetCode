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
    void calculate(TreeNode* Node){
        TreeNode* right = nullptr;
        TreeNode* left = nullptr;
        TreeNode* right_end = nullptr;
        
        if(Node -> right != nullptr){
            calculate(Node -> right);
        }
        
        if(Node->left != nullptr){
            calculate(Node->left);
            
            right = Node -> right;
            left = Node -> left;
            right_end = left;
            
            if(right_end != nullptr){
                while(right_end -> right != nullptr){
                    right_end = right_end -> right;
                }
            }
            
            Node->right = left;
            Node->left = nullptr;
            right_end -> right = right;
        }
    }
    
    void flatten(TreeNode* root) {
        if(root != nullptr) calculate(root);
    }
};