#include<iostream>
using namespace std;
int main(){
    int a = 0, b = 1, fib = 0, i, n;
    cout<<"Enter Number: ";
    cin>>n;
    for (i = 2; i < n; i++){
        fib = a + b;
        a = b;
        b = fib;
    }
    cout<<fib;
    return 0;
}