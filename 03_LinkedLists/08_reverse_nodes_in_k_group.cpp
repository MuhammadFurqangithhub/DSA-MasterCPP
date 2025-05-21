#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseKGroup(Node* head, int k) {
    if (!head) return nullptr;

    Node* curr = head;
    int count = 0;

    // Check if there are at least k nodes left
    while (curr && count < k) {
        curr = curr->next;
        count++;
    }

    if (count < k) return head; // Less than k nodes, no reversal

    // Reverse k nodes
    curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    count = 0;

    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Recurse for the next group
    if (next != nullptr)
        head->next = reverseKGroup(next, k);

    return prev; // prev is new head of reversed group
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr\n";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 3;

    cout << "Original list:\n";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Reversed list in groups of " << k << ":\n";
    printList(head);

    return 0;
}
