/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "#,"; // # denotes backtracking
        string res;
        dfs_ser(root, res);
        // cout << res << endl;
        return res;
    }
    
    void dfs_ser(Node *x, string &res) {
        res += to_string(x->val)  + ",";
        for (Node *y : x->children)
            dfs_ser(y, res);
        res += "#,";
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        int idx = 0;
        return dfs_des(data, idx);
    }
    
    Node* dfs_des(string &s, int &idx) {
        if (s[idx] == '#') {
            idx += 2;
            return NULL;
        } else {
            int num = 0;
            while (s[idx] >= '0' && s[idx] <= '9') num = num * 10 + s[idx ++] - '0';
            idx ++;
            Node *x = new Node(num, vector<Node*>());
            while (true) {
                Node *y = dfs_des(s, idx);
                if (y) x->children.push_back(y);
                else break;
            }
            return x;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));