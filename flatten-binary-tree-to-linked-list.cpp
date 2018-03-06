/*dfs*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        lk(root);
    }

    pair<TreeNode*, TreeNode*> lk(TreeNode* x) {
        //cout << x->val << endl;
        pair<TreeNode*, TreeNode*> lt = make_pair((TreeNode*)NULL, (TreeNode*)NULL);
        pair<TreeNode*, TreeNode*> rt = make_pair((TreeNode*)NULL, (TreeNode*)NULL);
        if (x->left != NULL) lt = lk(x->left); 
        if (x->right != NULL) rt = lk(x->right);
        TreeNode* ed = x;
        x->left = NULL;
        if (lt.first != NULL) {
            ed->right = lt.first;
            ed = lt.second;
        }
        if (rt.first != NULL) {
            ed->right = rt.first;
            ed = rt.second;
        }
        return make_pair(x, ed);
    }
};

int main() {
    TreeNode* x = new TreeNode(1);
    x->left = new TreeNode(2);
    x->left->right = new TreeNode(3);
    Solution().flatten(x);
    cout << x->right << "  " << x->right->right << endl;
    return 0;
}