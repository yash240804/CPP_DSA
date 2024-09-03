#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int value){
        data = value;
        next = NULL;
    }
};

int main(){
    node *head;
    head = NULL;
    int arr[] = {1, 4, 3, 10, 7};
    for (int i = 0; i < 5; i++)
    {
        if (head == NULL){
            head = new node(arr[i]);
        }
        else{
            node *temp = new node(arr[i]);
            temp->next = head;
            head = temp;
        }
        
    }
    if (head != NULL){
        if (head->next == NULL){
            node *temp;
            temp = head;
            head = NULL;
            delete temp;
        }
        else{
            node *current = head;
            node *previous = NULL;
            while (current->next != NULL){
                previous = current;
                current = current->next;
            }
            delete current;
            previous->next = NULL;
        }
    }
    
     node *temp = head;
    while (temp){
        cout<<temp->data<<"|"<<temp->next<<"-->"<<" ";
        temp = temp->next;
    }
    
    return 0;
}