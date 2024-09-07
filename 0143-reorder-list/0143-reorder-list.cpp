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
    void reorderList(ListNode* head) {
        ListNode* node = head;
        int start = 0, end = 0;
        std::vector< ListNode* > arr_node;
        
        while(node != nullptr){
            arr_node.emplace_back(node);
            node = node->next;
        }
        end = arr_node.size() - 1;
    
        for(; end - start > 1;){
            node = arr_node[start++];
            node->next = arr_node[end--];
            node->next->next = arr_node[start];
        }
        arr_node[end] -> next = nullptr;
        
        
    }
};