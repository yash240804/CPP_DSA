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
    node *head = NULL;
    int arr[] = {1, 4, 6};
    for (int i = 0; i < 3; i++){
    // if linked list doesn't exist
    if (head == NULL){
        head = new node(arr[i]);
    }
    // if linked list exist
    else{
        node *temp;
        temp = new node(arr[i]);
        temp->next = head;
        head = temp;
    }
}
    node *temp = head;
    while (temp){
        cout<<temp->data<<"|"<<temp->next<<"-->"<<" ";
        temp = temp->next;
    }
    
    return 0;
}