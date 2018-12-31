// child first

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node *last;
    Node* flatten(Node* head) { // an instance can be used for many times!!!
        if (!head) return head;
        last = NULL;
        return my_flatten(head);
    }
    
    Node* my_flatten(Node* head) {
        for (Node *x = head; x; ) {
            Node *y = x->next;
            if (last) last->next = x;
            x->prev = last;
            last = x;
            if (x->child) {
                x->child->prev = last;
                last->next = x->child;
                my_flatten(x->child);
                x->child = NULL; // bad description
            }
            x = y;
        }
        
        return head;
    }
};
// flatten according to depth

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        Node *prev = NULL;
        unordered_map<Node*, bool> vis;
        queue<Node*> q;
        q.push(head);
        while (!q.empty()) {
            Node *x = q.front();
            cout << x->val << endl;
            q.pop();
            vis[x] = true;
            
            Node *tmp = x;
            if (x->child) q.push(x->child);
            for (Node *y = x->next; y; y = y->next) {
                if (y->child) q.push(y->child);
                tmp = y;
            }
            
            if (prev) prev->next = x;
            x->prev = prev;
            prev = tmp;
        }
        // head->prev = prev;
        //prev->next = head;
        
        Node *z = head;
        while (z) {
            cout << z->val << ", ";
            z = z->next;
        }
        
        return head;
    }
};