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
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set<ListNode *>st ; 

        ListNode * node = head ; 
        while(node)
        {
            if(st.find(node) != st.end())
            return node ; 

            st.insert(node) ; 
            node = node->next ; 
        }
        return nullptr ; 
    }
};