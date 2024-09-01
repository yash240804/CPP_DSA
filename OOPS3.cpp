#include<iostream>
using namespace std;
class student{
    string name, grade;
    int roll_number, age;
    public:
    void setname(){//setter function
        cin>>name;
    }
    void setage(int a){//another way
        age = a;
    }
    void setgrade(){
        cin>>grade;
    }
    void setroll_number(){
        cin>>roll_number;
    }
     void getname(){
        cout<<name;
    }
    void getage(){
        cout<<age;
    }
    void getgrade(int pin){//you can also add functionality
        if(pin == 1234){
        cout<<grade;
        }
        else{
            cout<<"enter correct pin";
            return;
        }
    }
    void getroll_number(){
        cout<<roll_number;
    }
};

int main(){
    student s1;
    s1.setage(20);
    s1.getage();
    s1.setgrade();
    s1.getgrade(123);
    return 0;
}