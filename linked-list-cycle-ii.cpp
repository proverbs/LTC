/*two pointers, math*/
/*typical, 非常巧妙！*/
/*https://leetcode.com/problems/linked-list-cycle-ii/discuss/44781/Concise-O(n)-solution-by-using-C++-with-Detailed-Alogrithm-Description*/

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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *a, *b;
        a = b = head;
        int k = 0;
        while (a != NULL && b != NULL) {
            a = a->next;
            b = b->next;
            if (b == NULL) return NULL;
            b = b->next;
            k ++;
            if (a == b) {
                ListNode* c = head;
                while (a != c) a = a->next, c = c->next;
                return a;
            }
        }
        return NULL;
    }
};