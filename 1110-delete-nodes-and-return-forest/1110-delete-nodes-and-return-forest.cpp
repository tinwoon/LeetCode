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
        
        printf("Node : %d\n", Node->val);
        printf("U_Node : %p\n", U_Node);
        printf("consist_of_del : %b\n\n", consist_of_del);
        
        if(!U_Node && !consist_of_del){
            ans.emplace_back(Node);
        }
        
        if(consist_of_del && U_Node){
            if(U_Node->left){
                printf("U_Node->left : %d\n\n", U_Node->left->val);
                if(U_Node->left->val == Node->val) U_Node->left = nullptr;
            }
            if(U_Node->right){
                printf("U_Node->right : %d\n\n", U_Node->right->val);
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