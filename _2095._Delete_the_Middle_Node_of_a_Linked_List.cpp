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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head->next;

        if(second == nullptr) return second;
        

        while( second != nullptr && second->next != nullptr && second->next->next != nullptr ) {
            first = first->next;
            second = second->next->next;
        }

        ListNode* temp = first->next;
        first->next = temp->next;
        delete temp;

        return head;
    }
};