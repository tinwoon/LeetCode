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
    ListNode* init_head(ListNode* head, int k){
        ListNode* ret = head;

        for(int i=0; i < k - 1; i++){
            ret = ret -> next;
        }

        return ret;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p_node = head;
        ListNode* ret = init_head(head, k);
        ListNode* start_node = p_node;
        ListNode* prev_tail = nullptr;

        while(start_node){
            ListNode* n_node = start_node -> next;
            //처음 시작이 reverse 시 end_node로 갈거기 때문
            ListNode* end_node = start_node;
            ListNode* tmp_node;
            p_node = start_node;

            //다음 K 주기의 
            for(int i=0; i < k - 1; i++){
                start_node = start_node -> next;
                if(start_node == nullptr){
                    return ret;
                } 
            }
            
            //다음 start_node의 내용 초기화
            start_node = start_node -> next;
            p_node -> next = start_node;

            for(int i=0; i < k - 1; i++){
                tmp_node = n_node -> next;
                n_node -> next = p_node;
                p_node = n_node;
                n_node = tmp_node;
            }

            if(prev_tail != nullptr) prev_tail->next = p_node;
            end_node -> next = start_node;
            prev_tail = end_node;
        }
        
        return ret;
    }
};