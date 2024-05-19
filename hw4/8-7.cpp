#include <iostream>
#include <cmath>
using namespace std;

class PrimeNumber {
public:
    PrimeNumber();
    PrimeNumber(int number);
    int getPrimeNumber() const { return number; }
    void setPrimeNumber(int number);
    friend const PrimeNumber operator++(const PrimeNumber& primeNum);
    friend const PrimeNumber operator--(const PrimeNumber& primeNum);
    bool isPrime(int num) const;
private:
    int number;
};

PrimeNumber::PrimeNumber() : number(1) {}

PrimeNumber::PrimeNumber(int number) {
    this->number = number;
}

void PrimeNumber::setPrimeNumber(int number) {
    this->number = number;
}

bool PrimeNumber::isPrime(int num) const {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

const PrimeNumber operator++(const PrimeNumber& primeNum) {
    int nextPrimeNum = primeNum.number + 1;
    while (!primeNum.isPrime(nextPrimeNum)) {
        nextPrimeNum++;
    }
    return PrimeNumber(nextPrimeNum);
}

const PrimeNumber operator--(const PrimeNumber& primeNum) {
    if (primeNum.number <= 2) {
        cout << "\nThere is no prime number smaller than 2.\n";
        return PrimeNumber(2); // 保持原來的值
    }

    int nextPrimeNum = primeNum.number - 1;
    while (nextPrimeNum > 1 && !primeNum.isPrime(nextPrimeNum)) {
        nextPrimeNum--;
    }
    return PrimeNumber(nextPrimeNum);
}

int main(void) {
    int num, check;

    cout << "Enter a prime number: ";
    cin >> num;

    PrimeNumber primenum;
    while (!primenum.isPrime(num)) {
        cout << "\nThe number you entered is not a prime number, please enter again: ";
        cin >> num;
    }

    cout << "\nThe original prime number you entered: " << num << endl << endl;
    cout << "Enter 1 for finding the next largest prime number, 2 for the next smallest prime number: ";
    cin >> check;

    primenum.setPrimeNumber(num);

    if (check == 1) {
        PrimeNumber newprime = ++primenum;
        cout << "\nThe next largest prime number is " << newprime.getPrimeNumber() << endl << endl;
    }
    else {
        PrimeNumber newprime = --primenum;
        if (newprime.getPrimeNumber() != primenum.getPrimeNumber()) {
            cout << "\nThe next smallest prime number is " << newprime.getPrimeNumber() << endl << endl;
        }
    }

    system("pause");
    return 0;
}
