#include<iostream>
using namespace std;
class student{
    string name, grades;
    int age, roll_number;
    // once you have created a constructor complier will not create constructor automatically
    public:
    student(){// construtor jo dikhta nhi par hota hai as soon as object created
        cout<<"Construtor called\n";// Default constructor
    }
    student(string name, int age, int roll_number, string grades){
        this->name = name;
        this->age = age;
        this->roll_number = roll_number;//this pointer which stores address of object
        this->grades = grades;
    }
    // constructor overloading(nothing but multiple constructor with different no. parameter)
    student(string n, int a){
        name = n;
        age = a;
    }
    inline student(int a, string n) : age(age), name(n){}//inline constructor
    void display(){
        cout<<name<<" "<<age<<" "<<roll_number<<" "<<grades<<" "<<endl;
    }
};
int main(){
    student obj1;
    student obj2("Yash", 20, 21, "A+");//compiler can identify which constuctor belong to which object
    student obj3("om", 26);
    student obj4("Rohit", 22);
    obj2.display();
    obj3.display();
    obj4.display();
    return 0;
}