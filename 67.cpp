#include<iostream>
using namespace std;
int findindex(int arr[], int size){
    for (int i = 0; i < size; i++){
        if(arr[i] == 5){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[100];
    int size;
    cin>>size;
    for (int i = 0; i < size; i++){
        cin>>arr[i];
    }
    cout<<findindex(arr, size);
    return 0;    
}