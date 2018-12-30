// bfs: right child comes first

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    typedef pair<TreeLinkNode*, int> pr; // <node, depth>
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<pr> q;
        int cur_dep = 0;
        TreeLinkNode *last;
        q.push({root, 1});
        while (!q.empty()) {
            TreeLinkNode *x = q.front().first;
            int dep = q.front().second;
            q.pop();
            if (dep == cur_dep) x->next = last, last = x;
            else cur_dep = dep, x->next = NULL, last = x;
            if (x->right) q.push({x->right, dep + 1});
            if (x->left) q.push({x->left, dep + 1});
        }
    }
};