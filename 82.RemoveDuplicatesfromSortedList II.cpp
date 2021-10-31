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
    ListNode* deleteDuplicates(ListNode* head) 
    {

        
       ListNode* nlist = new ListNode();
       ListNode* temp = head;
       head = nlist;
        
        
       while (temp)
       {
           if (temp->next && temp->val == temp->next->val)
           {
               while (temp->next && temp->val == temp->next->val)
                   temp= temp->next;
           
           
           temp = temp->next;
           }
           else
           {
               nlist->next = temp;
               nlist = nlist->next;
               temp = temp->next;
           }
           
           nlist->next = temp;
       }
    
        return head->next;
    }
};
