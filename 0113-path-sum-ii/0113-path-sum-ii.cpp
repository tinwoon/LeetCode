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
    
    void calculate(TreeNode* Node, int remain_v, std::vector<int> ret){        
        std::vector<int> cpy_right = ret, cpy_left = ret;
        
        if((remain_v - (Node->val)) == 0){
            if((Node -> left == nullptr) && (Node->right == nullptr)){
                ret.emplace_back(Node->val);
                ans.emplace_back(ret);
                return;
            }
        }
        
        if(Node->left != nullptr){
            cpy_left.emplace_back(Node->val);
            calculate(Node->left, remain_v - (Node->val), cpy_left);
        }
        if(Node->right != nullptr){
            cpy_right.emplace_back(Node->val);
            calculate(Node->right, remain_v - (Node->val), cpy_right);
        }
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return ans;
        
        calculate(root, targetSum, std::vector<int>());
        return ans;
    }
};