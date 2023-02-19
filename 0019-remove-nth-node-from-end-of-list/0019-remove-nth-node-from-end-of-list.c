/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode_prv{
    struct ListNode_prv *prev;
    struct ListNode_prv *next;
    struct ListNode* Node;
}ListNode_prv;

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode_prv* tail = (ListNode_prv*)malloc(sizeof(ListNode_prv));
    tail-> prev = NULL;
    struct ListNode* ret = head;
    while(head != NULL){
        tail -> next = (ListNode_prv*)malloc(sizeof(ListNode_prv));
        tail -> next -> prev = tail;
        tail -> Node = head;
        head = head -> next;
        tail = tail -> next;
    }
    for(int k=0;k < n+1; k++){
        tail = tail -> prev;
    }
    //tail이 head 이전이 아닌 경우 
    if(tail != NULL) tail -> Node -> next = tail -> Node -> next -> next;
    //tail이 head 이전인 경우
    else ret = ret -> next;
    return ret;
}