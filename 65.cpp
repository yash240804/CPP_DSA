#include<iostream>
using namespace std;
int main(){
    int arr[20], sum = 0;
    for (int  i = 0; i < 20; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    cout<<"The sum is: "<<sum;
    return 0;
}