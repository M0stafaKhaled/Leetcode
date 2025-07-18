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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode * node1 = head ; 
        ListNode * node2  = new ListNode(0); 
         ListNode * node3 = node2 ;  
        int listSize = 0 ; 
        vector<int> arr ;
        while(node1)
        {
            arr.push_back(node1->val);
            node1=node1->next ; 
            listSize++;
        }
        if(k>arr.size()) return head ;
        int n = 0 ;
         n =arr.size();
        for(int i =0 ; i< n ;i+=k)
        {   int start = i ; 
            
            int d = k -1; 
           
            while((d+1)/2 >0 && i+k-1 <arr.size())
            {
                int t =  arr[start] ;
                arr[start] =  arr[start+(d)];
                arr[start+(d)] = t ;
              
                start++;
                d-=2;
            }
        }
       
          for(int i =0 ; i< n ;i++)
          {
              node2->next = new ListNode(arr[i]);
             node2= node2->next ;
           
          }
        return node3->next ; 
    }
};