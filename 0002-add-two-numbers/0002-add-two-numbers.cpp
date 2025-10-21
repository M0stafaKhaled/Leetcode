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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node1 = l1 ; 
        ListNode* node2 = l2 ; 
        ListNode* node3 = new ListNode(-1) ;
        ListNode* node4 = node3;
        string s1 ="" ;
        string s2 ="";
        int re = 0 ;
        bool first = true ; 
        while(l1 && l2)
        {
            int d =re ;
            
            d+=l1->val  + l2->val; 
            if(d>=10) 
            {
                int tem = d%10 ; 
                re=d/10 ; 
                d = tem ; 
            } else re=0;
            node3->next = new ListNode(d); 
            node3=node3->next;
            l1=l1->next ; 
            l2=l2->next ; 
        }

         while(l1)
        {
            int d =re ;
            d+=l1->val; 
            if(d>=10) 
            {
                int tem = d%10 ; 
                re=d/10 ; 
                d = tem ; 
            } else re=0;
            node3->next = new ListNode(d); 
            node3=node3->next;
            l1=l1->next ;  
        }

           while(l2)
        {
            int d =re ;
            d+=l2->val; 
            if(d>=10) 
            {
                int tem = d%10 ; 
                re=d/10 ; 
                d = tem ; 
            }
            else re=0;
            node3->next = new ListNode(d); 
            node3=node3->next;
            l2=l2->next ;  
        }

        if(re>0)node3->next = new ListNode(re);


            return node4->next;

    }
};