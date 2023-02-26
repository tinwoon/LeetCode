/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* list = head;
    
    if(list1 == NULL && list2 == NULL) return NULL;
    
    while(list1 != NULL && list2 != NULL){
        if(list1 -> val <= list2 -> val){
            list -> next = list1;
            list1 = list1-> next;
        }else{
            list -> next = list2;
            list2 = list2 -> next;
        }
        list = list -> next;
    }    
    
    if(list1 != NULL){
        list-> next = list1;
    }
    if(list2 != NULL){
        list->next = list2;
    }
    return head -> next;
}