#include<iostream>
using namespace std;
void selectionsort1(int arr[], int size){
    int index;
    for (int i = size - 1; i > 0; i--){
        index = i;
        for (int j = i - 1; j >= 0; j--){
            if(arr[index] < arr[j]){
                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }
}
int main(){
    int arr[1000];
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    selectionsort1(arr, n);
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}