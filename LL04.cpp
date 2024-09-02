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
    int arr[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++){
        if (head == NULL){
            head = new node(arr[i]);
        }
        else{
            node *tail = head;
            while(tail->next != NULL){
            tail = tail->next;
            }
            tail->next = new node(arr[i]);
            // node *temp = new node(arr[i]);
            // tail->next = temp;
        }
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        cout<<temp->data<<"|"<<temp->next<<"->";
        temp = temp->next;
    }
    
    return 0;
}
