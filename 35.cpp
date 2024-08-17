#include<iostream>
using namespace std;
int main(){
    int i, j, n;
    cin>>n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++){
            cout<<"  ";
        }
        for (j = 1; j <= 2*i - 1; j++){
            cout<<"* ";
        }
        // for (j = 1; j <= n - i; j++){
        //     cout<<"  ";
        // }
        // Not imp kyuki next line pe jaane wala hai toh space ki zarurat nhi hai.
        cout<<endl;
    }
    return 0;
}