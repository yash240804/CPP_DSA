#include<iostream>
using namespace std;
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    // or like this also arr[] = {1, 2, 3, 4, 5}; you dont need to mention size of array.
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i];
    }
    return 0;
}