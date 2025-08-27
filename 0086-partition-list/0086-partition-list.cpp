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
    ListNode* make_copy(ListNode* head) {
        ListNode* copy = new ListNode(head->val);
        ListNode* root = copy;
        head = head->next;
        while (head) {
            copy->next = new ListNode(head->val);
            copy = copy->next;
            head = head->next;
        }

        return root;
    }
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return nullptr;
        ListNode* node = head;
        ListNode* ge = nullptr;
        ListNode* prev = nullptr;
        ListNode* node3 = make_copy(head);
        ListNode* node2 = node3;
        while (node2) {
            if (node2->val < x) {
                if (prev) {
                    prev->next = node2->next;
                } else {
                    node3 = node3->next;
                }
            } else {
                prev = node2;
            }

            node2 = node2->next;
        }
        if (!node3)
            return head;
        node2 = head;
        prev = nullptr;
        while (node2) {
            if (node2->val >= x) {
                if (prev) {
                    prev->next = node2->next;
                } else {
                    head = head->next;
                }
            } else {
                prev = node2;
            }

            node2 = node2->next;
        }
        while (prev && prev->next)
            prev = prev->next;
        if (prev)
            prev->next = node3;
        else
            return node3;
        return head;
    }
};