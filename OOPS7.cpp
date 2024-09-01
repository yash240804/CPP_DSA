#include<iostream>
using namespace std;

class student{
    public: 
    int roll_number, age;
    string name, grade;

    student(string name, int age){
        this->name = name;
        this->age = age;
        roll_number = 21;
        grade = "O";
    }
    student(){

    }
    // student(student &b){//default copy constructor
    //     age = b.age;
    //     roll_number= b.roll_number;
    //     grade = b.grade;
    //     name = b.name;
    // }
    void display(){
        cout<<name<<" "<<age<<" "<<roll_number<<" "<<grade<<" "<<endl;
    }
};

int main(){
    student A1("Yash", 20);
    student A2(A1);//either you make other wise complier toh hai hi
    A1.display();
    A2.display();
    student A3;
    A3 = A2;//another way to copy
    A3.display();
}
