/*bfs*/

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
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        vector<TreeLinkNode*> q;
        q.push_back(root);
        int lt = 0, rt = 0, cnt = 0;
        while (cnt < q.size()) {
            TreeLinkNode* x = q[cnt ++];
            if (x->left != NULL) q.push_back(x->left);
            if (x->right != NULL) q.push_back(x->right);
            if (cnt > rt) {
                for (int i = lt; i < rt; i ++) {
                    q[i]->next = q[i + 1];
                }
                q[rt]->next = NULL;
                lt = cnt;
                rt = q.size() - 1;
            }
        }
    }
};