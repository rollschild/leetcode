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
    int carry = 0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // int carry = 0;
        int sub_sum = 0;
        if(l1 == nullptr && l2 == nullptr && carry == 0) {
            return nullptr;
        }
        else if(l1 == nullptr && l2 == nullptr && carry != 0) {
            sub_sum += carry;
            carry = 0;
        }
        else if(l2 == nullptr) {
            sub_sum = (l1->val + carry)%10;
            carry = (l1->val + carry)/10;
        }
        else if(l1 == nullptr) {
            sub_sum = (l2->val + carry)%10;
            carry = (l2->val + carry)/10;
        }
        else {
            sub_sum = (l1->val + l2->val + carry)%10;
            carry = (l1->val + l2->val + carry)/10;
        }
        ListNode* sum = new ListNode(sub_sum);
        if(l1 == nullptr && l2 == nullptr) 
            sum->next = addTwoNumbers(nullptr, nullptr);
        else if(l1 == nullptr)
            sum->next = addTwoNumbers(nullptr, l2->next);
        else if(l2 == nullptr)
            sum->next = addTwoNumbers(l1->next, nullptr);
        else 
            sum->next = addTwoNumbers(l1->next, l2->next);
        return sum;
    }
};
