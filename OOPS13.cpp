#include<iostream>
using namespace std;
class A{
    public:
    void print(){
        cout<<"This is base class function"<<endl;
    }
};
class B:public A {
    public:
    void print(){
        cout<<"This is derived class function"<<endl;
    }
};

int main(){
    A obj1;
    B obj2;
    obj1.print();
    obj2.print();
}