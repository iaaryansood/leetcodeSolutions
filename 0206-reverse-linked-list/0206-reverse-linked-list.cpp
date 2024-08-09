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
        vector<int> ans;
        while(head != NULL)
        {
            ans.push_back(head->val);
            head=head->next;
        }
        reverse(ans.begin(),ans.end());
        if(ans.empty())
        return NULL;
        ListNode * new_head=new ListNode(ans[0]);
        ListNode * curr=new_head;
        for(int i=1;i<ans.size();i++)
        {
            curr->next=new ListNode(ans[i]);
            curr=curr->next;
        }
        return new_head;
    }
};