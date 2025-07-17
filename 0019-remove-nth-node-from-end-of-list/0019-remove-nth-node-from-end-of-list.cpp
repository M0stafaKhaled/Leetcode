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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz =0 ; 
        ListNode * node = head ; 
        while(node)
        {
            sz++;
            node = node->next ; 
        }

        int pos = (sz - n)+1 ; 
        int cur =0 ; 
        ListNode * prev  = nullptr;
        node = head ;  
         while(node)
        {
            cur++;
            if(cur == pos)
            {
            if(prev)
            {
                 prev->next = node->next ; 
                 break ; 
            }
                head= head->next ; 
          

            }
            prev = node ; 
            node = node->next ; 
        }


        return head ; 

    }
};