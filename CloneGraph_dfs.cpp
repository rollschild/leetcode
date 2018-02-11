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
    unordered_map< UndirectedGraphNode*, UndirectedGraphNode*> mp;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) return nullptr;
        if(!mp.count(node)) {
            mp[node] = new UndirectedGraphNode(node->label);
            for(auto ptr : node->neighbors) {
                mp[node]->neighbors.push_back(cloneGraph(ptr));
            }
        }
        return mp[node];
    }
};
