#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertFront(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void insertMiddle(int data, int position) {
        if (position == 0) {
            insertFront(data);
            return;
        }
        Node* newNode = new Node();
        newNode->data = data;
        Node* temp = head;
        for (int i = 0; i < position - 1; ++i) {
            if (temp == nullptr) {
                cout << "Position out of range" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position out of range" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertBack(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteFront() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteMiddle(int position) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (position == 0) {
            deleteFront();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1; ++i) {
            if (temp == nullptr || temp->next == nullptr) {
                cout << "Position out of range" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of range" << endl;
            return;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    void deleteBack() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    LinkedList ll;

    int choice, data, position;

    while(true) {
        
       cout << "\nMenu:\n";
       cout << "1. Insert Front\n";
       cout << "2. Insert Middle\n";
       cout << "3. Insert Back\n";
       cout << "4. Delete Front\n";
       cout << "5. Delete Middle\n";
       cout << "6. Delete Back\n";
       cout << "7. Display\n";
       cout << "8. Exit\n";
       cout << "Enter your choice: ";
       cin >> choice;

       switch(choice) {
           case 1:
               cout << "Enter data to insert at front: ";
               cin >> data;
               ll.insertFront(data);
               break;

           case 2:
               cout << "Enter data to insert in middle: ";
               cin >> data;
               cout << "Enter position: ";
               cin >> position;
               ll.insertMiddle(data, position);
               break;

           case 3:
               cout << "Enter data to insert at back: ";
               cin >> data;
               ll.insertBack(data);
               break;

           case 4:
               ll.deleteFront();
               break;

           case 5:
               cout << "Enter position to delete: ";
               cin >> position;
               ll.deleteMiddle(position);
               break;

           case 6:
               ll.deleteBack();
               break;

           case 7:
               ll.display();
               break;

           case 8:
               exit(0);

           default:
               cout << "Invalid choice, please try again." << endl;

       }
   }

   return 0;

}