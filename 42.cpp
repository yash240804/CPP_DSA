#include<iostream>
using namespace std;
int main(){
    int n, i, j;
    cin>>n;
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n - i; j++){
            cout<<"  ";
        }
        for (j = 1; j <= i; j++){
            char name = 'A' + j-1;
            cout<<name<<" ";
        }
        for (j = i - 1; j >= 1; j--){
            char name = 'A' + j-1;
            cout<<name<<" ";
        }
        cout<<endl;
    }
    return 0;   
}