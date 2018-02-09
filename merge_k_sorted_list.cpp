/*priority queue(heap)*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
    struct HP {
        int idx, val;
    };

    static bool cmp(const HP& a, const HP& b) {
        return a.val > b.val;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        static const int INF = 99999999;
        int slen = 0;
        for (int i = 0; i < lists.size(); i ++) {
            for (ListNode *x = lists[i]; x != NULL; x = x->next) {
                slen ++;
            }
        }

        HP hp[slen + 1];
        int sz = 0;
        for (int i = 0; i < lists.size(); i ++) {
            if (lists[i]) {
                hp[++ sz].val = lists[i]->val;
                hp[sz].idx = i;
                push_heap(hp + 1, hp + 1 + sz, cmp);
                lists[i] = lists[i]->next;
            }
        }

        ListNode *head = NULL, *now;
        int v1, v2, v, tlen = 0;
        while (tlen < slen) {
            tlen ++;
            int min_idx, min_val;
            min_idx = hp[1].idx;
            min_val = hp[1].val;
            pop_heap(hp + 1, hp + 1 +sz, cmp);
            sz --;
            if (lists[min_idx]) {
                hp[++ sz].val = lists[min_idx]->val;
                hp[sz].idx = min_idx;
                push_heap(hp + 1, hp + 1 + sz, cmp);
                lists[min_idx] = lists[min_idx]->next;
            }

            if (head) {
                ListNode *p = new ListNode(min_val);
                now->next = p;
                now = p;
            }
            else {
                ListNode *p = new ListNode(min_val);
                now = head = p;
            }
        }
        return head;
    }
};