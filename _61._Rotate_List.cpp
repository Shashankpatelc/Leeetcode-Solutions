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
    ListNode* rotateRight(ListNode* head, int k) {
        int l = 1;

        if(head == nullptr) return head;

        ListNode * temp = head;
        ListNode * tail = head;

        while(tail->next != nullptr) {
            tail = tail->next;
            l++;
        }

        k %= l;
        l -= k;

        if( k == 0 ) return head;

        tail->next = head;

        while(l--) {
            tail = tail->next;
        }

        ListNode * newNode = tail->next;
        tail->next = nullptr;

        return newNode;
    }
};