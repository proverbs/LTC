// tipical: only push nodes whose left child has not visited into the stack

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> stk;
    TreeNode *nxt;
    BSTIterator(TreeNode *root) {
        TreeNode *t = root;
        while (t) {
            stk.push(t);
            t = t->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *cur = stk.top();
        stk.pop();
        
        TreeNode *t = cur->right;
        while (t) {
            stk.push(t);
            t = t->left;
        }
        
        return cur->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */