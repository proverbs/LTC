// recursion

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        if (grid.size() == 0) return NULL;
        return build(grid, 0, 0, grid.size() - 1, grid.size() - 1);
    }
    
    Node* build(vector<vector<int>>& grid, int lt, int tp, int rt, int bt) {
        int y = lt + rt >> 1;
        int x = tp + bt >> 1;
        Node* now = new Node(grid[x][y], true, NULL, NULL, NULL, NULL);
        if (rt == lt) return now;
        Node* topleft = build(grid, lt, tp, y, x);
        Node* topright = build(grid, y + 1, tp, rt, x);
        Node* bottomleft = build(grid, lt, x + 1, y, bt);
        Node* bottomright = build(grid, y + 1, x + 1, rt, bt);
        if (topleft->isLeaf && topright->isLeaf && bottomleft->isLeaf && bottomright->isLeaf &&
           topleft->val == topright->val && topleft->val == bottomleft->val && topleft->val == bottomright->val)
            free(topleft), free(topright), free(bottomleft), free(bottomright);
        else now->topLeft = topleft, now->topRight = topright, now->bottomLeft = bottomleft, now->bottomRight = bottomright, now->isLeaf = false;
        return now;
    }
};