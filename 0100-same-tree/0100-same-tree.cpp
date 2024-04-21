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
    bool search(TreeNode* p, TreeNode* q){
        bool ret = true;
       
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr && q != nullptr) return false;
        if(p != nullptr && q == nullptr) return false;
        if(p->val != q->val) return false;
        
        ret &= search(p -> left, q -> left);
        ret &= search(p -> right, q -> right);
        
        return ret;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return search(p, q);
    }
};