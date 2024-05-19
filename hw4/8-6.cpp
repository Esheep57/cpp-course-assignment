#include <iostream>
#include <cmath>

using namespace std;

class MyInteger {
public:
    MyInteger(int integer);
    MyInteger() : integer(1) {};
    void setInteger(int integer);
    int getInteger() { return integer; }
    int operator [](int index);
private:
    int integer;
};

int main(void) {
    int num;
    int i = 1, len = 0;
    cout << "enter the number: ";
    cin >> num;
    MyInteger x(num);

    while (i <= num) {
        i = i * 10;
        len++;
    }

    for (int i = 0; i < len; i++) {
        cout << "x[" << i << "]: " << x[i] << endl;
    }

    cout << "x[" << len << "]: " << -1 << endl;

    system("pause");
    return 0;
}

MyInteger::MyInteger(int integer) {
    this->integer = integer;
}

void MyInteger::setInteger(int integer) {
    this->integer = integer;
}

int MyInteger::operator [](int index) {
    int num = integer;
    while (index-- > 0) {
        num /= 10;
    }
    return num % 10;
}