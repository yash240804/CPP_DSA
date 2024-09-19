#include<iostream>
using namespace std;
class node{
    public:
    string pizzatype;
    int ordercount;
    node *next;

    node(string p, int o){
        pizzatype = p;
        ordercount = o;
        next = NULL;
    }
    
    node *head = NULL;

    void placeorder(int order, string pizaatype){
        if(head == NULL){
            head = new node(pizzatype, order);
            head -> next = head;
        }
        else{
            node *temp = new node(pizzatype, order);
            temp = head;
            while(temp->next != NULL){
                temp = temp -> next;
            }
            temp -> next = head;
        }
    }

    void serveorder(){
        if (head != NULL) {
            node *temp = head;
            head = head->next;
            delete temp;
        } 
        else{
            cout << "The list is already empty.\n";
        }
        
    }
};