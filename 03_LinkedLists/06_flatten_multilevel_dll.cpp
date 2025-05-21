#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node* child;
    Node(int val) : data(val), prev(nullptr), next(nullptr), child(nullptr) {}
};

// Helper function to flatten the list starting from head
Node* flattenList(Node* head) {
    Node* curr = head;
    Node* tail = head;

    while (curr) {
        Node* next = curr->next;
        if (curr->child) {
            Node* child = flattenList(curr->child);

            curr->next = child;
            child->prev = curr;
            curr->child = nullptr;

            while (child->next) child = child->next;
            child->next = next;
            if (next) next->prev = child;
        }

        if (curr->next) curr = curr->next;
        else break;
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    // Creating nodes
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    // Creating child list for node 2
    Node* child = new Node(5);
    child->next = new Node(6);
    child->next->prev = child;

    head->next->child = child;

    cout << "Original list:\n";
    printList(head);

    head = flattenList(head);

    cout << "Flattened list:\n";
    printList(head);

    return 0;
}
