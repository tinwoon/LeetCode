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
    ListNode* get_prv_node(ListNode* head){
        ListNode* ret = head;
        
        while(ret->next->next != nullptr){
            ret = ret->next;
        }
        return ret;
    }
    
    ListNode* calculate(ListNode* head){
        if(head == nullptr || head -> next == nullptr) return head;
        
        ListNode* prev_node = get_prv_node(head);
        ListNode* final_node = prev_node -> next;
        
        final_node-> next = head;
        head = final_node;
        prev_node -> next = nullptr;
        
        return head;
    }
    
    int ListNode_size(ListNode* head){
        int cnt = 0;
        while(head != nullptr){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        int n = ListNode_size(head);
        int cnt = (n == 0 || n == 1) ? 0 : k % n;
        while(cnt--){
            head = calculate(head);
        }
        return head;
    }
};