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

    ListNode *reverse(ListNode *head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        else
        {
            ListNode *rest=reverse(head->next);
            head->next->next=head;
            head->next=NULL;
            return rest;
        }
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }
        else
        {
            ListNode* newnode=reverse(head);
            if(n == 1)
            {
                return reverse(newnode->next);
            }
            ListNode* curr=newnode;
            int i=1;
            while(i != n-1)
            {
                i++;
                curr=curr->next;
            }
            curr->next=curr->next->next;
            ListNode *ans=reverse(newnode);
            return ans;
            
            
        }
    }
};