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
    //현재까지의 거쳐간 Node의 value의 합, 거쳐간 Node의 합
    std::pair<int,int> calculate(TreeNode* Node){
        int Node_sum = Node->val, Node_count = 1;
        std::pair<int, int> ret;
        
        if(Node->left){
            ret = calculate(Node->left);
            Node_sum += ret.first;
            Node_count += ret.second;
        } 
        if(Node->right){
            ret = calculate(Node->right);
            Node_sum += ret.first;
            Node_count += ret.second;
        }
        
        ans += (Node->val == (int)(Node_sum / Node_count));
        
        return std::make_pair(Node_sum, Node_count);
    }
    
    int averageOfSubtree(TreeNode* root) {
        calculate(root);
        
        return ans;
    }
};