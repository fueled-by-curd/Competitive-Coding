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
    ListNode* middleNode(ListNode* head) 
    {
        struct ListNode* tmp = head;
        struct ListNode* hd = head;
        
        int l=0;
        if( head == NULL)
            return NULL;
        
        
        while( tmp != NULL)
        {
            l++;
            tmp = tmp->next;
        }
        
        int mid = l/2;
        
        
        for(int i=0;i<mid;i++)
            hd = hd->next;
        
        
        //cout << hd->val << endl;
        return hd;
   }    
        
        
        
    
};