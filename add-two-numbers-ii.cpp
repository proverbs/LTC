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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0;
        ListNode *t = l1, *res;
        while (t) len1 ++, t = t->next;
        t = l2;
        while (t) len2 ++, t = t->next;
        
        if (len1 < len2) {
            swap(l1, l2);
            swap(len1, len2);
        } 
        
        int dlen = len1 - len2;
        if (dlen == 0) {
            res = dfs(l1, l2);
            
            
        } else {
            t = l1;
            dlen --;
            for (int i = 0; i < dlen; i ++) t = t->next;
            res = dfs(t->next, l2);
            ListNode *cp = cplink(l1, t);
            t = cp;
            for (int i = 0; i < dlen; i ++) t = t->next;
            t->next = res;
            res = cp;
        }
        
        int jin = mod(res);
        while (jin) {
            ListNode *z = new ListNode(jin % 10);
            jin /= 10;
            z->next = res;
            res = z;
        }
        return res;
    }
    
    ListNode* dfs(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return NULL;
        ListNode *z = new ListNode(l1->val + l2->val);
        
        ListNode *y = dfs(l1->next, l2->next);
        z->next = y;
        
        return z;
    }
    
    ListNode* cplink(ListNode *a, ListNode *b) {
        if (a == b) {
            return new ListNode(a->val);
        } else {
            ListNode *z = new ListNode(a->val);
            z->next = cplink(a->next, b);
            return z;
        }
    }
    
    int mod(ListNode *a) {
        if (!a) return 0;
        a->val += mod(a->next);
        int res = a->val / 10;
        a->val %= 10;
        return res;
    }
};