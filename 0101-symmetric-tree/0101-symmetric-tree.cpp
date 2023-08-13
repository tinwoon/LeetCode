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
    
    std::vector< std::pair<int, int> > calculate(TreeNode* root, int level){
        std::vector< std::pair<int,int> > left, right;
        
        bool l_mpt = false, r_mpt = false;
        
        if(root -> left != nullptr){
            left = calculate(root->left, level + 1);
        }else l_mpt = true;
        
        if(root -> right != nullptr){
            right = calculate(root->right, level + 1);
        }else r_mpt = true;
        
        if(l_mpt && r_mpt){
        }else {
            if(l_mpt) left.emplace_back(std::make_pair(101, level + 1));
            if(r_mpt) right.emplace_back(std::make_pair(101, level + 1));
        }
        
        left.emplace_back(std::make_pair(root->val, level));
        
        for(int k=0; k < right.size(); k++){
            left.emplace_back(right[k]);
        }
        return left;
    }
    
    bool isSymmetric(TreeNode* root) {
        std::vector< std::pair<int,int> > ans = calculate(root, 0);
        
        int lft_idx = 0, rgh_idx = ans.size() - 1;
        
        while(lft_idx <= rgh_idx){
            if(ans[lft_idx] != ans[rgh_idx]) return false;
            lft_idx++;
            rgh_idx--;
        }
        return true;
    }
};