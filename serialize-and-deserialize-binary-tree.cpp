/*树的dfs序列化*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    string serialize(TreeNode* root) {
        ostringstream out; // 一切可输出类型转string的方法
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:

    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' '; 
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val)); // c++ 11 new features
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    TreeNode* a = new TreeNode(1);
    a->left = new TreeNode(2);
    a->right = new TreeNode(3);
    a->right->left = new TreeNode(4);
    a->right->right = new TreeNode(5);
    string s = Codec().serialize(a);
    cout << s << endl;
    TreeNode* b = Codec().deserialize(s);
    cout << b->right->right->val << endl;
    return 0;
}