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

class DoublyLL {
public:
    node *head = NULL;
    node *tail = NULL;

    void insertion_at_start(int value) {
        if (head == NULL) {
            head = new node(value);
        } else {
            node *temp = new node(value);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    void insertion_at_end(int value) {
        if (head == NULL) {
            head = new node(value);
        } else {
            tail = head;
            while (tail->next != NULL) {
                tail = tail->next;
            }
            node *temp = new node(value);
            tail->next = temp;
            temp->prev = tail;
        }
    }

    void insertion_at_position(int value, int position) {
        if (position == 1) {
            insertion_at_start(value);
            return;
        }

        node *temp2 = head;
        position--;
        while (position-- && temp2->next != NULL) {
            temp2 = temp2->next;
        }

        if (temp2->next == NULL) {
            insertion_at_end(value);
            return;
        }

        node *temp3 = new node(value);
        temp3->next = temp2->next;
        temp2->next = temp3;
        temp3->prev = temp2;
        temp2->next->prev = temp3;
    }

    void deletion_at_start() {
        if (head != NULL) {
            node *temp = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            delete temp;
        } else {
            cout << "The list is already empty.\n";
        }
    }

    void deletion_at_end() {
        if (head != NULL) {
            if (head->next == NULL) {
                node *temp = head;
                head = NULL;
                delete temp;
            } else {
                node *current = head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->prev->next = NULL;
                delete current;
            }
        } else {
            cout << "The list is already empty.\n";
        }
    }

    void deletion_at_position(int position) {
        if (head == NULL) {
            cout << "The list is already empty.\n";
            return;
        }

        if (position == 1) {
            deletion_at_start();
            return;
        }

        int x = position;
        node *current = head;
        x--;

        while (x-- && current->next != NULL) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Position out of bounds.\n";
            return;
        }

        current->next->prev = current->prev;
        current->prev->next = current->next;
        delete current;
    }

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

    void display_linked_list() {
        node *temp = head;
        cout<<"NULL";
        while (temp) {
            cout <<"<--"<<temp->prev <<"|"<< temp->data << "|" << temp->next << "--> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLL A1; 
    int choice;

    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Insert at the start\n";
        cout << "2. Insert at the end\n";
        cout << "3. Insert at a specific position\n";
        cout << "4. Delete from the start\n";
        cout << "5. Delete from the end\n";
        cout << "6. Delete from a specific position\n";
        cout << "7. Display the linked list\n";
        cout << "8. Exit\n";
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
            case 3: {
                int value = A1.insert_value();
                int position = A1.insert_position();
                A1.insertion_at_position(value, position);
                break;
            }
            case 4:
                A1.deletion_at_start();
                break;
            case 5:
                A1.deletion_at_end();
                break;
            case 6: {
                int position = A1.insert_position();
                A1.deletion_at_position(position);
                break;
            }
            case 7:
                A1.display_linked_list();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
