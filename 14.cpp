#include<iostream>
using namespace std;
int main(){
    int n, power, i, ans = 1;
    cout<<"Enter number: ";
    cin>>n;
    cout<<"Enter power: ";
    cin>>power;
    for (i = 1; i < power; i++)
    {
        ans = ans * n;
    }
    cout<<ans;
    return 0;
}