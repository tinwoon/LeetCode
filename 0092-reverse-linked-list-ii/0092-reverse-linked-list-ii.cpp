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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        
        ListNode* Node = head, *p_Node = nullptr, *n_Node = nullptr;
        std::vector<ListNode*> NODE;
        
        for(int k=0; k < left - 1; k++){
            p_Node = Node;
            Node = Node->next;
        }
        
        for(int k = left; k <= right; k++){
            n_Node = Node->next;
            NODE.emplace_back(Node);
            Node = Node -> next;
        }
        
        for(int k = NODE.size() - 1; k >= 0; k--){
            if(k == (NODE.size() - 1) && p_Node) p_Node->next = NODE[k];
            NODE[k] -> next = ((k==0) ? (n_Node) : (NODE[k-1]));
        }
        
        if(left == 1) head = NODE[NODE.size()-1];
        
        return head;
    }
};