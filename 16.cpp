#include<iostream>
using namespace std;
int main(){
    int n, fact = 1, i;
    cout<<"Enter number: ";
    cin>>n;
    for (i = 2; i <= n; i++)
    {
        fact = fact * i;
    }
    cout<<fact;
}