#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int ans = 0, rem = 0, mul = 1;
    while (n){
        rem = n % 2;
        n /= 2;
        ans = rem * mul + ans;
        mul *= 10;
    }
    cout<<"Enterd number in decimal: "<<ans;
    return 0;
}