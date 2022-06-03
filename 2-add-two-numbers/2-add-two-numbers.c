/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    struct ListNode* l = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head = l;
    int upper_v = 0;
    
    while(1){
       struct ListNode* l_next = (struct ListNode*)malloc(sizeof(struct ListNode));
       int l1_v, l2_v;
       l1_v = (l1 == NULL) ? 0 : l1->val;
       l2_v = (l2 == NULL) ? 0 : l2->val;
       l->val  = (l1_v + l2_v + upper_v)%10;
       upper_v = (l1_v + l2_v + upper_v) >= 10 ? 1 : 0;
       l1 = (l1 != NULL) ? l1->next : NULL;
       l2 = (l2 != NULL) ? l2->next : NULL;
       
       if(upper_v || l1 != NULL || l2 != NULL){
         l->next = l_next;
         l = l_next;
       }else{
         l->next = NULL;
         break;
       } 
        
    }
    
    return head;
}