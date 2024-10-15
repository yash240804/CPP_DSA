#include <iostream>
using namespace std;

class Base {
public:
    virtual void display(){
        cout << "virtual Base Class function"<<endl;
    }
    void print(){
        cout << "Base print function"<<endl;
    }
};

class Child : public Base {
public:
    void display()
    {
        cout << "Child Display Function"<<endl;
    }

    void print()
    {
        cout << "Child print Function"<<endl;
    }
};

int main(){
    Base* base;
    Child child;
    base = &child;
    base->display();
    base->print();
    return 0;
}