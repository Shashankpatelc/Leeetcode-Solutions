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
    ListNode* deleteDuplicates(ListNode* head) {

        if ( head == nullptr || head->next == nullptr)
            return head;
        
        int val = head->val;
        ListNode* temp_head = head;
        ListNode* next_node = head->next;

        while(next_node != nullptr) {
            if( next_node->val == val ) {
                next_node = next_node->next;
            } else {
                val = next_node->val;
                temp_head = temp_head->next;
                temp_head->val = val;
            }
        }

        temp_head->next = nullptr;

        return head;
    }
};