#include<iostream>
using namespace std;
void bubblesort(int arr[], int size){
    int swapped;
    for (int i = size - 2; i >= 0; i--){
        swapped = 0;
        for (int j = 0; j <= i; j++){
            if (arr[j] < arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
        break;
    }
}
int main(){
    int arr[1000];
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    bubblesort(arr, n);
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}