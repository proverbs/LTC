/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string res;
    int p;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        res.clear();
        dfs(root);
        return res;
    }
    
    void dfs(TreeNode *x) { // preoeder
        if (!x) res += "#,";
        else {
            char ca[10];
            sprintf(ca, "%d", x->val);
            res = res + string(ca) + ",";
            dfs(x->left);
            dfs(x->right);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        p = 0;
        return dedfs(data);
    }
    
    TreeNode* dedfs(string& s) {
        
        string t;
        while (s[p] <= '9' && s[p] >= '0') t.push_back(s[p ++]);
        p += 1;
        if (t.length() == 0) {
            p ++;
            return NULL;
        }
        
        int a;
        sscanf(t.c_str(), "%d", &a);
        TreeNode *x = new TreeNode(a);
        TreeNode *lt = dedfs(s);
        TreeNode *rt = dedfs(s);
        x->left = lt;
        x->right = rt;
        return x;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));