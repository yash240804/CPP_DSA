#include<iostream>
using namespace std;
int main(){
    int *ptr1, *ptr2, sum;
    ptr1 = new int;
    ptr2 = new int;
    cout<<"Enter first no.: ";
    cin>>*ptr1;
    cout<<"Enter second no.: ";
    cin>>*ptr2;
    sum = *ptr1 + *ptr2;
    cout<<"The sum is: "<<sum;
    delete ptr1, ptr2;
    return 0;
}