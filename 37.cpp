#include<iostream>
using namespace std;
int main(){
    int n, i, j;
    cin>>n;
    for (i = 5; i >= 1; i--){
        for (j = 1; j <= n - i; j++){
            cout<<"  ";
        }
        for (j = 1; j <= 2*i - 1; j++){
            cout<<"* ";           
        }
        cout<<endl;
    }
    return 0;    
}