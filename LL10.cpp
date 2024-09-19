#include<iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
    node *prev;

    node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class CircularDoublyLL {
public:
    node *head = NULL;

    // Insertion at start
    void insertion_at_start(int value) {
        node *temp = new node(value);
        
        if (head == NULL) {
            // If the list is empty, point temp to itself (circular)
            head = temp;
            head->next = head;
            head->prev = head;
        } else {
            // Traverse to the last node (which will be the "tail" in a circular list)
            node *current = head;
            while (current->next != head) {
                current = current->next;
            }

            // Insert new node at the beginning
            temp->next = head;
            temp->prev = current;  // current is the last node now

            // Update head and last node's (current's) next and previous links
            head->prev = temp;
            current->next = temp;

            // Update the head to the new node
            head = temp;
        }
    }

    // Insertion at end
    void insertion_at_end(int value) {
        node *temp = new node(value);

        if (head == NULL) {
            // If the list is empty, make the new node point to itself (circular)
            head = temp;
            head->next = head;
            head->prev = head;
        } else {
            // Traverse to the last node (which is just before the head)
            node *current = head;
            while (current->next != head) {
                current = current->next;
            }

            // Insert the new node after the last node
            current->next = temp;
            temp->prev = current;

            // Complete the circular linking
            temp->next = head;
            head->prev = temp;
        }
    }

    // Deletion at start
    void deletion_at_start() {
        if (head == NULL) {
            cout << "The list is already empty.\n";
            return;
        }

        if (head->next == head) {
            // If there is only one node
            delete head;
            head = NULL;
        } else {
            // Traverse to the last node (which is the node just before the head)
            node *current = head;
            while (current->next != head) {
                current = current->next;
            }

            // Update the last node's next pointer to the new head (head->next)
            node *temp = head;
            current->next = head->next;
            head->next->prev = current;

            // Update the head pointer
            head = head->next;

            // Delete the original head node
            delete temp;
        }
    }

    // Deletion at end
    void deletion_at_end() {
        if (head == NULL) {
            cout << "The list is already empty.\n";
            return;
        }

        if (head->next == head) {
            // If there is only one node in the list
            delete head;
            head = NULL;
        } else {
            // Traverse to the second last node (just before the last node)
            node *current = head;
            while (current->next->next != head) {
                current = current->next;
            }

            // Current now points to the second last node
            node *lastNode = current->next;  // This is the last node

            // Update the second last node to point to head, removing the last node
            current->next = head;
            head->prev = current;

            // Delete the last node
            delete lastNode;
        }
    }

    // Display the circular doubly linked list
    void display_linked_list() {
        if (head == NULL) {
            cout << "The list is empty.\n";
            return;
        }

        node *temp = head;
        cout << "NULL <-- ";
        do {
            cout << temp->prev << " | " << temp->data << " | " << temp->next << " <--> ";
            temp = temp->next;
        } while (temp != head);
        cout << " NULL\n";
    }

    // Utility functions for input
    int insert_value() {
        int value;
        cout << "Enter the value you want to insert in the linked list: ";
        cin >> value;
        return value;
    }

    int insert_position() {
        int position;
        cout << "Enter the position where you want to insert/delete the node: ";
        cin >> position;
        return position;
    }
};

int main() {
    CircularDoublyLL A1;
    int choice;

    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Insert at the start\n";
        cout << "2. Insert at the end\n";
        cout << "3. Delete from the start\n";
        cout << "4. Delete from the end\n";
        cout << "5. Display the linked list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value = A1.insert_value();
                A1.insertion_at_start(value);
                break;
            }
            case 2: {
                int value = A1.insert_value();
                A1.insertion_at_end(value);
                break;
            }
            case 3:
                A1.deletion_at_start();
                break;
            case 4:
                A1.deletion_at_end();
                break;
            case 5:
                A1.display_linked_list();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
