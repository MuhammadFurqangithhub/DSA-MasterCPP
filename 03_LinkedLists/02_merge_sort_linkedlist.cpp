#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Merge two sorted lists
Node* merge(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;

    while (l1 && l2) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// Find the middle of the list
Node* getMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Merge Sort
Node* mergeSort(Node* head) {
    if (!head || !head->next)
        return head;

    Node* mid = getMid(head);
    Node* right = mid->next;
    mid->next = nullptr;

    Node* leftSorted = mergeSort(head);
    Node* rightSorted = mergeSort(right);

    return merge(leftSorted, rightSorted);
}

// Helper to print the list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(3);
    head->next->next = new Node(8);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(7);

    cout << "Original List:\n";
    printList(head);

    head = mergeSort(head);

    cout << "\nSorted List:\n";
    printList(head);

    return 0;
}
