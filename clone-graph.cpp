/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> vis;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        vis.clear();
        return dfs(node);
    }
    
    UndirectedGraphNode* dfs(UndirectedGraphNode *x) {
        UndirectedGraphNode *nx = new UndirectedGraphNode(x->label);
        vis[x] = nx;
        for (int i = 0; i < x->neighbors.size(); i ++) {
            if (!vis.count(x->neighbors[i])) {
                nx->neighbors.push_back(dfs(x->neighbors[i]));
            } else {
                nx->neighbors.push_back(vis[x->neighbors[i]]);
            }
        }
        return nx;
    }
};