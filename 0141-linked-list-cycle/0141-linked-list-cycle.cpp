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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> sample_set;
        while(head != NULL)
        {
            if(sample_set.count(head))
            {
                return true;
            }
            else
            {
                sample_set.insert(head);
            }
            head=head->next;
        }
        return false;
    }
};