/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> map;
        Node *temp=head;
        while(temp)
        {
            Node *newnode=new Node(temp->val);
            map[temp]=newnode;
            temp=temp->next;
        }

        temp=head;
        Node *newhead=map[temp];
        while(temp)
        {
            Node *curr=map[temp];
            if(temp->next)
            curr->next=map[temp->next];
            else
            curr->next=NULL;

            if(temp->random)
            curr->random=map[temp->random];
            else
            curr->random=NULL;

            temp=temp->next;
        }
        
        return newhead;
    }
};