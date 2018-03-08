/*pointer operation*/

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
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        int sz = 0;
        ListNode* t = head;
        while (t) t = t->next, sz ++;
        if (sz & 1) {
            t = head;
            sz >>= 1;
            while (sz --) t = t->next;
            ListNode* x = rev(t);
            t->next = NULL;
            return check(head, x);
        } else {
            t = head;
            sz = (sz - 1) >> 1;
            while (sz --) t = t->next;
            ListNode* x = rev(t->next);
            t->next = NULL;
            return check(head, x);
        }
    }

    ListNode* rev(ListNode* x) {
        if (x == NULL) return x;
        if (x->next == NULL) return x;
        else {
            ListNode* y = rev(x->next);
            x->next->next = x;
            return y;
        }
    }

    bool check(ListNode* x, ListNode* y) {
        while (x != NULL && y != NULL) {
            if (x->val != y->val) return false;
            x = x->next;
            y = y->next;
        }
        return true;
    }
};