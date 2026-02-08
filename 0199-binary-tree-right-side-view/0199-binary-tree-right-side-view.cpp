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

#define INVALID INT_MAX

class Solution {
public:
    std::map<int, int> right_v;

    void calculate(TreeNode* node, int level){
        if(node->right){
            if(!right_v.count(level + 1)){
                right_v[level + 1] = node->right->val;
            }
            calculate(node->right, level + 1);
        }
        if(node->left){
            if(!right_v.count(level + 1)){
                right_v[level + 1] = node->left->val;
            }
            calculate(node->left, level + 1);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        if(root) {
            right_v[0] = root->val;
            calculate(root, 0);
        }

        std::vector<int> ans;
        std::vector< std::pair<int, int> > m_to_v(right_v.begin(), right_v.end());

        for(int k=0; k < m_to_v.size(); k++){
            ans.emplace_back(m_to_v[k].second);
        }

        return ans;
    }
};