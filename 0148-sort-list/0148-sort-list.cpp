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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        // 1  ,2 ,3 ,  4
        //
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* right = slow->next;
        slow->next = nullptr;
        ListNode* left = head;

        ListNode* node1 = sortList(left);
        ListNode* node2 = sortList(right);

        ListNode* dum = new ListNode(0);
        ListNode* dum2 = dum;
        while (node1 && node2) {
            if (node1->val < node2->val) {
                dum->next = node1;
                node1 = node1->next;
            } else {
                dum->next = node2;
                node2 = node2->next;
            }
            dum = dum->next;
        }

        while (node1) {
            dum->next = node1;
            node1 = node1->next;
            dum = dum->next;
        }

        while (node2) {
            dum->next = node2;
            node2 = node2->next;
            dum = dum->next;
        }

        return dum2->next;
    }
};