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
        node *temp = new node(value);
        if (head == NULL) {
            head = tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    void insertion_at_end(int value) {
        node *temp = new node(value);
        if (head == NULL) {
            head = tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
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

        node *current = head;
        position--;
        while (position-- && current->next != NULL) {
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
        cout << "NULL";
        while (temp) {
            cout << "<--" << temp->prev << "| " << temp->data << " |" << temp->next << "--> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    node* merge_lists(node *head1, node *head2) {
        node *temp = new node(0);
        node *tail = temp;

        while (head1 && head2) {
            if (head1->data <= head2->data) {
                tail->next = head1;
                head1->prev = tail;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2->prev = tail;
                head2 = head2->next;
            }
            tail = tail->next;
        }

        if (head1) {
            tail->next = head1;
            head1->prev = tail;
        } else {
            tail->next = head2;
            if (head2) {
                head2->prev = tail;
            }
        }

        node *mergedHead = temp->next;
        if (mergedHead) {
            mergedHead->prev = NULL;
        }
        delete temp;
        return mergedHead;
    }

    void create_list_from_array(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            insertion_at_end(arr[i]);
        }
    }

    node* sort_list(node* head) {
        if (head == NULL) {
            return NULL;
        }

        int swapped;
        node* current;
        node* last = NULL;

        do {
            swapped = 0;
            current = head;

            while (current->next != last) {
                if (current->data > current->next->data) {
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = 1;
                }
                current = current->next;
            }
            last = current;
        } while (swapped);

        return head;
    }
};

int main() {
    DoublyLL A1, A2;

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
        cout << "8. Merge two linked lists\n";
        cout << "9. Sort the linked list\n";
        cout << "10. Exit\n";
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
            case 8: {
                int n1, n2;
                node *SA1, *SA2;
                cout << "Enter the number of elements for the first linked list: ";
                cin >> n1;
                int arr1[n1];
                cout << "Enter elements of the first linked list:\n";
                for (int i = 0; i < n1; i++) {
                    cin >> arr1[i];
                }
                A1.create_list_from_array(arr1, n1);
                A1.display_linked_list();
                A1.head = A1.sort_list(A1.head);
                A1.display_linked_list();

                cout << "Enter the number of elements for the second linked list: ";
                cin >> n2;
                int arr2[n2];
                cout << "Enter elements of the second linked list:\n";
                for (int i = 0; i < n2; i++) {
                    cin >> arr2[i];
                }
                A2.create_list_from_array(arr2, n2);
                A2.display_linked_list();
                A2.head = A2.sort_list(A2.head);
                A2.display_linked_list();

                node* mergedHead = A1.merge_lists(A1.head, A2.head);
                A1.head = mergedHead;

                cout << "Merged Linked List:\n";
                A1.display_linked_list();
                break;
            }
            case 9: {
                A1.head = A1.sort_list(A1.head);
                cout << "Sorted Linked List:\n";
                A1.display_linked_list();
                break;
            }
            case 10:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 10);

    return 0;
}
