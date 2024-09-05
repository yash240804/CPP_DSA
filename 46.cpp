#include<iostream>
using namespace std;
int main(){
    int n, i, j;
    cin>>n;
    for (int i = 1; i <= n; i++){
        for (int j = i - 1; j >= 1; j--)
        {
            cout<<" ";
        }
        for (int j = i; j <= n; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}