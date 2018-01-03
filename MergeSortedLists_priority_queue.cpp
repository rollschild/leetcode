/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct Compare {
            bool operator()(const ListNode* lhs, const ListNode* rhs) {
                return lhs->val > rhs->val;
            }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // now let's try priority_queue
        priority_queue< ListNode*, vector<ListNode*>, Compare > pq;
        for(auto p : lists) {
            if(p != nullptr)
                pq.push(p);
        }
        ListNode* listnodes = nullptr;
        if(!pq.empty())
            listnodes = pq.top();
        pq.pop();
        if(listnodes == nullptr) return nullptr;
        // we cannot ignore the first list:
        if(listnodes->next != nullptr) pq.push(listnodes->next);
        
        ListNode* p = listnodes;
        while(!pq.empty()) {
            p->next = pq.top();
            pq.pop();
            p = p->next;
            if(p->next != nullptr) {
                pq.push(p->next);
                
            }
        }
        return listnodes;
    }
};
