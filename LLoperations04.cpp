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

    Polynomial multiply(Polynomial& poly) {
        Polynomial result;
        for (Node* temp1 = this->head; temp1 != NULL; temp1 = temp1->next) {
            for (Node* temp2 = poly.head; temp2 != NULL; temp2 = temp2->next) {
                result.insertTerm(temp1->coeff * temp2->coeff, temp1->exp + temp2->exp);
            }
        }
        return result;
    }

    void inputPolynomial() {
        int n, coeff, exp;
        cout << "Enter the number of terms: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Enter coefficient and exponent for term " << i + 1 << ": ";
            cin >> coeff >> exp;
            insertTerm(coeff, exp);
        }
    }

    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "0" << endl;
            return;
        }

        while (temp != NULL) {
            cout << temp->coeff << "x^" << temp->exp;
            if (temp->next != NULL)
                cout << " + ";
            temp = temp->next;
        }
        cout << endl;
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

    Polynomial result = poly1.multiply(poly2);

    cout << "Resultant Polynomial after multiplication: ";
    result.display();

    return 0;
}
