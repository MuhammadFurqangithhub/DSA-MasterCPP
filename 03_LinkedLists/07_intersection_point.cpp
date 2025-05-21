#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to get length of a linked list
int getLength(Node* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find intersection point of two linked lists
Node* getIntersectionNode(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Move the pointer of longer list ahead by difference in lengths
    int diff = abs(len1 - len2);
    if (len1 > len2) {
        while (diff--) head1 = head1->next;
    } else {
        while (diff--) head2 = head2->next;
    }

    // Move both pointers and check for intersection
    while (head1 && head2) {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return nullptr;
}

int main() {
    // Creating first list: 1->2->3->4->5
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    // Creating second list: 9->10
    Node* head2 = new Node(9);
    head2->next = new Node(10);

    // Creating intersection at node with value 4
    head2->next->next = head1->next->next->next; // Points to node 4

    Node* intersection = getIntersectionNode(head1, head2);

    if (intersection)
        cout << "Intersection at node with value: " << intersection->data << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}
