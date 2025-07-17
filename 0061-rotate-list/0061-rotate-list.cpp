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
    ListNode* rotateRight(ListNode* head, int k) {
        int sz = 0;
        ListNode* node = head;
        while (node) {
            sz++;
            node = node->next;
        }
        if(sz == 0 ) return head; 
        k = k % sz;
        if (k == 0)
            return head;
        int pos = sz - k;
        node = head;
        ListNode* start = nullptr;
        int cur = 0;
        while (node) {
            cur++;
            if (cur == pos) {
                start = node->next;
               
                node->next = nullptr;
                break;
            }

            node = node->next;
        }
             ListNode* ans = start ; 
            while (start->next) {
                 start = start->next;
            }
        if (start)
            start->next = head;

        return ans;
    }
};