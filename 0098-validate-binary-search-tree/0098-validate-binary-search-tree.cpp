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
    bool calculate(long long min, long long max, TreeNode* root){
        bool ans = true;
        int val = root->val;
        if(root -> left != nullptr){
            int l_val = root->left->val;
            if((l_val < val) && (l_val > min) && (l_val < max)){
                ans &= calculate(min, (long long)val, root -> left);
            }else return false;
        }
        if(root -> right != nullptr){
            int r_val = root->right->val;
            if((r_val > val) && (r_val > min) && (r_val < max)){
                ans &= calculate((long long)val, max, root -> right);
            }else return false;
        }
        return ans;
    }
    
    bool isValidBST(TreeNode* root) {
        return calculate(LLONG_MIN, LLONG_MAX, root);
    }
};