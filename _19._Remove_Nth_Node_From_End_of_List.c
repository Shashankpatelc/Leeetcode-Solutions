//  Definition for singly-linked list.
 struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    struct ListNode* node = head;
    int i = 1,k = 1;

    if(n == 0){
        return head;
    }

    while (node->next != NULL){
        node = node->next;
        i++;
    }
    
    if(n == i){
        head=head->next;
        return head;
    }

    node = head;
    
    while(k < i - n){
        node = node->next;
        k++;
    }
    
    node->next = node->next->next;
    
    return head;
}