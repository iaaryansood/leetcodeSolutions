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
    ListNode *reverseK(ListNode *head,int k)
    {
        ListNode *curr=head;
        ListNode *prev=NULL;
        int i=0;
        while(i != k)
        {
            ListNode *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            i++;
        }
        head->next=curr;
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr=head;
        int count=0;
        bool length=false;
        while(curr)
        {
            count++;
            curr=curr->next;
            if(count == k)
            {
                length=true;
                break;
            }
        }

        if(!length)
        {
            return head;
        }
        ListNode *rest=reverseKGroup(curr,k);
        ListNode *newhead=reverseK(head,k);
        head->next=rest;
        return newhead;
        
    }
};