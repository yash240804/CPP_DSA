#include<iostream>
using namespace std;

class node{
public:
    string pizzatype;
    int ordercount;
    node* next;

    node(string p, int o) {
        pizzatype = p;
        ordercount = o;
        next = NULL;
    }
};

class PizzaParlor{
public:
    node* head;  
    int maxOrders;
    int currentOrders;

    PizzaParlor(int m) {
        head = NULL;
        maxOrders = m;
        currentOrders = 0;
    }

    void placeOrder(string pizzatype, int order) {
        if (currentOrders >= maxOrders) {
            cout<<"Cannot place more orders parlor is closed.\n";
            return;
        }

        node* newNode = new node(pizzatype, order);
        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        currentOrders++;
        cout<<"Order placed: " << pizzatype << " (Order Count: " << order << ")\n";
    }

    void serveOrder() {
        if(head == NULL){
            cout<<"No pending orders to serve.\n";
            return;
        }

        node* temp = head;
        if(head->next == head){
            head = NULL;
        } 
        else{
            node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;
        }
        cout<<"Served order: " << temp->pizzatype << " Order Count: " << temp->ordercount << "\n";
        delete temp;
    }

    void pendingOrders(){
        if (head == NULL) {
            cout<<"No pending orders.\n";
            return;
        }

        node* temp = head;
        cout<<"Pending Orders: \n";
        do{
            cout<<"Pizza: " << temp->pizzatype << " | Count: " << temp->ordercount << " --> ";
            temp = temp->next;
        }while(temp != head);
        cout<<"HEAD\n";
    }

    void cancelOrder(){
        cout<<"You can't cancel the order once placed.\n";
    }
};

int main() {
    int choice;
    string pizzatype;
    int order, maxOrders;
    cout << "Enter the maximum number of orders: ";
    cin >> maxOrders;
    PizzaParlor parlor(maxOrders);
    do{
        cout << "\n--- Pizza Parlor ---\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. View Pending Orders\n";
        cout << "4. Cancel Order\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
        case 1:
            cout << "Enter Pizza Type: ";
            cin >> pizzatype;
            cout << "Enter Order Count: ";
            cin >> order;
            parlor.placeOrder(pizzatype, order);
            break;
        case 2:
            parlor.serveOrder();
            break;
        case 3:
            parlor.pendingOrders();
            break;
        case 4:
            parlor.cancelOrder();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }while(choice != 5);
    return 0;
}