#include <iostream>
using namespace std;

class Node {
public:
    int coeff;  
    int exp;    
    Node* next;

    Node(int c, int e) {
        coeff = c;
        exp = e;
        next = NULL;
    }
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() {
        head = NULL;
    }

    void insertTerm(int coeff, int exp) {
        Node* newNode = new Node(coeff, exp);

        if (head == NULL || head->exp < exp) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL && temp->next->exp >= exp)
                temp = temp->next;

            if (temp->exp == exp) {
                temp->coeff += coeff;
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    Polynomial add(Polynomial& poly) {
        Polynomial result;
        Node* temp1 = this->head;
        Node* temp2 = poly.head;

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->exp > temp2->exp) {
                result.insertTerm(temp1->coeff, temp1->exp);
                temp1 = temp1->next;
            } else if (temp1->exp < temp2->exp) {
                result.insertTerm(temp2->coeff, temp2->exp);
                temp2 = temp2->next;
            } else {
                int sumCoeff = temp1->coeff + temp2->coeff;
                if (sumCoeff != 0) {
                    result.insertTerm(sumCoeff, temp1->exp);
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }

        while (temp1 != NULL) {
            result.insertTerm(temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        }

        while (temp2 != NULL) {
            result.insertTerm(temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }

        return result;
    }

    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "0" << endl;
            return;
        }

        while (temp != NULL) {
            cout << temp->coeff << "x^" << temp->exp;
            if (temp->next != NULL) {
                cout << " + ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    void inputPolynomial() {
        int n, coeff, exp;
        cout << "Enter the number of terms in the polynomial: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Enter coefficient and exponent for term " << i + 1 << ": ";
            cin >> coeff >> exp;
            insertTerm(coeff, exp);
        }
    }
};

int main() {
    Polynomial poly1, poly2;

    cout << "Input Polynomial 1:\n";
    poly1.inputPolynomial();

    cout << "Input Polynomial 2:\n";
    poly2.inputPolynomial();

    cout << "Polynomial 1: ";
    poly1.display();

    cout << "Polynomial 2: ";
    poly2.display();

    Polynomial result = poly1.add(poly2);

    cout << "Resultant Polynomial: ";
    result.display();

    return 0;
}
