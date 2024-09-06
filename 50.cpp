#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int rem = 0, ans = 0, mul = 1, rem2 = 0, ans2 = 0, mul2 = 1;
    while (n){
        rem = n % 10;
        n = n / 10;
        ans = rem * mul + ans;
        mul = mul * 8;
    }
    while (ans){
        rem2 = ans % 2;
        ans = ans / 2;
        ans2 = rem2 * mul2 + ans2;
        mul2 = mul2 * 10;
    }
    cout<<ans2;
    return 0;
}