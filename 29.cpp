#include<iostream>
using namespace std;
int main(){
    int i, j, n;
    cin>>n;
    for (i = 1; i <= n; i++){
        for (j = n; j >= n-i+1; j--){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}