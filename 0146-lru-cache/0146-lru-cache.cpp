class LRUCache {

    // Doubly Linked List Node
    struct Node {
        int key, value;          // Stores key-value pair
        Node *prev, *next;       // Pointers to previous and next node

        // Constructor to initialize a node
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int cap;   // Maximum capacity of cache

    // HashMap: key -> corresponding node in DLL
    unordered_map<int, Node*> m;

    // Dummy head and tail nodes
    // They simplify insertion and deletion operations
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

public:

    // Constructor
    LRUCache(int capacity) : cap(capacity) {

        // Initially connect head and tail
        // head <-> tail
        head->next = tail;
        tail->prev = head;
    }

    // ---------------------------------------------------
    // Inserts a node immediately after head
    // This means the node becomes the Most Recently Used (MRU)
    // ---------------------------------------------------
    void addNode(Node* newNode) {

        Node *temp = head->next;     // Current first node

        newNode->next = temp;        // New node points to first node
        newNode->prev = head;        // Previous becomes head

        head->next = newNode;        // Head points to new node
        temp->prev = newNode;        // First node points back to new node
    }

    // ---------------------------------------------------
    // Removes a node from the doubly linked list
    // ---------------------------------------------------
    void deleteNode(Node* delNode) {

        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;

        // Bypass the node
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // ---------------------------------------------------
    // GET Operation
    // Returns value if key exists
    // Also moves that node to the front (MRU position)
    // ---------------------------------------------------
    int get(int key) {

        // Key found
        if (m.find(key) != m.end()) {

            Node* resNode = m[key];
            int res = resNode->value;

            // Remove old mapping
            m.erase(key);

            // Remove node from current position
            deleteNode(resNode);

            // Move it to front
            addNode(resNode);

            // Update hashmap with new position
            m[key] = head->next;

            return res;
        }

        // Key not found
        return -1;
    }

    // ---------------------------------------------------
    // PUT Operation
    // Inserts or updates a key-value pair
    // ---------------------------------------------------
    void put(int key, int value) {

        // If key already exists
        if (m.find(key) != m.end()) {

            Node* existingNode = m[key];

            // Remove old entry
            m.erase(key);

            // Remove node from DLL
            deleteNode(existingNode);
        }

        // Cache is full
        if (m.size() == cap) {

            // tail->prev is the Least Recently Used (LRU) node

            // Remove its key from hashmap
            m.erase(tail->prev->key);

            // Remove node from DLL
            deleteNode(tail->prev);
        }

        // Insert new node at front (MRU position)
        addNode(new Node(key, value));

        // Store pointer in hashmap
        m[key] = head->next;
    }
};