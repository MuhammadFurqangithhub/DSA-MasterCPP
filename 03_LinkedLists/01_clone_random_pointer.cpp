#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int val) {
        data = val;
        next = random = nullptr;
    }
};

// Function to clone the list
Node* cloneList(Node* head) {
    if (!head) return nullptr;

    // Step 1: Insert clone nodes
    Node* curr = head;
    while (curr) {
        Node* clone = new Node(curr->data);
        clone->next = curr->next;
        curr->next = clone;
        curr = clone->next;
    }

    // Step 2: Update random pointers
    curr = head;
    while (curr) {
        if (curr->random)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    // Step 3: Detach clone list
    curr = head;
    Node* cloneHead = head->next;
    Node* clone = cloneHead;

    while (curr) {
        curr->next = curr->next->next;
        if (clone->next)
            clone->next = clone->next->next;
        curr = curr->next;
        clone = clone->next;
    }

    return cloneHead;
}

// Helper to print list
void printList(Node* head) {
    while (head) {
        cout << "Data = " << head->data;
        if (head->random)
            cout << ", Random = " << head->random->data << endl;
        else
            cout << ", Random = NULL" << endl;
        head = head->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Setting up random pointers
    head->random = head->next->next;       // 1 → 3
    head->next->random = head;             // 2 → 1
    head->next->next->random = head->next; // 3 → 2
    head->next->next->next->random = head; // 4 → 1

    cout << "Original List:\n";
    printList(head);

    Node* cloned = cloneList(head);
    cout << "\nCloned List:\n";
    printList(cloned);

    return 0;
}
