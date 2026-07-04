class Node{
    public:
    int cnt;
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int value) {
        cnt = 1;
        this -> key = key;
        this -> val = value;
        next = prev = NULL;
    }
};

class List{
    public:
    int size;
    Node* head;
    Node* tail;

    List() {
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }

    void insertafterhead(Node* node){
        node -> next = head -> next;
        node -> prev = head;
        node -> next -> prev = node;
        head -> next = node;

        size++;
    }

    void deletenode(Node* node){
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;

        size--;
    }
};

class LFUCache {
    public:
    int capacity;
    int currsize;
    int minfreq;
    unordered_map<int, Node*> keynode;
    unordered_map<int, List*> freqlist;


    LFUCache(int capacity) {
        this -> capacity = capacity;
        minfreq = 0;
        currsize = 0;
    }

    void updatefreq(Node* node) {

        keynode.erase(node -> key);

        freqlist[node -> cnt] -> deletenode(node);

        if(node->cnt == minfreq && freqlist[node->cnt]->size == 0){
            minfreq++;
        }

        node -> cnt++;

         List* nextfreq;

        if(freqlist.count(node -> cnt)){
            nextfreq = freqlist[node -> cnt];
        }
        else {
            freqlist[node -> cnt] = new  List();
            nextfreq = freqlist[node -> cnt];
        }

        nextfreq -> insertafterhead(node);
        keynode[node -> key] = node;
    }
    
    int get(int key) {
        if(keynode.find(key) == keynode.end()){
            return -1;
        }

        Node* node = keynode[key];

        updatefreq(node);

        return node -> val;
    }


    
    void put(int key, int value) {
        if(capacity == 0) return;
        
        if(keynode.find(key) != keynode.end()){
            Node* node = keynode[key];
            node -> val = value;
            updatefreq(node);
        }
        else{
            if(currsize == capacity){
                 List* dellist = freqlist[minfreq];
                Node* delnode = dellist -> tail -> prev;
                keynode.erase(delnode -> key);
                dellist -> deletenode(delnode);
                delete delnode;
                currsize--;
            }

            currsize++;
            minfreq = 1;

             List* inslist;

            if(freqlist.count(minfreq)){
                inslist = freqlist[minfreq];
            }
            else{
                freqlist[minfreq] = new  List();
                inslist = freqlist[minfreq];
            }

            Node* newnode = new Node(key, value);

            inslist -> insertafterhead(newnode);
           keynode[key] = newnode;


        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */