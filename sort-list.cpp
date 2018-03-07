/*merge sort with linked list*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int sz = 0;
        ListNode* t = head, *mid = head;
        while (t != NULL) t = t->next, sz ++;
        if (sz == 0 || sz == 1) return head;
        sz = sz -1 >> 1;
        while (sz --) mid = mid->next;
        t = mid->next;
        mid->next = NULL;// important
        // cout << head->val << "  " << t->val << endl;
        ListNode* lt = sortList(head);
        ListNode* rt = sortList(t);
        
        // merge
        ListNode* x = new ListNode(0);
        ListNode* y = x;
        while (lt != NULL || rt != NULL) {
            if (lt == NULL) {
                x->next = rt;
                x = rt;
                rt = rt->next;
            } else if (rt == NULL) {
                x->next = lt;
                x = lt;
                lt = lt->next;
            } else {
                if (lt->val < rt->val) {
                    x->next = lt;
                    x = lt;
                    lt = lt->next;
                } else {
                    x->next = rt;
                    x = rt;
                    rt = rt->next;
                }
            }
        }
        x = y->next;
        delete y;
        return x;
    }
};

int main() {
    ListNode* x = new ListNode(2);
    x->next = new ListNode(1);
    Solution().sortList(x);
    return 0;
}