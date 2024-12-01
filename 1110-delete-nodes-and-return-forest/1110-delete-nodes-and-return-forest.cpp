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
    vector<TreeNode*> ans;
    
    void calculate(TreeNode* Node, TreeNode* U_Node, vector<int>& to_delete){
        bool consist_of_del = !!(std::count(to_delete.begin(), to_delete.end(), Node->val));
        
        if(!U_Node && !consist_of_del){
            ans.emplace_back(Node);
        }
        
        if(consist_of_del && U_Node){
            if(U_Node->left){
                if(U_Node->left->val == Node->val) U_Node->left = nullptr;
            }
            if(U_Node->right){
                if(U_Node->right->val == Node->val) U_Node->right = nullptr;
            }
        } 
        
        if(Node->left) calculate(Node->left, consist_of_del ? nullptr : Node, to_delete);
        if(Node->right) calculate(Node->right, consist_of_del ? nullptr : Node, to_delete);
        
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        calculate(root, nullptr, to_delete);
        return ans;
    }
};