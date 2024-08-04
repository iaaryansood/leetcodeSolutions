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
    ListNode* doubleIt(ListNode* head) {
        if(head == NULL)
        {
            return NULL;
        }
        else
        {
            vector<int> nums;
            while(head != NULL)
            {
                nums.push_back(head->val);
                head=head->next;
            }
            reverse(nums.begin(),nums.end());
            int carry=0;
            for(int i=0;i < nums.size();i++)
            {
                int double_digit=(nums[i] * 2 + carry);
                carry=double_digit/10;
                nums[i]=double_digit % 10;
            }
            if(carry > 0)
            {
                nums.push_back(carry);
            }
            ListNode *new_head=new ListNode(nums[nums.size() - 1]);
            ListNode *current=new_head;
            for(int i=nums.size()-2 ; i >= 0;--i)
            {
                current->next=new ListNode(nums[i]);
                current=current->next;
            }
            return new_head;
        }
    }
};