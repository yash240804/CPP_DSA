#include<iostream>
int swapt(int &a, int &b, int &c){
    int temp = c;
        c = b;
        b = a;
        a = temp;
        return a, b, c;
}
using namespace std;
int main(){
    int a, b, c;
    cin>>a>>b>>c;
    swapt(a, b, c);
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}