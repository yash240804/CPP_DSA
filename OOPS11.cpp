#include<iostream>
using namespace std;

class B;
class A{
    private:
        int privateA;
    public:
    A(){
        privateA=1000;
    }
    friend int ff(A objA, B objB);
};
class B{
    private:
        int privateB;
    public:
    B(){
        privateB=2000;
    }
    friend int ff(A objA, B objB);
};

int ff(A objA, B objB){
    cout<<"PrivateA: "<<objA.privateA<<endl<<"PrivateB: "<<objB.privateB<<endl;
}

int main(){
    A objA;
    B objB;
    ff(objA, objB);
    return 0;
}
