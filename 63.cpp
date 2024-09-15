#include<iostream>
using namespace std;
int main(){
    int arr[5] = {10, 20, 67, 98, 90};
    int ans = INT32_MAX;
    for (int i = 0; i < 5; i++){
        if (ans > arr[i]){
            ans = arr[i];
        }
    }
    cout<<ans<<" ";
    ans = INT32_MIN;
    for (int i = 0; i < 5; i++){
        if (ans < arr[i]){
            ans = arr[i];
        }
    }
    cout<<ans;

    return 0;
}