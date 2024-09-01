#include<iostream>
using namespace std;
class bank{
    int *bal;
    string name;
    public:
    bank(){

    }
    bank(string name){
        this->name = name;
        this->bal = new int;
        *bal = 10;
    }
    ~bank(){//destructor
        delete bal;
        cout<<"d called"<<endl;
    }
};
int main(){
    bank U1("yash");
    bank *U2 = new bank;
    delete U2;
}