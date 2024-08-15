#include<iostream>
using namespace std;
int main(){
    int n, i, j;
    cout<<"Enter Row: ";
    cin>>n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
             char name = 'a'+(j-1);
            cout<<name<<" ";
        }
        cout<<endl;
    }
    return 0;
}