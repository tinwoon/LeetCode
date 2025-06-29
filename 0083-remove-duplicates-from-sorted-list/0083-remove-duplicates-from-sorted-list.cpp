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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;

        ListNode* node = head;

        while(node->next != nullptr){
            ListNode* n_node = node->next;
            if(n_node->val == node->val){
                node->next = n_node->next;
                delete n_node;
            }else{
                node = node->next;
            }
        }

        return head;
    }
};