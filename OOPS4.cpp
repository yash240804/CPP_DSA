#include<iostream>
using namespace std;
//static vs dynamic memory allocation
class student{
    public:
    string name, grade;
    int roll_number, age;
};
int main(){//dynamic memory allocation and stack and heap memory concept
    student *s = new student;
    (*s).name = "Rohit";
    s->age = 20;
    cout<<s->age<<endl;
    cout<<(*s).name;
}