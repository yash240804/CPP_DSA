#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int ans = 0, rem = 0, mul = 1;
    while (n){
        rem = n % 10;
        n /= 10;
        ans = rem * mul + ans;
        mul *= 2;
    }
    cout<<"Enterd number in decimal: "<<ans;
    return 0;
}