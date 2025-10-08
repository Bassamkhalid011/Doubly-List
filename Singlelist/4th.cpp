#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SingleList {
private:
    Node* head;
public:
    SingleList() : head(nullptr) {}

    ~SingleList() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void insertFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertBack(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    void deleteValue(int val) {
        Node* curr = head;
        Node* prev = nullptr;
        while (curr) {
            if (curr->data == val) {
                if (prev) {
                    prev->next = curr->next;
                } else {
                    head = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void printList() const {
        Node* curr = head;
        while (curr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    SingleList list;
    list.insertFront(3);
    list.insertFront(2);
    list.insertBack(4);
    list.printList(); // Output: 2 3 4
    list.deleteValue(3);
    list.printList(); // Output: 2 4
    return 0;
}