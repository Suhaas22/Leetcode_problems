class Node{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mpp;


public:
    void insertafterhead(Node* node) {
        node -> next = head -> next;
        node -> next -> prev = node;
        head -> next = node;
        node -> prev = head;
    }
    void deletenode(Node* node){
        node -> next -> prev = node -> prev;
        node -> prev -> next = node -> next;
    }
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            Node* temp = mpp[key];
            deletenode(temp);
            insertafterhead(temp);
            return temp->val;
        }
        else{
            return -1;
        }

        
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->val = value;
            deletenode(node);
            insertafterhead(node);
        }
        else{
            if(mpp.size() == capacity){
                Node* lru = tail->prev;

                mpp.erase(lru->key);
                deletenode(lru);
                delete lru;
                
                Node* node = new Node(key, value);
                insertafterhead(node);
                mpp[key] = node;
            }
            else{
                Node* node = new Node(key, value);
                insertafterhead(node);
                mpp[key] = node;
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */