class Node{
    public:
    int key;
    int val;
    Node* next;
    Node *prev;
    Node(int key,int val)
    {
        this->key=key;
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
class LRUCache {
public:

    int capacity;
    unordered_map<int,Node*> map;
    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);

    void add(Node *node)
    {
        Node *prevtail=tail->prev;
        prevtail->next=node;
        node->prev=prevtail;
        node->next=tail;
        tail->prev=node;
    }

    void remove(Node *node)
    {
        Node *nextNode=node->next;
        Node *prevNode=node->prev;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        
        if(map.find(key) == map.end())
        {
            return -1;
        }
        Node *node=map[key];
        remove(node);
        add(node);
        return node->val;
    }
    
    void put(int key, int value) {
        
        if(map.find(key) == map.end())
        {
            Node *newNode=new Node(key,value);
            if(map.size() == this->capacity)
            {
                map.erase(head->next->key);
                remove(head->next);
                add(newNode);
                map[key]=newNode;
            }
            else
            {
                add(newNode);
                map[key]=newNode;
            }
        }
        else
        {
            Node *nodeToDelete=map[key];
            map.erase(nodeToDelete->key);
            remove(nodeToDelete);
            Node *newNode=new Node(key,value);
            add(newNode);
            map[key]=newNode;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */