// it is kind of trick
// the random link pointer is based on the linked list

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        RandomListNode *p, *q;
        for (p = head; p != NULL; p = q->next) {
            q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
        }
        
        for (p = head; p != NULL; p = q->next) {
            q = p->next;
            if (p->random == NULL) q->random = NULL;
            else q->random = p->random->next; // points to the copy
        }
        
        RandomListNode *res = head->next;
        p = head;
        while (1) {
            q = p->next;
            p->next = q->next;
            p = p->next;
            if (p == NULL) break;
            else q->next = p->next;
        }
        return res;
    }
};