/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        std::set<ListNode*> Node;
        ListNode* ret = head;
        
        if(head == nullptr) return nullptr;
        
        while(ret->next != nullptr){
            if(Node.count(ret)) return ret;
            
            Node.emplace(ret);
            ret = ret->next;
        }
        
        return nullptr;
    }
};