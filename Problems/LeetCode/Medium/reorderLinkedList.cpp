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
    
    void reorderList(ListNode* head) 
    {
        if( head == NULL || head->next == NULL)
            return;
        unordered_map <int, ListNode*> List;
        
        int count = 0;
        ListNode* tmp = head;
        for( int i = 0 ; tmp != NULL ; tmp=tmp->next, i++, count++ )
            List[i] = tmp;
        
        tmp = head;
        ListNode* a = NULL;
        ListNode* b = NULL;
        for( int i = 0 ; i <= count/2  ; tmp=tmp->next, i++ )
        {
            
            a = List[i];
            if( b != NULL)
                b->next = a;
            
            if( i != count - i - 1)
                b = List[count - i  - 1];
            
            a->next = b ;
            if( b!= NULL)
                b->next = NULL;
            
        }
        
        if( a != NULL)
        {
            b->next = a;
            a->next = NULL;
        }

    }
};

/*
class Solution {
public:
    void reorderList(ListNode *head) 
    {
        if (head == NULL) return;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *curr = slow;
        ListNode *prev = NULL, *temp;
        while (curr != NULL) 
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode *first = head;
        ListNode *second = prev;
        while (second->next != NULL) 
        {
            temp = first->next;
            first->next = second;
            first = temp;
            temp = second->next;
            second->next = first;
            second = temp;
        }
    }
};
*/
