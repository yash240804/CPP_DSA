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
    int arr[] = {1, 4, 6, 10, 40};
    for (int i = 0; i < 5; i++){
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
    node *temp5 = head;
    while (temp5){
        cout<<temp5->data<<"|"<<temp5->next<<"-->"<<" ";
        temp5 = temp5->next;
    }
    cout<<endl<<endl;
    int x = 3;
    int value = 30;
    node *temp2 = head;
    x--;
    while (x--){
        temp2 = temp2->next;
    }
    node * temp3 = new node(value);
    temp3-> next = temp2->next;
    temp2->next = temp3;
    
    node *temp = head;
    while (temp){
        cout<<temp->data<<"|"<<temp->next<<"-->"<<" ";
        temp = temp->next;
    }
    
    return 0;
}