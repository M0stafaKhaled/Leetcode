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
    ListNode* solve(ListNode* head, stack<ListNode*>& st) {
        if (!head)
            return head;

        while (st.size() && st.top()->val < head->val) {
            auto top = st.top();
            st.pop();
            if (st.size() >= 1) {
                st.top()->next = top->next;
            }
        }
        st.push(head);
        solve(head->next, st);
        return head;
    }
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        solve(head, st);
        while (st.size() > 1) {
            st.pop();
        }
        return st.top();
    }
};