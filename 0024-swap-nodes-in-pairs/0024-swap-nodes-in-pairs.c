/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* tmp;
    struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    ret -> next = head;
    struct ListNode* node = ret; 
    
    while((node -> next != NULL) && (node -> next -> next != NULL)){
        tmp = node -> next -> next;
        node -> next -> next = tmp -> next;
        tmp -> next = node -> next;
        node -> next = tmp;
        node = node -> next -> next;
    }
    
    return ret -> next;
    
}