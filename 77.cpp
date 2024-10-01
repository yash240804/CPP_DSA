#include<iostream>
using namespace std;
void selectionsort(char arr[], int size){
    int index;
    for (int i = 0; i < size - 1; i++){
        index = i;
        for (int j = i + 1; j < size; j++){
            if(arr[j]<arr[index]){
                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }
}
int main(){
    char arr[26];
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    selectionsort(arr, n);
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}