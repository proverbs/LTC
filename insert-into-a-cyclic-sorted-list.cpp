/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            Node* h = new Node(insertVal);
            h->next = h;
            return h;
        } else {
            Node *p_max = head, *p_min = head;
            Node *p = head->next;
            while (p != head) {
                if (p->val > p_max->val) p_max = p;
                if (p->val < p_min->val) p_min = p;
                p = p->next;
            }
            if (insertVal > p_min->val  && insertVal < p_max->val) {
                p = p_min;
                while (p->next->val < insertVal) p = p->next;
                Node *q = p->next;
                p->next = new Node(insertVal);
                p->next->next = q;
            } else {
                p = p_max;
                while (p->next->val > p_min->val) p = p->next;
                Node *q = p->next;
                p->next = new Node(insertVal);
                p->next->next = q;
            }
            return head;
        }
    }
};