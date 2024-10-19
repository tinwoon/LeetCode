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
    TreeNode* calculate(TreeNode* Node, int minimum, int maximum){
        if(Node->val >= minimum && Node->val <= maximum){
            TreeNode* ret;
            if(Node->left && (ret = calculate(Node->left, minimum, Node->val))){
                return ret;
            }
            if(Node->right && (ret = calculate(Node->right, Node->val, maximum))){
                return ret;
            }
        }else{
            return Node;
        }
        
        return nullptr;
    }
    
    bool find_answer(TreeNode* Node, TreeNode* Mt_Node, TreeNode* root){
        int ret = false;
        std::swap(Node->val, Mt_Node->val);
        if(calculate(root, INT_MIN, INT_MAX)){
            std::swap(Node->val, Mt_Node->val);
            if(Node->left) ret |= find_answer(Node->left, Mt_Node, root);
            if(Node->right) ret |= find_answer(Node->right, Mt_Node, root); 
        }else ret = true;
        
        return ret;
    }
    
    void swapNode(TreeNode* MT_Node, TreeNode* root){
        if(find_answer(root, MT_Node, root)){
            return;
        }
        
        if(MT_Node->left) swapNode(MT_Node->left, root);
        if(MT_Node->right) swapNode(MT_Node->right, root);
    }
    
    void recoverTree(TreeNode* root) {
        swapNode(root, root);
    }
};