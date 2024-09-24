#include<iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
};

int main () {
    node *head = nullptr, *newnode, *temp, *prevnode = nullptr, *nextnode = nullptr;
    int ch, n, i = 1, pos;
    
    cout << "1. Deletion at beginning" << endl;
    cout << "2. Deletion at end" << endl;
    cout << "3. Deletion after a given node" << endl;
    cout << "Enter the no. of nodes which you want to insert:\n";
    cin >> n;

    // Insert nodes
    while (i <= n) {
        newnode = new node();
        cout << "Enter data:\n";
        cin >> newnode->data;
        newnode->next = nullptr;

        if (head == nullptr)
            head = temp = newnode;
        else {
            temp->next = newnode;
            temp = newnode;
        }
        i++;
    }

    cout << "Enter your choice: ";
    cin >> ch;

    switch (ch) {
    case 1: // Deletion from beginning
        if (head == nullptr) {
            cout << "List is empty." << endl;
            break;
        }
        temp = head;
        head = head->next;
        free(temp);
        cout << "After deletion from beginning, list becomes:\n";
        temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
        break;

    case 2: // Deletion from end
        if (head == nullptr) {
            cout << "List is empty." << endl;
            break;
        }
        temp = head;
        while (temp->next != nullptr) {
            prevnode = temp;
            temp = temp->next;
        }
        if (temp == head) {
            head = nullptr;
        } else {
            prevnode->next = nullptr;
        }
        free(temp);
        cout << "After deletion from end, list becomes:\n";
        temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
        break;

    case 3: // Deletion after a given node
        if (head == nullptr) {
            cout << "List is empty." << endl;
            break;
        }
        cout << "Enter the index position after which to delete a node: ";
        cin >> pos;
        temp = head;
        for (i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Invalid position." << endl;
            break;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        free(nextnode);
        cout << "After deletion from position " << pos << ", list becomes:\n";
        temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
        break;

    default:
        cout << "Invalid choice: Enter a valid choice." << endl;
    }
    return 0;
}
