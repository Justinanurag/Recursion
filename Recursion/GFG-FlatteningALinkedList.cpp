#include<iostream>
using namespace std;

// Struct Node
struct Node {
    int data;
    Node* next;
    Node* bottom;
    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

// Merge two bottom-linked lists
Node* mergeTwoLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    Node* result;
    if (l1->data < l2->data) {
        result = l1;
        result->bottom = mergeTwoLists(l1->bottom, l2);
    } else {
        result = l2;
        result->bottom = mergeTwoLists(l1, l2->bottom);
    }

    result->next = NULL;
    return result;
}

// Flatten the 2D linked list
Node* flatten(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* head2 = flatten(head->next);
    return mergeTwoLists(head, head2);
}

// Print the flattened list using bottom pointers
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

int main() {
    // Create sample 2D linked list:
    // 5 -> 10 -> 19 -> 28
    // |     |     |     |
    // 7     20    22    35
    // |           |     |
    // 8           50    40
    // |                 |
    // 30                45

    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    // Flatten and print
    Node* flat = flatten(head);
    printList(flat);

    return 0;
}
