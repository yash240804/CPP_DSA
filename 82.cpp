#include<iostream>
using namespace std;
void insertionsort(int arr[], int size){
    for(int i = 1; i < size; i++){
        for (int j = i; j > 0; j--){
            if(arr[j] < arr[j - 1]){
                swap(arr[j], arr[j - 1]);
            }
            else{
                break;
            }
        }
    }
}
int main(){
    int arr[1000], n;
    cin>>n;
    for (int i = 0; i < n; i++)
    cin >> arr[i];
    insertionsort(arr, n);
    for (int i = 0; i < n; i++)
    cout << arr[i]<<" ";
    return 0;
}