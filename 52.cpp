#include<iostream>
using namespace std;
void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
int main(){
    int n, m;
    cin>>n>>m;
    swap(n, m);
    cout<<n<<" "<<m<<endl;
    Swap(n, m);
    cout<<n<<" "<<m;
    return 0;
}