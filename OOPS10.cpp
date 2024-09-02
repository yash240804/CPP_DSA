#include<iostream>
using namespace std;

class customer{
    string name;
    int account_number, balance;
    static int total_customer;
    public:
    
    customer(string name, int account_number, int balance){
        this->name = name;
        this->account_number = account_number;
        this->balance = balance;
        total_customer++;
    }
    void display(){
        cout<<name<<" "<<account_number<<" "<<balance<<" "<<total_customer<<endl;
    }
};
    int customer::total_customer = 0;
    int main(){
        customer A1("Rohit", 1, 1000);
        customer A2("Yash", 2, 14034);
        A1.display();
        A2.display();
        return 0;
    }