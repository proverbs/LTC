/*pointer*/
/**
 * 有一个巧妙的one pass 方法（其实也不是one pass）
 * p1走n-1步，然后p2从头走，同事p1继续走，直到p1为null，此时p2指向的为需要删除的节点
*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *q = head;
        while (q) {
            q = q->next;
            len ++;
        }
        n = len - n;
        if (n == 0) return head->next;
        n --;
        ListNode *p = head;
        while (n --) {
            p = p->next;
        }
        q = p->next;
        p->next = q ? q->next : q;
        return head;
    }
};