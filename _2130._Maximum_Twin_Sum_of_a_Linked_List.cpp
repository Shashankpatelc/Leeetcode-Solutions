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
    int pairSum(ListNode* head) {
        int max_sum = INT_MIN;

        ListNode* one_step = head;
        ListNode* head2 = head;

        while( head2 != nullptr && head2->next != nullptr ) {
            one_step = one_step->next;
            head2 = head2->next->next;
        }
        
        if( head2 != nullptr) head2 = head2->next;

        while( one_step != nullptr ) {
            ListNode* next = one_step->next;
            one_step->next = head2;
            head2 = one_step;
            one_step = next;
        }

        while( head2 != nullptr ) {
            max_sum = max(max_sum, head->val + head2->val);
            head = head->next;
            head2 = head2->next;
        }

        return max_sum;
    }
};