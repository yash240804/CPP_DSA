#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter leap year: ";
    cin>>n;
    if (n%400==0){
        cout<<"Leap Year";
    }
    else if (n%4==0 && n%100!=0){
        cout<<"Leap Year";
    }
    else{
        cout<<"Not a leap year";
    }
    
    return 0;
}