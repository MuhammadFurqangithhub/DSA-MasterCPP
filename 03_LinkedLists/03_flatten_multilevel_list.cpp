#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* child;

    Node(int val) {
        data = val;
        next = prev = child = nullptr;
    }
};

// Helper function to flatten the list
Node* flatten(Node* head) {
    if (!head) return nullptr;

    Node* curr = head;

    while (curr) {
        if (curr->child) {
            Node* nextNode = curr->next;
            Node* childHead = flatten(curr->child);

            curr->next = childHead;
            childHead->prev = curr;
            curr->child = nullptr;

            Node* tail = childHead;
            while (tail->next) tail = tail->next;

            tail->next = nextNode;
            if (nextNode) nextNode->prev = tail;
        }
        curr = curr->next;
    }

    return head;
}

// Print the doubly linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Example usage
int main() {
    // Level 1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    // Level 2
    Node* child1 = new Node(7);
    child1->next = new Node(8);
    child1->next->prev = child1;

    // Level 3
    child1->next->child = new Node(11);
    child1->next->child->next = new Node(12);
    child1->next->child->next->prev = child1->next->child;

    head->next->child = child1;

    cout << "Original multilevel list:\n";
    printList(head);

    head = flatten(head);

    cout << "\nFlattened list:\n";
    printList(head);

    return 0;
}
