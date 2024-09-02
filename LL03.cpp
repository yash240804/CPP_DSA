#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int value){
        data = value;
        next = NULL;
    }
};
int main(){
    Node *Head = NULL;
    Node *Tail = NULL;
    int arr[] = {1, 5, 10, 9};
    for (int i = 0; i < 4; i++){
        if (Head == NULL){
            Head = new Node(arr[i]);
            Tail = Head;
        }
        else{
            Tail->next = new Node(arr[i]);
            Tail = Tail->next;
        }
    }
    Node *temp = Head;
    while (temp)
    {
        cout<<temp->data<<"|"<<temp->next<<"->";
        temp = temp->next;
    }
    return 0;
}