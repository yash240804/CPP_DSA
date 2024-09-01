#include<iostream>
using namespace std;

class student{
    public: // by defult these data members are private to access them outside the class we have to make them public if they are private we can't access them outside the class
    int roll_number, age;
    string name, grade;
};

int main(){
    student obj1;//object created
    obj1.name = "Yash";// to access particular datamember use '.' operator
    obj1.grade = "A+";
    obj1.age = 20;
    obj1.roll_number = 21;
    cout<<obj1.name;
    return 0;
}