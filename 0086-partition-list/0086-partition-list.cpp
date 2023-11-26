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
    ListNode* partition(ListNode* head, int x) {
        std::queue<int> L_queue, R_queue;
        ListNode* node = head;
        
        while(node != nullptr){
            if(node -> val >= x){
                R_queue.emplace(node->val);
            }else L_queue.emplace(node->val);
            node = node -> next;
        }
        
        node = head;
        
        while(node != nullptr){
            if(!L_queue.empty()){
                node->val = L_queue.front();
                L_queue.pop();
            }else{
                node-> val = R_queue.front();
                R_queue.pop();
            }
            node = node->next;
        }
        return head;
    }
};