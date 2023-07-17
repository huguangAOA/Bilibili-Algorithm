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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1 && right == 1) return head;
        if (left != 1) {
            head->next = reverseBetween(head->next, left - 1, right - 1);
        } else {
            ListNode *tail = head->next, *new_head;
            new_head = reverseBetween(head->next, left, right - 1);
            head->next = tail->next;
            tail->next = head;
            head = new_head;
        }
        return head;
    }
};
