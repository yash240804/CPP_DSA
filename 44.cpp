#include<iostream>
using namespace std;
int main(){
    int n, i, fact = 1;
    cin>>n;
    i = 1;
    while (i<=n){
        fact = fact * i;
        i++;
    }
    cout<<fact;
    
    return 0;   
}