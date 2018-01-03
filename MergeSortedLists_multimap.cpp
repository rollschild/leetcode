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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // multimap version
        multimap<int, ListNode*> nodes;
        for(auto p : lists) {
            if(p != nullptr)
                nodes.insert(make_pair(p->val, p));
        }
        ListNode* listnodes = nullptr;
        ListNode* p = nullptr;
        while(!nodes.empty()) {
            
            multimap<int, ListNode*>::iterator itr = nodes.begin();
            if(listnodes == nullptr) {
                // listnodes now is the head;
                // we don't change the head
                listnodes = itr->second;
                p = listnodes;
            }
            else {
                p->next = itr->second;
                p = p->next;
            }
            if(itr->second->next != nullptr) {
                nodes.insert(make_pair(itr->second->next->val, itr->second->next));
            }
            nodes.erase(itr);
        }
        return listnodes;
    }
};
