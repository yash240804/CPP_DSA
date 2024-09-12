#include<iostream>
using namespace std;
char convert(char &n){
    n = n - 'a' + 'A';
    return n;
}
int main(){
    char n;
    cin>>n;
    cout<<convert(n);
    return 0;
}