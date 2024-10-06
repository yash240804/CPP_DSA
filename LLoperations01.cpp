#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class CircularLinkedList{
public:
    Node *head;

    CircularLinkedList(){
        head = NULL;
    }

    void createCLL(int n){
        if (n <= 0)
            return;

        head = new Node(1);
        Node *prev = head;

        for (int i = 2; i <= n; i++){
            Node *newNode = new Node(i);
            prev->next = newNode;
            prev = newNode;
        }

        prev->next = head;
    }

    int solveJosephus(int k)
    {
        if (head == NULL)
            return -1;

        Node *ptr = head;
        Node *prev = NULL;

        while (ptr->next != ptr)
        {
            for (int count = 1; count < k; count++){
                prev = ptr;
                ptr = ptr->next;
            }

            cout << "Person " << ptr->data << " is killed.\n";
            prev->next = ptr->next; 
            delete ptr;            
            ptr = prev->next;
        }

        head = ptr;
        return ptr->data;
    }
};

int main()
{
    int n, k;
    cout << "Enter the number of people: ";
    cin >> n;
    cout << "Enter the kill count (k): ";
    cin >> k;

    CircularLinkedList c;
    c.createCLL(n);

    int result = c.solveJosephus(k);
    cout << "The last person alive is at position: " << result << endl;

    return 0;
}
