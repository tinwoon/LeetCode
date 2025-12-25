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
    int ans = 0;

    void search_node(TreeNode* node, int consecutive_v){
        ans = std::max(ans, consecutive_v);

        if(node -> right){
            search_node(node->right, (node->val + 1) == (node -> right ->val) ? consecutive_v + 1 : 1);
        }

        if(node -> left){
            search_node(node->left, (node->val + 1) == (node -> left ->val) ? consecutive_v + 1 : 1);
        }
    }

    int longestConsecutive(TreeNode* root) {
        search_node(root, 1);

        return ans;
    }
};