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
    int getLength(ListNode *head) {
        int n = 0;
        while (head) n += 1, head = head->next;
        return n;
    }
    ListNode *merge_sort(ListNode *head, int n) {
        if (n <= 1) return head;
        int l = n / 2, r = n - l;
        ListNode *p = head, *p1, *p2, ret;
        for (int i = 1; i < l; i++) p = p->next;
        p1 = head; p2 = p->next;
        p->next = NULL;
        p1 = merge_sort(p1, l);
        p2 = merge_sort(p2, r);
        p = &ret; ret.next = NULL;
        while (p1 || p2) {
            if (p2 == NULL || (p1 && p1->val <= p2->val)) {
                p->next = p1;
                p = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p = p2;
                p2 = p2->next;
            }
        }
        return ret.next;
    }
    ListNode* sortList(ListNode* head) {
        int n = getLength(head);
        return merge_sort(head, n);
    }
};