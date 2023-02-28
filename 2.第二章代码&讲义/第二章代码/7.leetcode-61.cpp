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
    int getLenght(ListNode *head) {
        int n = 0;
        while (head) {
            n += 1;
            head = head->next;
        }
        return n;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        int n = getLenght(head);
        k %= n;
        if (k == 0) return head;
        ListNode *p = head, *q = head;
        for (int i = 0; i <= k; i++) p = p->next;
        while (p) p = p->next, q = q->next;
        p = q->next;
        q->next = NULL;
        q = p;
        while (q->next != NULL) q = q->next;
        q->next = head;
        return p;
    }
};
