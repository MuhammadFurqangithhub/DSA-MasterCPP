#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Comparator for the min-heap
struct compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

// Merge K sorted linked lists
Node* mergeKLists(vector<Node*>& lists) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (auto node : lists) {
        if (node != nullptr)
            minHeap.push(node);
    }

    Node* dummy = new Node(0);
    Node* tail = dummy;

    while (!minHeap.empty()) {
        Node* curr = minHeap.top();
        minHeap.pop();

        tail->next = curr;
        tail = tail->next;

        if (curr->next)
            minHeap.push(curr->next);
    }

    return dummy->next;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node* createList(vector<int> vals) {
    Node* dummy = new Node(0);
    Node* temp = dummy;
    for (int v : vals) {
        temp->next = new Node(v);
        temp = temp->next;
    }
    return dummy->next;
}

int main() {
    vector<Node*> lists;
    lists.push_back(createList({1, 4, 7}));
    lists.push_back(createList({2, 5, 8}));
    lists.push_back(createList({3, 6, 9}));

    Node* mergedHead = mergeKLists(lists);

    cout << "Merged Linked List: ";
    printList(mergedHead);

    return 0;
}
