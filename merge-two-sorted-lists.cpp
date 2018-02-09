/*monotonicity(merge sorted)*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        static const int INF = 99999999;
        ListNode *head = NULL, *now;
        int v1, v2, v;
        while (l1 || l2) {
            v1 = l1 ? l1->val : INF;
            v2 = l2 ? l2->val : INF;
            if (v1 < v2) {
                v = v1;
                l1 = l1->next;
            }
            else {
                v = v2;
                l2 = l2->next;
            }
            if (head) {
                ListNode *p = new ListNode(v);
                now->next = p;
                now = p;
            }
            else {
                ListNode *p = new ListNode(v);
                now = head = p;
            }
        }
        return head;
    }
};