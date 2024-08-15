#include<iostream>
using namespace std;
int main(){
    int n, i;
    cout<<"Enter number: ";
    cin>>n;
    if (n<2){
        cout<<"Niether prime nor composite";
        return 0;
    }
    else{
        for (i = 2; i < n; i++){
            if (n%i==0)
            {
                cout<<"Not prime";
                return 0;
            }    
        }
        cout<<"Prime";
    }
    return 0;
}