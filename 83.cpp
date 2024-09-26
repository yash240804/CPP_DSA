#include<iostream>
using namespace std;
void binarysearch(int arr[], int n, int target){
    int start = 0, mid;
    int end = n - 1;
    while (start <= end){
        mid = start + (end - start) / 2;
        if(arr[mid] == target){
            cout<<endl;
            cout<<"Target found at index "<<mid;
            return;
        }
        else if(arr[mid] < target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    cout<<endl;
    cout<<"Target Not Found!";
}
int main(){
    int arr[100];
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter element in array: ";
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the element you want to find in array: ";
    cin>>target;
    binarysearch(arr, n, target);
    return 0;
}