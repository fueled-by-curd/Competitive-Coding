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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int carry=0;
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        //ruct ListNode* head;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        
        int ans = 0;
        int a = 0;int b = 0;
        int sum = 0;
        int f = 0;
        vector<struct ListNode* > v;
        
        while(tmp1 != NULL && tmp2 != NULL)
        {
            a = tmp1->val;
            b = tmp2->val;
            sum = a+b+carry;
            carry = sum/10;
            tmp1->val = sum%10;
            tmp2->val = sum%10;
            
            p1 = tmp1;
            p2 = tmp2;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        
        if(tmp1 == NULL)
        {
            f=1;
            while( tmp2 != NULL)
            {
                b = tmp2->val;
                sum = b+carry;
                carry = sum/10;
                tmp2->val = sum%10;
                p2 = tmp2;
                tmp2 = tmp2->next;
            }
            if( carry !=0 && p1 != NULL)
            {
                p1->val = carry;
                p2->next = p1;
            }
            return l2;
        }
        else if(tmp1 != NULL)
        {
            while( tmp1 != NULL)
            {
                b = tmp1->val;
                sum = b+carry;
                carry = sum/10;
                tmp1->val = sum%10;
                p1 = tmp1;
                tmp1 = tmp1->next;
            }
            if( carry !=0 && p2 != NULL)
            {
                p2->val = carry;
                p1->next = p2;
            }
            return l1;
                
        }
        
        if(f !=0)
        {
            if(carry !=0 && p2 !=NULL)
            {
                p2->val = carry;
                p1->next = p2;
            }
            return l1;
        }
        else
        {
            if(carry !=0 && p1 !=NULL)
            {
                p1->val = carry;
                p2->next = p1;
            }
            return l2;
            
        }
        
        
        //return head; 
        
        
    }
    
};