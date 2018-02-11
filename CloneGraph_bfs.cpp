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
        // now we try to use BFS
        if(node == nullptr) return nullptr;
        UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
        mp[node] = root;
        queue<UndirectedGraphNode*> adjacent;
        adjacent.push(node); // to be modified
        while(!adjacent.empty()) {
            UndirectedGraphNode*  current = adjacent.front(); // first node
            adjacent.pop(); // now we examine the first node; no to-be-visited for now
            for(auto n : current->neighbors) {
                if(!mp.count(n)) {
                    UndirectedGraphNode* copy = new UndirectedGraphNode(n->label);
                    mp[n] = copy;
                    adjacent.push(n);
                }
                mp[current]->neighbors.push_back(mp[n]);
            }
        }
        return root;
    }
};
