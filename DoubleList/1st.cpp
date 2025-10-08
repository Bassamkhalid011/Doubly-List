#include <iostream>
using namespace std;

// Doubly linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Doubly linked list class
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at end
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Reverse the doubly linked list
    void reverse() {
        Node* curr = head;
        Node* temp = nullptr;
        while (curr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp) {
            head = temp->prev;
        }
    }

    // Remove all nodes with even values
    void removeEven() {
        Node* curr = head;
        while (curr) {
            if (curr->data % 2 == 0) {
                Node* toDelete = curr;
                if (curr->prev) curr->prev->next = curr->next;
                else head = curr->next;
                if (curr->next) curr->next->prev = curr->prev;
                else tail = curr->prev;
                curr = curr->next;
                delete toDelete;
            } else {
                curr = curr->next;
            }
        }
    }

    // Print list forward
    void printForward() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // Print list backward
    void printBackward() {
        Node* curr = tail;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->prev;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.append(4);
    dll.append(5);

    cout << "Original list (forward): ";
    dll.printForward();

    cout << "Original list (backward): ";
    dll.printBackward();

    dll.reverse();
    cout << "Reversed list (forward): ";
    dll.printForward();

    dll.removeEven();
    cout << "List after removing even values: ";
    dll.printForward();

    return 0;
}