#include<iostream>
using namespace std;
int main(){
    int arr[18], sum = 0;
    for (int i = 0; i < 18; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    int avg = sum / 18;
    cout<<avg;
}