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

    ListNode *reverseList(ListNode *head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        else
        {
            ListNode *rest=reverseList(head->next);
            head->next->next=head;
            head->next=NULL;
            return rest;
        }
    }

    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return;
        }
        else
        {
            ListNode *slow=head;
            ListNode *fast=head;
            while(fast != NULL && fast->next != NULL)
            {
                slow=slow->next;
                fast=fast->next->next;
            }
            ListNode *newnode=reverseList(slow);
            slow->next=NULL;
            ListNode *curr=head;

            while(newnode->next)
            {
                ListNode *temp=curr->next;
                curr->next=newnode;
                curr=temp;

                ListNode *temp1=newnode->next;
                newnode->next=curr;
                newnode=temp1;
            }
            curr->next=newnode;
            newnode->next=NULL;

        }
    }
};