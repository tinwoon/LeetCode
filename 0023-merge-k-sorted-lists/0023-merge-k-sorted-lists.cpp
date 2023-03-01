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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        //value, index
        std::priority_queue< std::pair<int,int> > pq;
        ListNode* list = (ListNode*)malloc(sizeof(ListNode));
        list -> next = NULL;
        ListNode* head = list;
        
        
        if(!lists.size()){
            return NULL;
        } 
        
        for(int idx=0; idx < lists.size(); idx++){
            if(lists[idx] != NULL) pq.emplace(std::make_pair(-1*(lists[idx] -> val),idx));
        }
        
        //if list is not empty at list
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int val = front.first;
            int idx = front.second;
            list->next = lists[idx];
            lists[idx] = lists[idx] -> next;
            list = list -> next;
            
            if(lists[idx] != NULL) pq.push(make_pair(-1*(lists[idx]->val), idx));
        }
        
        return head -> next;
    }
};