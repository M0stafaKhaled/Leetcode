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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* node = head;
       // ListNode* node = cur;
        unordered_map<int, ListNode*> map;
        ListNode* dum = new ListNode(0);
        dum->next = head;
        int sum = 0;
        map[0] = dum;
        while (node) {
            int val = node->val;
            sum += val;
            map[sum] = node;
            node = node->next;
        }

        ListNode* dum2 = dum;
         sum = 0;
        while (dum2) {
            int val = dum2->val;
            sum += val;
            if (map.find(sum) != map.end()) {
                dum2->next = map[sum]->next;
            }
            dum2 = dum2->next;
        }

        return dum->next;
    }
};