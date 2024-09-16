#include<iostream>
using namespace std;
int main(){
    int arr[5] = {1, 5, 2, 4, 3};
    int ans = INT32_MIN;
    int index;
    for (int i = 0; i < 5; i++){
        if (arr[i] > ans){
            ans = arr[i];
            index = i;
        }
    }
    ans = INT32_MIN;
    for (int i = 0; i < 5; i++)
    {
        if (i == index){
            continue;
        }
        else if(arr[i] > ans){
            ans = arr[i];
        }
    }
    cout<<ans;
    return 0;
}