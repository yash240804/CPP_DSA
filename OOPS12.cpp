#include<iostream>
using namespace std;

class ComplexTime{
    public:
    void sum(){
        cout<<"The sum is "<<10 + 20<<endl;
    }
    void sum(int a){
        cout<<"The sum is "<<a + 10<<endl;
    }
    void sum(int a, int b){
        cout<<"The sum is "<<a + b<<endl;
    }
};

int main(){
    ComplexTime A1;
    A1.sum();
    A1.sum(90);
    A1.sum(15, 25);
}