#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to detect and remove a loop in the list
void detectAndRemoveLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Detect loop using Floyd's cycle detection
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cout << "Loop detected." << endl;
            break;
        }
    }

    // If loop does not exist
    if (slow != fast)
        return;

    // Move slow to head, keep fast at meeting point
    slow = head;
    if (slow == fast) {
        // Loop starts at head
        while (fast->next != slow)
            fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Remove loop
    fast->next = nullptr;
    cout << "Loop removed." << endl;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating a loop for testing
    head->next->next->next->next->next = head->next;

    detectAndRemoveLoop(head);
    cout << "Linked List after loop removal: ";
    printList(head);

    return 0;
}
