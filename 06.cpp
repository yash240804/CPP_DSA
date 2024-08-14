#include<iostream>
using namespace std;
int main(){
    int age;
    cout<<"Enter age: ";
    cin>>age;
    if(age >= 18)
    cout<<"Adult";
    else if (age >= 10 && age < 18)
    cout<<"Teenager";
    else
    cout<<"Child";
    
    return 0;
}