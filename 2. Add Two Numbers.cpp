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
    char to_char(int n){
        return (char)(n + '0');    
    }
    
    int to_in(char c){
        return (int)(c - '0');
    }
    
    pair<int, char> sum(char a, char b, int rem){
        int sum = to_in(a) + to_in(b) + rem;
        rem = sum/10;
        sum = sum%10;
        return {rem, sum};
    }
    
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        
        int carry=0;
        ListNode* head3 =new ListNode ((head1->val + head2->val + carry)%10);
        carry=(head1->val + head2->val + carry)/10;
        ListNode* t=head3;
        head1=head1->next;
        head2=head2->next;
        while(head1!=NULL || head2!=NULL || carry!=0)
        {
            int sum=carry;
            if(head1!=0){
                sum=sum+head1->val;
                head1=head1->next;
            }
            if(head2!=0){
                sum=sum+head2->val;
                 head2=head2->next;
            }
            carry=sum/10;
            ListNode* n=new ListNode(sum%10);
            t->next=n;
            t=n;
        }
        return head3;
        
    }
};
