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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next  == NULL)
        {
            return head;
        }
        // vector<int> temp;
        else
        {
            ListNode * curr=reverseList(head->next);
            ListNode * ans=curr;
            while(curr->next != NULL)
            {
                curr=curr->next;
            }
            curr->next=head;
            head->next=NULL;
            return ans;
        }

    }
};