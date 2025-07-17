/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* node = head;
        ListNode* prev = nullptr;
        while (node && node->next) {
            ListNode* cur = node->next;
            bool re = false;
            while (cur && node->val == cur->val) {
                cur = cur->next;
                re = true;
            }
            if (re) {
                if (prev) {
                    prev->next = cur;
                } else {
                    head = cur;
                }
    
                node = cur;
            } else {
                prev=node ; 
            
                node = node->next;
            }
        }

        return head;
    }
};