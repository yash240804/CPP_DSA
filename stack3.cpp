#include <iostream>
using namespace std;

class Stack
{
public:
    char *arr;
    int size;
    int top;

    Stack(int size)
    {
        arr = new char[size];
        this->size = size;
        this->top = -1;
    }

    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        else
        {
            top--;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    int getSize()
    {
        return top + 1;
    }

    void print()
    {

        cout << "Stack: ";
        for (int i = 0; i < getSize(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl
             << endl;
    }
};

int main()
{

    // creation
    Stack st(3);

    //push
    //st.push('a');
    st.push('+');
    st.print();

    st.push('b');
    st.print();

    cout << endl
         << "Top elemet: " << st.getTop() << endl;
    cout << endl
         << "Size of stack: " << st.getSize() << endl;

    st.pop();
     st.pop();

    if (st.isEmpty())
    {
        cout << "Empty" << endl;
    }
    else
    {
        cout << "Not empty" << endl;
    }

       st.push(30);
       st.print();

    return 0;
}