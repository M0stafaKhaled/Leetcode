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
    int getDecimalValue(ListNode* head) {
        int sz = 0;
        auto node = head;

        while (node) {
            sz++;
            node = node->next;
        }

        node = head;
        int ans = 0;
        while (node) {
            sz--;
            int val = node->val * pow(2, sz);
            ans += val;
            node = node->next;
        }
        return ans;
    }
};