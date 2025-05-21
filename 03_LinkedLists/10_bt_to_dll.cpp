#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;  // For tree: left child, For DLL: previous node
    Node* right; // For tree: right child, For DLL: next node
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTreeToDLL {
    Node* head = nullptr;
    Node* prev = nullptr;

    void inorderConvert(Node* root) {
        if (!root) return;

        // Recursively convert left subtree
        inorderConvert(root->left);

        // Process current node
        if (!prev) {
            head = root;  // First node is head of DLL
        } else {
            root->left = prev;
            prev->right = root;
        }
        prev = root;

        // Recursively convert right subtree
        inorderConvert(root->right);
    }

public:
    Node* convert(Node* root) {
        head = nullptr;
        prev = nullptr;
        inorderConvert(root);
        return head;
    }

    void printDLL(Node* head) {
        Node* curr = head;
        cout << "Doubly Linked List: ";
        while (curr) {
            cout << curr->data << " ";
            curr = curr->right;
        }
        cout << endl;
    }
};

int main() {
    // Construct binary tree
    Node* root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);

    BinaryTreeToDLL converter;
    Node* head = converter.convert(root);

    converter.printDLL(head);

    return 0;
}
