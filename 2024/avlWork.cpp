#include <iostream>

using namespace std;

class Node {
public:
    int Value;
    int SubTreeHeight = 1;
    Node *Left = nullptr, *Right = nullptr, *Parent = nullptr;

    Node(int v, Node *parent) : Value(v), Parent(parent) {}
};

class Tree {
public:
    Node *root = nullptr;

    void Insert(int x) {
        root = InsertRecursive(root, x, nullptr);
    }

    void PrintInOrder() {
        PrintInOrderRecursive(root);
        cout << endl;
    }

private:
    Node* InsertRecursive(Node* node, int value, Node* parent) {
        if (node == nullptr) {
            Node* newNode = new Node(value, parent);
            if (root == nullptr) {
                root = newNode;
            }
            return newNode;
        }

        if (value < node->Value) {
            node->Left = InsertRecursive(node->Left, value, node);
        } else if (value > node->Value) {
            node->Right = InsertRecursive(node->Right, value, node);
        }

        BalanceTree(node);
        UpdateSubTreeHeight(node);
        return node;
    }

    void PrintInOrderRecursive(Node* node) {
        if (node == nullptr) {
            return;
        }
        PrintInOrderRecursive(node->Left);
        cout << node->Value << " ";
        PrintInOrderRecursive(node->Right);
    }

    void UpdateSubTreeHeight(Node* node) {
        if (node == nullptr) {
            return;
        }
        int leftHeight = (node->Left) ? node->Left->SubTreeHeight : 0;
        int rightHeight = (node->Right) ? node->Right->SubTreeHeight : 0;
        node->SubTreeHeight = max(leftHeight, rightHeight) + 1;
    }

    void RotateLeft(Node* node) {
        Node* a = node;
        Node* b = node->Right;
        Node* t = b->Left;

        if (a->Parent) {
            if (a->Parent->Left == a) {
                a->Parent->Left = b;
            } else {
                a->Parent->Right = b;
            }
        }

        b->Left = a;
        b->Parent = a->Parent;
        a->Parent = b;

        a->Right = t;
        if (t != nullptr) {
            t->Parent = a;
        }

        if (a == root) {
            root = b;
        }

        UpdateSubTreeHeight(a);
    }

    void RotateRight(Node* node) {
        Node* a = node;
        Node* b = node->Left;
        Node* t = b->Right;

        if (a->Parent) {
            if (a->Parent->Left == a) {
                a->Parent->Left = b;
            } else {
                a->Parent->Right = b;
            }
        }

        b->Right = a;
        b->Parent = a->Parent;
        a->Parent = b;

        a->Left = t;
        if (t != nullptr) {
            t->Parent = a;
        }

        if (a == root) {
            root = b;
        }

        UpdateSubTreeHeight(a);
    }

    void BalanceTree(Node* node) {
        if (node == nullptr) {
            return;
        }

        int leftHeight = (node->Left) ? node->Left->SubTreeHeight : 0;
        int rightHeight = (node->Right) ? node->Right->SubTreeHeight : 0;
        int balance = leftHeight - rightHeight;

        if (balance > 1) {
            if (node->Left->Left) {
                RotateRight(node);
            } else {
                RotateLeft(node->Left);
                RotateRight(node);
            }
        } else if (balance < -1) {
            if (node->Right->Right) {
                RotateLeft(node);
            } else {
                RotateRight(node->Right);
                RotateLeft(node);
            }
        }
    }
};

int main() {
    Tree* t = new Tree();

    // Insert nodes into the tree
    t->Insert(5);
    t->Insert(3);
    t->Insert(7);
    t->Insert(2);
    t->Insert(4);

    // Print in-order traversal to check tree structure
    cout << "In-order traversal: ";
    t->PrintInOrder();

    delete t; // Clean up allocated memory

    return 0;
}
