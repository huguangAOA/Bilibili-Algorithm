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
    ListNode* sortList(ListNode* head) {
        if (head == NULL) return head;
        int l = head->val, r = head->val, z;
        ListNode *p = head, *h1 = NULL, *h2 = NULL, *q;
        while (p) l = min(p->val, l), r = max(p->val, r), p = p->next;
        z = (l + r) >> 1;
        if (l == r) return head;
        p = head;
        while (p) {
            q = p->next;
            if (p->val <= z) {
                p->next = h1;
                h1 = p;
            } else {
                p->next = h2;
                h2 = p;
            }
            p = q;
        }
        h1 = sortList(h1);
        h2 = sortList(h2);
        p = h1;
        while (p->next) p = p->next;
        p->next = h2;
        return h1;
    }
};