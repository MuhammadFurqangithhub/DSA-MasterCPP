#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    int capacity;
    unordered_map<int, Node*> cacheMap;
    Node *head, *tail;

    void removeNode(Node* node) {
        if (!node) return;

        if (node->prev) node->prev->next = node->next;
        else head = node->next;

        if (node->next) node->next->prev = node->prev;
        else tail = node->prev;
    }

    void addToFront(Node* node) {
        node->next = head;
        node->prev = nullptr;

        if (head) head->prev = node;
        head = node;

        if (!tail) tail = head;
    }

public:
    LRUCache(int cap) : capacity(cap), head(nullptr), tail(nullptr) {}

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;  // Not found
        }
        // Move accessed node to front
        Node* node = cacheMap[key];
        removeNode(node);
        addToFront(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // Update value and move to front
            Node* node = cacheMap[key];
            node->value = value;
            removeNode(node);
            addToFront(node);
        } else {
            // Insert new node
            Node* node = new Node(key, value);
            if ((int)cacheMap.size() == capacity) {
                // Remove LRU item
                cacheMap.erase(tail->key);
                removeNode(tail);
                delete tail;
            }
            addToFront(node);
            cacheMap[key] = node;
        }
    }

    void display() {
        Node* curr = head;
        while (curr) {
            cout << "(" << curr->key << ":" << curr->value << ") ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    LRUCache cache(3);

    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);
    cache.display();  // Expected: (3:30) (2:20) (1:10)

    cout << "Get 2: " << cache.get(2) << endl; // Access 2 -> moves to front
    cache.display();  // Expected: (2:20) (3:30) (1:10)

    cache.put(4, 40); // Evicts key 1
    cache.display();  // Expected: (4:40) (2:20) (3:30)

    cout << "Get 1: " << cache.get(1) << endl; // Should return -1 (not found)

    return 0;
}
