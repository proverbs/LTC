/*same as "linked list cycle ii" using O(1) space*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA, *b = headB;
        while (a != NULL && b != NULL) {
            a = a->next;
            b = b->next;
        }
        ListNode* t = NULL;
        if (a == NULL) t = b;
        else if (b == NULL) t = a;
        ListNode* p = a == NULL ? headA : headB;
        ListNode* q = a == NULL ? headB : headA;
        while (t != NULL) t = t->next, q = q->next;
        while (p != q) p = p->next, q = q->next;
        return p;
    }
};