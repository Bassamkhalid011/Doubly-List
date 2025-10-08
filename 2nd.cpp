#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = *head_ref;
    if (*head_ref != nullptr)
        (*head_ref)->prev = new_node;
    *head_ref = new_node;
}

void reverse(Node** head_ref) {
    Node* temp = nullptr;
    Node* current = *head_ref;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr)
        *head_ref = temp->prev;
}

void printList(Node* node) {
    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    std::cout << "Original list: ";
    printList(head);

    reverse(&head);

    std::cout << "Reversed list: ";
    printList(head);

    return 0;
}