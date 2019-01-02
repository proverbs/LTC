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
    ListNode* middleNode(ListNode* head) {
        ListNode* p = head;
        int len = 0;
        while (p) len ++, p = p->next;
        len >>= 1;
        p = head;
        while (len --) p = p->next;
        return p;
    }
};