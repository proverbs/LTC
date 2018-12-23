/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) return NULL;
        Node *h, *t;
        dfs(root, h, t);
        return h;
    }
    
    void dfs(Node *root, Node* &h, Node* &t) {
        Node *lt = root->left;
        Node *rt = root->right;
        h = t = root;
        root->left = root;
        root->right = root;
        
        if (lt) {
            Node *ah, *at;
            dfs(lt, ah, at);
            concat(ah, at, h, t);
            h = ah;
        } 
        
        if (rt) {
            Node *ah, *at;
            dfs(rt, ah, at);
            concat(h, t, ah, at);
            t = at;
        } 
    }
    
    void concat(Node *la, Node *ra, Node *lb, Node *rb) {
        ra->right = lb;
        lb->left = ra;
        rb->right = la;
        la->left = rb;
    }
};