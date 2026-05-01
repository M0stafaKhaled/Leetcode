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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        ListNode* node = head;

        while (node) {
            size++;
            node = node->next;
        }

        int rem = 0;
        if (k < size) {
            rem = size % k;
        }
        int buk = max(size / k, 1);
        cout << rem << buk << endl;
        node = head;
        vector<ListNode*> ans;
        while (node) {
            ListNode* cur = node;
            ans.push_back(cur);
            int f = buk - 1;
            while (f-- && cur->next) {
                cur = cur->next;
            }
            if (rem > 0) {
                rem--;
                cur = cur->next;
            }

            if (cur) {
                ListNode* temp = cur->next;
                cur->next = nullptr;
                node = temp;
            }
        }
        int diff = k - size;
        while (diff > 0) {
            ans.push_back(nullptr);
            diff--;
        }

        return ans;
    }
};