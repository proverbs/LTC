// classic
// Trie

class Solution {
public:
    struct Node {
        int son[2];
        Node() {
            son[0] = son[1] = -1;
        }
    };
    
    int findMaximumXOR(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<Node> t;
        int res = 0;
        t.push_back(Node());
        insert(t, 0, nums[0]);
        for (int i = 1; i < nums.size(); i ++) {
            res = max(res, findMax(t, 0, nums[i]));
            insert(t, 0, nums[i]);
        }
        return res;
    }
    
    int findMax(vector<Node>& t, int x, int num) {
        int res = 0;
        for (int i = 30; i >= 0; i --) {
            int z = (num >> i) & 1;
            if (~t[x].son[!z]) {
                x = t[x].son[!z];
                res |= 1 << i;
            } else {
                x = t[x].son[z];
            }
            
        }
        return res;
    }
    
    void insert(vector<Node>& t, int x, int num) {
        for (int i = 30; i >= 0; i --) {
            int z = (num >> i) & 1;
            if (t[x].son[z] == -1) {
                t.push_back(Node());
                t[x].son[z] = t.size() - 1;
            }
            x = t[x].son[z];
        }
    }
};