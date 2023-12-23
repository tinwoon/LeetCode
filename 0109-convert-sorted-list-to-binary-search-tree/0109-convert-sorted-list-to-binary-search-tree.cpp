/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    #define CALLOC(X) ((X*)calloc(1,sizeof(X))) 
    
    void init(std::vector<int>& data, ListNode* node){
        while(node != nullptr){
            data.emplace_back(node->val);
            node = node->next;
        }
    }
    
    void calculate(int left, int right, std::vector<int>& data, TreeNode* node, TreeNode* prev, bool is_left){
        if(left > right) return;
        
        int mid = (left + right) / 2;
        node->val = data[mid];
        if(prev != nullptr){
          if(is_left) prev->left = node;
          else prev->right = node;
        } 
        
        TreeNode* L_N = CALLOC(TreeNode);
        TreeNode* R_N = CALLOC(TreeNode);
        
        calculate(left, mid - 1, data, L_N, node, true);
        calculate(mid + 1, right, data, R_N, node, false);
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        
        std::vector<int> data;
        TreeNode* ret = CALLOC(TreeNode);
        
        init(data, head);
        calculate(0, data.size()-1, data, ret, nullptr, false);
        
        return ret;
    }
};